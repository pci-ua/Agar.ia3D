
#include <stdlib.h>

#include "position.hh"
Vect2D<double> EmplacementRandom() {
     return {
          (static_cast<double>(rand()%(2*CARTE::LONGUEUR)) + (static_cast<double>(rand())/RAND_MAX) ) - static_cast<double>(CARTE::LONGUEUR),
          (static_cast<double>(rand()%(2*CARTE::LARGEUR)) + (static_cast<double>(rand())/RAND_MAX) ) - static_cast<double>(CARTE::LARGEUR)
     } ;
}
