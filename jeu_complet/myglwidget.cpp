#include "myglwidget.hh"

Joueur player(0,0);

Ia iatest[NBIAMAX];

Food food[FOOD::COUNT];

GLfloat x_cam=player.getPosition().getX();
GLfloat y_cam=7.0f;
GLfloat z_cam=player.getPosition().getZ()+5;

GLint frame=0,temps,timebase=0;

int LightPos[4] = {0,20,0,1};

float Light1Dif[4] = {1.0f,0.2f,0.0f,1.0f};

float Spotlight1direc[3] = {0.0f, 0.0f, -1.0f};
int MatSpec [4] = {1,1,1,1};

MyGLWidget::MyGLWidget(QWidget* parent):
    QOpenGLWidget(parent)
{
    QSurfaceFormat format   ;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(3,2);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    this->setFocusPolicy(Qt::StrongFocus); //demande a qt de prende en compte l'action de la souris et du clavier pour cette fenetre en particulier
}

void MyGLWidget::LoadGLTextures(){
    QImage img;

       if(!img.load("./Ressources/sol.png")){

           qDebug()<<"Image loading failed";
       }

       QImage t =  QGLWidget::convertToGLFormat(img);

       glGenTextures(1, &tex[0]);

       glBindTexture(GL_TEXTURE_2D, tex[0]);

       glTexImage2D( GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits() );

       // définit les options de la texture actuellement liée
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void MyGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
    LoadGLTextures();

    glEnable(GL_LIGHTING);
    if(this->_mode_nuit=="Nuit"){
        glEnable(GL_LIGHT1); //Lumiere Mode Nuit
    }else {
        glEnable(GL_LIGHT0);
    }
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    this->setMouseTracking(true);
}


void MyGLWidget::paintGL()
{
    glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,MatSpec);
    glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,100);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // test pour les FPS
    frame++;
    temps=glutGet(GLUT_ELAPSED_TIME);
    if (temps - timebase > 1000) {
        printf("frames =%2.0d, ",frame/10);
        printf("temps = %4.0d, ",(temps-timebase)/10);
        printf("FPS = %4.0d",frame*1000/(temps-timebase));
        printf("\n");
        timebase = temps;
        frame = 0;
    }

    // caméra sur le player
    gluLookAt(static_cast<double>(x_cam),static_cast<double>(y_cam),static_cast<double>(z_cam),static_cast<double>(player.getPosition().getX()),0.0,static_cast<double>(player.getPosition().getZ()),0.0,1.0,0.0);

    float Light1Pos[4] = {player.getPosition().getX(),3,player.getPosition().getZ(),1};
    glLightiv(GL_LIGHT0,GL_POSITION,LightPos);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,Light1Dif);
    glLighti(GL_LIGHT1,GL_SPOT_CUTOFF,60);
    float Light1Dir[3] = {0,-1,0};
    glLightfv(GL_LIGHT1,GL_POSITION,Light1Pos);
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,Light1Dir);


    glBindTexture(GL_TEXTURE_2D, tex[0]);
    terrain t(TERRAIN::LONGUEUR,TERRAIN::LARGEUR); // création du terrain

    // dessine le joueur
    player.draw();

    for(int i=0; i<this->nbia;++i){

        iatest[i].draw();
    }

    // boucle pour toutes les foods
    for(unsigned int i=0; i<FOOD::COUNT;++i){
        for(int j=0; j<this->nbia;++j){ // boucle pour toutes les ia
            if(iatest[j].collision(food[i])){ // vérifie s'il y a collision entre ia et food
                food[i].SeFaireManger();
                iatest[j].mangerf(food[i]);
            }
        }
        if(player.collision(food[i])){ // vérifie s'il y a collision entre player et food
            food[i].SeFaireManger();
            player.mangerf(food[i]);
        }
        else {
            food[i].draw(); // dessine le food s'il n'y a aucune collision
        }
    }
    for(int u=0;u<this->nbia;++u){ // boucle pour toutes les ia
        for(int w=u+1;w<this->nbia;++w){ // boucle pour les ia autre que celle séléctionnée (ou déjà passé)
            if(iatest[u].collision(iatest[w])){ // vérifie s'il y a collision entre ia et un autre ia
                if(static_cast<double>(iatest[u].getTaille())<static_cast<double>(iatest[w].getTaille())-static_cast<double>(iatest[w].getTaille())*ECART){
                    iatest[u].SeFaireManger();
                    iatest[w].mangerj(iatest[u]);
                }
                else if(static_cast<double>(static_cast<double>(iatest[u].getTaille()))-static_cast<double>(iatest[u].getTaille())*ECART>static_cast<double>(iatest[w].getTaille())){
                    iatest[w].SeFaireManger();
                    iatest[u].mangerj(iatest[w]);
                }
            }
        }
        if(iatest[u].collision(player)){ // vérifie s'il y a collision entre ia et player
            if(static_cast<double>(iatest[u].getTaille())<static_cast<double>(player.getTaille())-static_cast<double>(player.getTaille())*ECART){
                iatest[u].SeFaireManger();
                player.mangerj(iatest[u]);
                if(this->son==0){
                   QSound::play("./Ressources/sefairemanger.wav");
                }
            }
            else if(static_cast<double>(iatest[u].getTaille())-static_cast<double>(iatest[u].getTaille())*ECART>static_cast<double>(player.getTaille())){
                player.SeFaireManger();
                iatest[u].mangerj(player);
                if(this->son==0){
                    QSound::play("./Ressources/manger.wav");
                }
            }
        }
    }
    // récupère la position de la souris
    glutPassiveMotionFunc(souris);
    // active la fonction pour que le joueur se déplace dans la direction de la souris
    this->deplacementJ();

    // obtenir des tirages différents à chaque lancement
    srand (time(NULL));
    // active la fonction pour que les ia se déplace dans la direction de leur "curseur"
    for(int i=0;i<this->nbia;++i){
        this->deplacementia(i);
    }
}

void MyGLWidget::resizeGL( GLsizei Largeur, GLsizei Hauteur){

        glViewport(0, 0, Largeur, Hauteur);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0,(static_cast<double>((static_cast<float>(Largeur))/(static_cast<float>(Hauteur)))), 1.0, 100.0);
}

//Fonction qui met a jour la position de la souris si l'utilisateur la bouge
void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    player.setsourisX(event->x());
    player.setsourisY(event->y());

    update(); //demande a qt dupdate le widget courant, ce qui rafraichis l'image
}

//Fonction qui deplace la boule du joueur en fonction de la taille de la fenetre opengl
void MyGLWidget::deplacementJ(){

    int width= this->width();
    int height= this->height();

    player.deplacement(width,height);

    update(); //demande a qt de update le widget courant, ce qui rafraichis l'image
}

//Deplacement de l'ia en fonction de la taille de la fenetre opengl
void MyGLWidget::deplacementia(int i)
{
   int width= this->width();
   int height= this->height();

   iatest[i].deplacement(width,height);

   update();
}
