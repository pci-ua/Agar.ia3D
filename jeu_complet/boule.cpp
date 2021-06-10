#include "boule.hh"

// Pour le dessin
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

void Boule::draw() const{
	glPushMatrix();
	{
		glTranslatef(_posX,0,_posZ); //se positionne sur le terrain
		_couleur.setGlutColor();
		glutSolidSphere(static_cast<double>(_taille),SUBDIVISIONS_BOULE,SUBDIVISIONS_BOULE); // créer une sphère
	}
	glPopMatrix();
}

Boule::Boule(float taille) {
	// rand et RAND_MAX viennent de la bibliothèque stdlib.h
	// le calcul suivant correspond à prendre un nombre aléatoire (flottant) compris dans le terrain
	this->_posX = (float)rand()/(RAND_MAX)*(LONGUEUR-MARGE+LONGUEUR-MARGE)-LONGUEUR+MARGE;
	this->_posZ = (float)rand()/(RAND_MAX)*(LARGEUR-MARGE+LARGEUR-MARGE)-LARGEUR+MARGE;
	this->_taille = taille;
}
