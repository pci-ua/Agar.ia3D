#include "Manuel.hh"

#include <math.h>

#define PI 3.1415927

// à chaque frame retourne l'angle de direction stocké
double JoueurManuel::deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) {
	return angle;
}

// à chaque mouvement de la souris recalcul l'angle de direction
void JoueurManuel::setSouris(int x,int y,int width,int height) {
	// Décallage vers le centre et changement repère
	double cx =  x - (width / 2);
	double cy =  y - (height / 2);

	angle = atan2(cy,cx) + PI / 4;
}