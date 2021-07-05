
#include <stdlib.h>

#include "g_couleur.hh"
Couleur CouleurRandom() {
  return {(rand()%256),(rand()%256),(rand()%256)};
}
