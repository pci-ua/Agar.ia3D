#include "food.hh"

// change la position de la food sur le terrain
void Food::SeFaireManger() {
  this->_position = Vect2D({(-LONGUEUR+MARGE,LONGUEUR-MARGE)},{(-LONGUEUR+MARGE,LONGUEUR-MARGE)});
}
