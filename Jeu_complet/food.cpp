#include "food.h"

void food::SeFaireManger() {
  this->_posX=(float)rand()/(RAND_MAX)*(longueur-0.5+longueur-0.5)-longueur+0.5;
  this->_posZ=(float)rand()/(RAND_MAX)*(largeur-0.5+largeur-0.5)-largeur+0.5;
}
