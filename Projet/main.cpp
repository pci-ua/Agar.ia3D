#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "terrain.h"
#include "boule.h"
#include "food.h"
#include "joueurs.h"
#include "joueur.h"
#include "ia.h"

int window;

// en fonction de ce que le joueur choisit modifier la taille du terrain
float longueur=40.0/2;
float largeur=40.0/2;

joueur Player(0,0);

int const nbia(5);
ia iatest[nbia];

int const nbfood(200);
food Food[nbfood];

GLfloat x_cam=Player.getX();
GLfloat y_cam=7.0f;
GLfloat z_cam=Player.getZ()+5;

GLint frame=0,temps,timebase=0;

// retourne vrai si collision et faux sinon
bool collision(boule const & b1,boule const & b2){
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
  } else { // (dans ce cas la deuxième)
  	if((pow(posX2-posX1,2)+pow(posZ2-posZ1,2))<=pow(taille2,2)){
    	return true;
    }
  }
  return false;
}

GLvoid Modelisation()
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
	gluLookAt(x_cam,y_cam,z_cam,Player.getX(),0.0f,Player.getZ(),0.0,1.0,0.0);

	// couleur jaune du terrain
	glColor3f(1.0,1.0,0.0);
	terrain t(longueur,largeur); // création du terrain

	// dessine la joueur
	Player.draw();

	// boucle pour toutes les foods
	for(int i=0; i<nbfood;++i){
			 for(int j=0; j<nbia;++j){ // boucle pour toutes les ia
					 if(collision(iatest[j],Food[i])){ // vérifie s'il y a collision entre ia et food
							 Food[i].SeFaireManger();
							 iatest[j].mangerf(Food[i]);
					 }
			 }
			 if(collision(Player,Food[i])){ // vérifie s'il y a collision entre player et food
					 Food[i].SeFaireManger();
					 Player.mangerf(Food[i]);
			 }
			 else {
					Food[i].draw(); // dessine le food
			 }
	 }

	 for(int u=0;u<nbia;++u){ // boucle pour toutes les ia
			 for(int w=u+1;w<nbia;++w){ // boucle pour les ia autre que celle séléctionnée (ou déjà passé)
					 if(collision(iatest[u],iatest[w])){ // vérifie s'il y a collision entre ia et un autre ia
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
			 if(collision(iatest[u],Player)){ // vérifie s'il y a collision entre ia et player
					 if(iatest[u].getTaille()<Player.getTaille()-Player.getTaille()*0.05){
							 iatest[u].SeFaireManger();
							 Player.mangerj(iatest[u]);
					 }
					 else if(iatest[u].getTaille()-iatest[u].getTaille()*0.05>Player.getTaille()){
							 Player.SeFaireManger();
							 iatest[u].mangerj(Player);
					}
			}
			else {
				iatest[u].draw(); // dessine l'ia
			}
	}

	//
	glutPassiveMotionFunc(souris);
	// active la fonction pour que le joueur se déplace dans la direction de la souris
	Player.deplacement();
	//  obtenir des tirages différents à chaque lancement
	srand (time(NULL));
	// active la fonction pour que les ia se déplace dans la direction de leur "curseur"
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

	glutIdleFunc(&Modelisation);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();
}
