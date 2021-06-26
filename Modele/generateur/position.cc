
#include <stdlib.h>

#include "position.hh"
Vect2D<double> EmplacementRandom() {
     return {
       (static_cast<double>(rand()%CARTE::LARGEUR) + (static_cast<double>(rand())/RAND_MAX) ),
       (static_cast<double>(rand()%CARTE::LONGUEUR) + (static_cast<double>(rand())/RAND_MAX) )
     } ;
}
