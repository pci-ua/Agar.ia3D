
#include <stdlib.h>

#include "couleur.hh"
Couleur CouleurRandom() {
  return {(rand()%256),(rand()%256),(rand()%256)};
}
