#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "Controlleur/Partie.hh"

#include "Intelligence/Indila.hh"

int main() {
  srand(time(nullptr));

  std::vector<Joueur*> v;
  for(int i=0;i<4;i++) {
    v.push_back(new Indila());
  }

  Partie p(v,20);
  for(int i=0;i<20;i++) {
    p.nextFrame();
    p.renduTerminal();
    sleep(1);
  }
  return EXIT_SUCCESS;
}
