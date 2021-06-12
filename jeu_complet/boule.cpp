#include "boule.hh"

// Pour le dessin
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <GL/glu.h>

void Boule::draw() const{
	glPushMatrix();
	{
		_position.setGlutPosition();
		_couleur.setGlutColor();
		glutSolidSphere(static_cast<double>(_taille),SUBDIVISIONS_BOULE,SUBDIVISIONS_BOULE); // créer une sphère
	}
	glPopMatrix();
}


Boule::Boule(float taille)
:_taille(taille),_position(Vect2D({-TERRAIN::LONGUEUR_S,TERRAIN::LONGUEUR_S},{-TERRAIN::LARGEUR_S,TERRAIN::LARGEUR_S})),_couleur(Couleur()) {}
