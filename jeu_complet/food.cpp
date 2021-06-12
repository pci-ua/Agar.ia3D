#include "food.hh"

// change la position de la food sur le terrain
void Food::SeFaireManger() {
  this->_position = Vect2D({-TERRAIN::LONGUEUR_S,TERRAIN::LONGUEUR_S},{-TERRAIN::LARGEUR_S,TERRAIN::LARGEUR_S});
}

void Food::draw() const {
	glPushMatrix();

	_position.setGlutPosition();
	_couleur.setGlutColor();

     glutSolidSphere(static_cast<double>(_taille),RENDU::SUBDIVISIONS_FOOD,RENDU::SUBDIVISIONS_FOOD);

     glPopMatrix();
}
