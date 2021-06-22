#include "../Controlleur/Partie.hh"

#include <iostream>
#include <array>
#include <cmath>
#include <cstdlib>

#include "../constante.hh"
#include "../Modele/couleur/couleur.hh"

void Partie::renduTerminal() {
  system("clear");
  std::array<std::array<bool,CARTE::LARGEUR>,CARTE::LONGUEUR> carte;
  for(unsigned int i=0 ; i<CARTE::LONGUEUR ; i++) {
    for(unsigned int j=0 ; j<CARTE::LARGEUR ; j++) {
      carte[i][j] = false;
    }
  }
  for(auto participant:participants) {
    auto p = participant->getPosition();
    carte[ (int)(p.getX()) ] [ (int)(p.getZ()) ] = true;
  }

  for(unsigned int i=0 ; i<CARTE::LONGUEUR ; i++) {
    for(unsigned int j=0 ; j<CARTE::LARGEUR ; j++) {
      std::cout << "\033[103;94m" << ( (carte[i][j]) ? "•" : " " ) << "\033[0m";
    }
    std::cout << std::endl;
  }

}
