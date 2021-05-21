#include "food.h"

// change la position de la food sur le terrain
void Food::SeFaireManger() {
  this->_posX=(float)rand()/(RAND_MAX)*(LONGUEUR-MARGE+LONGUEUR-MARGE)-LONGUEUR+MARGE;
  this->_posZ=(float)rand()/(RAND_MAX)*(LARGEUR-MARGE+LARGEUR-MARGE)-LARGEUR+MARGE;
}
