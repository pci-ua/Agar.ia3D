#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "actions.h"
#include "terrain.h"
#include "boule.h"
#include "food.h"
#include "joueurs.h"
#include "joueur.h"
#include "ia.h"

GLfloat xrot_camera=0.0;
GLfloat yrot_camera=0.0;
GLfloat zrot_camera=0.0;

GLfloat x_objet=0.0;
GLfloat z_objet=0.0;

int xboules=0.0;
int zboules=0.0;

int window;

joueur Player(0,0);

int const nbia(5);
ia iatest[nbia];

int const nbfood(200);
food Food[nbfood];

GLfloat x_cam=Player.getX();
GLfloat y_cam=10.0f;
GLfloat z_cam=10.0f;

// en fonction de ce que le joueur choisit modifier la taille du terrain
float longueur=20.0;
float largeur=20.0;

GLint frame=0,temps,timebase=0;

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

GLvoid Modelisation()
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

	gluLookAt(x_cam,y_cam,z_cam,Player.getX(),0.0f,Player.getZ(),0.0,1.0,0.0);

	glColor3f(1.0,1.0,0.0);
	terrain t(longueur,largeur);

	Player.draw();

	for(int i=0; i<nbia;++i){
		iatest[i].draw();
	}

	for(int i=0; i<nbfood;++i){
			 for(int j=0; j<nbia;++j){
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

	 for(int u=0;u<nbia;++u){
			 for(int w=u+1;w<nbia;++w){
					 if(collision(iatest[u],iatest[w])){
							 if(iatest[u].getTaille()<iatest[w].getTaille()-iatest[w].getTaille()*0.05){
									 iatest[u].SeFaireManger();
									 iatest[w].mangerj(iatest[u]);
							 }
							 else if(iatest[u].getTaille()-iatest[u].getTaille()*0.05>iatest[w].getTaille()){
									 iatest[w].SeFaireManger();
									 iatest[u].mangerj(Player);
							 }
					 }
			 }
			 if(collision(iatest[u],Player)){
					 if(iatest[u].getTaille()<Player.getTaille()-Player.getTaille()*0.05){
							 iatest[u].SeFaireManger();
							 Player.mangerj(iatest[u]);
					 }
					 else if(iatest[u].getTaille()-iatest[u].getTaille()*0.05>Player.getTaille()){
							 Player.SeFaireManger();
							 iatest[u].mangerj(Player);
					}
			}
	}

	glutPassiveMotionFunc(souris);
	Player.deplacement();
	srand (time(NULL));
	for(int i=0;i<nbia;++i){
		iatest[i].deplacement(i);
	}
	glutSwapBuffers();
}

GLvoid Redimensionne(GLsizei Largeur, GLsizei Hauteur)
{
	glViewport(0, 0, Largeur, Hauteur);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,((float) Largeur)/((float) Hauteur), 1.0, 100.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Agar.ia");
	glutDisplayFunc(&Modelisation);
	glutReshapeFunc(&Redimensionne);

	glutKeyboardFunc(&touche_pressee);
  glutSpecialFunc(&touche_speciale_pressee);

	glutIdleFunc(&Modelisation);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();
}
