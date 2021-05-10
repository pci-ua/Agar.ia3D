#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "actions.h"
#include "terrain.h"
#include "food.h"

GLfloat xrot_camera=0.0;
GLfloat yrot_camera=0.0;
GLfloat zrot_camera=0.0;

GLfloat x_objet=0.0;
GLfloat z_objet=0.0;

int xboules=0.0;
int zboules=0.0;

int window;

Joueur J(0,0);
joueur Player;

int const nbfood(200);
food Food[nbfood];

GLfloat z=-10.0f;

GLfloat x_cam=0.0f;
GLfloat y_cam=15.0f;
GLfloat z_cam=15.0f;

bool collision(boule b1,boule b2){
	float posX1,posX2,taille1,posZ1,posZ2,taille2;
	posX1=b1.getX();
	posZ1=b1.getZ();
	taille1=b1.getTaille();

	posX2=b2.getX();
	posZ2=b2.getZ();
	taille2=b2.getTaille();

	if((pow(posX2-posX1,2)+pow(posZ2-posZ1,2))<=pow(taille1+taille2,2)){
		return true;
	}
	return false;
}

GLvoid Modelisation()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(0.0,0.0,z);
	gluLookAt(Player.getX(),y_cam,z_cam,Player.getX(),0.0f,Player.getZ(),0.0,1.0,0.0);

	glRotatef(xrot_camera,1.0f,0.0f,0.0f);
	glRotatef(yrot_camera,0.0f,1.0f,0.0f);
	glRotatef(zrot_camera,0.0f,0.0f,1.0f);

	glColor3f(1.0,1.0,0.0);
	terrain t;

	Player.draw();

	for(int i=0; i<nbfood;++i){
		if(collision(Player,Food[i])){
			Food[i].SeFaireManger();
			Player.manger();
		}
		else {
			Food[i].draw();
		}
	}


	glutPassiveMotionFunc(souris);
	J.deplacement();
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
	window = glutCreateWindow("Agar.io");
	glutDisplayFunc(&Modelisation);
	glutReshapeFunc(&Redimensionne);

	glutKeyboardFunc(&touche_pressee);
  glutSpecialFunc(&touche_speciale_pressee);

	glutIdleFunc(&Modelisation);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();
}
