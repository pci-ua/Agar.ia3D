#include "Manuel.hh"

#include <math.h>

// à chaque frame retourne l'angle de direction stocké
double JoueurManuel::deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) {
  return angle;
}

// à chaque mouvement de la souris recalcul l'angle de direction
void JoueurManuel::setSouris(int x,int y,int width,int height) {
	// Décallage vers le centre
	double cx = x - (width / 2);
	double cy = y - (height / 2);

	this->angle = atan (cy / cx);
}