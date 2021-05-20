
#include "myglwidget.h"
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <QOpenGLFunctions>
 #include <QMouseEvent>
#include <iostream>
#include <QSurfaceFormat>


#include "actions.h"
#include "terrain.h"
#include "boule.h"
#include "food.h"
#include "joueurs.h"
#include "joueur.h"
#include "ia.h"
#include <array>


int xboules=0.0;
int zboules=0.0;

int window;

joueur Player(0,0);

ia iatest[20];

int const nbfood(300);
food Food[nbfood];

GLfloat x_cam=Player.getX();
GLfloat y_cam=10.0f;
GLfloat z_cam=10.0f;

GLint frame=0,temps,timebase=0;


float longueur=40.0;
float largeur=40.0;


bool collision(boule b1,boule b2){
    float posX1,posX2,taille1,posZ1,posZ2,taille2;
    posX1=b1.getX();
    posZ1=b1.getZ();
    taille1=b1.getTaille();

    posX2=b2.getX();
    posZ2=b2.getZ();
    taille2=b2.getTaille();

    if(taille1>=taille2){
        if((pow(posX2-posX1,2)+pow(posZ2-posZ1,2))<=pow(taille1,2)){
            return true;
        }
    }
    else {
        if((pow(posX2-posX1,2)+pow(posZ2-posZ1,2))<=pow(taille2,2)){
            return true;
        }
    }
    return false;

    /*if((pow(posX2-posX1,2)+pow(posZ2-posZ1,2))<=pow(taille1+taille2,2)){
        return true;
    }
    return false;*/
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
    glClearColor(0.2f,0.2f,0.2f,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    this->setMouseTracking(true);


}


void MyGLWidget::paintGL()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

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

        gluLookAt(static_cast<double>(x_cam),static_cast<double>(y_cam),static_cast<double>(z_cam),static_cast<double>(Player.getX()),0.0,static_cast<double>(Player.getZ()),0.0,1.0,0.0);

        glColor3f(1.0,1.0,0.0);
        terrain t(longueur,largeur);

        Player.draw();

        for(int i=0; i<this->nbia;++i){

            iatest[i].draw();
        }

        for(int i=0; i<nbfood;++i){
                 for(int j=0; j<this->nbia;++j){
                         if(collision(iatest[j],Food[i])){
                                 Food[i].SeFaireManger();
                                 iatest[j].mangerf(Food[i]);
                         }
                 }
                 if(collision(Player,Food[i])){
                         Food[i].SeFaireManger();
                         Player.mangerf(Food[i]);
                 }
                 else {

                         Food[i].draw();
                 }
         }

         for(int u=0;u<this->nbia;++u){
                 for(int w=u+1;w<this->nbia;++w){
                         if(collision(iatest[u],iatest[w])){
                                 if(static_cast<double>(iatest[u].getTaille())<static_cast<double>(iatest[w].getTaille())-static_cast<double>(iatest[w].getTaille())*0.05){
                                         iatest[u].SeFaireManger();
                                         iatest[w].mangerj(iatest[u]);
                                 }
                                 else if(static_cast<double>(static_cast<double>(iatest[u].getTaille()))-static_cast<double>(iatest[u].getTaille())*0.05>static_cast<double>(iatest[w].getTaille())){
                                         iatest[w].SeFaireManger();
                                         iatest[u].mangerj(Player);
                                 }
                         }
                 }
                 if(collision(iatest[u],Player)){
                         if(static_cast<double>(iatest[u].getTaille())<static_cast<double>(Player.getTaille())-static_cast<double>(Player.getTaille())*0.05){
                                 iatest[u].SeFaireManger();
                                 Player.mangerj(iatest[u]);
                         }
                         else if(static_cast<double>(iatest[u].getTaille())-static_cast<double>(iatest[u].getTaille())*0.05>static_cast<double>(Player.getTaille())){
                                 Player.SeFaireManger();
                                 iatest[u].mangerj(Player);
                        }
                }
        }



        glutPassiveMotionFunc(souris);
        this->deplacementJ();

        srand (time(NULL));
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
    Player.setsourisX(event->x());
    Player.setsourisY(event->y());

    update(); //demande a qt dupdate le widget courant, ce qui rafraichis l'image

}

//Fonction qui deplace la boule du joueur en fonction de la taille de la fenetre opengl
void MyGLWidget::deplacementJ(){


    int width= this->width();
    int height= this->height();

     Player.deplacement(width,height);

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






