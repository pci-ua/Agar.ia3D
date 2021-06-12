#include "boule.hh"

#include "joueurs.hh"
#include "food.hh"

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
		Joueurs* j = dynamic_cast<Joueurs*>(this);
		if( j != nullptr) {
			glutSolidSphere(static_cast<double>(_taille),RENDU::SUBDIVISIONS_JOUEUR,RENDU::SUBDIVISIONS_JOUEUR);
		} else {
			Food* f = dynamic_cast<Food*>(this);
			if( f != nullptr) {
				glutSolidSphere(static_cast<double>(_taille),RENDU::SUBDIVISIONS_FOOD,RENDU::SUBDIVISIONS_FOOD);
			} else {
				glutSolidSphere(static_cast<double>(_taille),RENDU::SUBDIVISIONS_BOULE,RENDU::SUBDIVISIONS_BOULE);
			}
		}
	}
	glPopMatrix();
}


Boule::Boule(float taille)
:_taille(taille),_position(Vect2D({-TERRAIN::LONGUEUR_S,TERRAIN::LONGUEUR_S},{-TERRAIN::LARGEUR_S,TERRAIN::LARGEUR_S})),_couleur(Couleur()) {}
