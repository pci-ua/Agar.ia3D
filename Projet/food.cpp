#include "food.h"

// change la position de la food sur le terrain
void food::SeFaireManger() {
  this->_posX=(float)rand()/(RAND_MAX)*(longueur-marge+longueur-marge)-longueur+marge;
  this->_posZ=(float)rand()/(RAND_MAX)*(largeur-marge+largeur-marge)-largeur+marge;
}
