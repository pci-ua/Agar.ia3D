#include "myglwidget.h"

Joueur player(0,0);

Ia iatest[NBIAMAX];

Food food[NBFOOD];

GLfloat x_cam=player.getX();
GLfloat y_cam=7.0f;
GLfloat z_cam=player.getZ()+5;

GLint frame=0,temps,timebase=0;

// retourne vrai si collision et faux sinon
bool collision(Boule b1,Boule b2){
    float posX1,posX2,taille1,posZ1,posZ2,taille2;
    posX1=b1.getX();
    posZ1=b1.getZ();
    taille1=b1.getTaille();

    posX2=b2.getX();
    posZ2=b2.getZ();
    taille2=b2.getTaille();

    // comparaison des tailles des 2 boules pour savoir laquelle est la plus grande (dans ce cas la première)
    if(taille1>=taille2){
        // Compare la distance des 2 centres des sphères avec la taille la plus grande
        if((pow(posX2-posX1,2)+pow(posZ2-posZ1,2))<=pow(taille1,2)){
            return true;
        }
    }
    else { // (dans ce cas la deuxième)
        if((pow(posX2-posX1,2)+pow(posZ2-posZ1,2))<=pow(taille2,2)){
            return true;
        }
    }
    return false;
}

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

void MyGLWidget::initializeGL()
{
    this->initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    this->setMouseTracking(true);
}


void MyGLWidget::paintGL()
{
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
    gluLookAt(static_cast<double>(x_cam),static_cast<double>(y_cam),static_cast<double>(z_cam),static_cast<double>(player.getX()),0.0,static_cast<double>(player.getZ()),0.0,1.0,0.0);

    // couleur jaune du terrain
    glColor3f(1.0,1.0,0.0);
    terrain t(LONGUEUR,LARGEUR); // création du terrain

    // dessine le joueur
    player.draw();

    for(int i=0; i<this->nbia;++i){

        iatest[i].draw();
    }

    // boucle pour toutes les foods
    for(int i=0; i<NBFOOD;++i){
        for(int j=0; j<this->nbia;++j){ // boucle pour toutes les ia
            if(collision(iatest[j],food[i])){ // vérifie s'il y a collision entre ia et food
                food[i].SeFaireManger();
                iatest[j].mangerf(food[i]);
            }
        }
        if(collision(player,food[i])){ // vérifie s'il y a collision entre player et food
            food[i].SeFaireManger();
            player.mangerf(food[i]);
        }
        else {
            food[i].draw(); // dessine le food s'il n'y a aucune collision
        }
    }
    for(int u=0;u<this->nbia;++u){ // boucle pour toutes les ia
        for(int w=u+1;w<this->nbia;++w){ // boucle pour les ia autre que celle séléctionnée (ou déjà passé)
            if(collision(iatest[u],iatest[w])){ // vérifie s'il y a collision entre ia et un autre ia
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
        if(collision(iatest[u],player)){ // vérifie s'il y a collision entre ia et player
            if(static_cast<double>(iatest[u].getTaille())<static_cast<double>(player.getTaille())-static_cast<double>(player.getTaille())*ECART){
                iatest[u].SeFaireManger();
                player.mangerj(iatest[u]);
            }
            else if(static_cast<double>(iatest[u].getTaille())-static_cast<double>(iatest[u].getTaille())*ECART>static_cast<double>(player.getTaille())){
                player.SeFaireManger();
                iatest[u].mangerj(player);
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
