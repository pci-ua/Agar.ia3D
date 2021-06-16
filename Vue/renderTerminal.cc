#include "../Controlleur/Partie.hh"

#include <iostream>

void Partie::renduTerminal() {
  std::cout << std::endl << std::endl << std::endl << std::endl << "_____________________________________________"<< std::endl ;
  std::cout << "Frame restante : " << tempRestant << std::endl;
  for(auto participant:participants) {
    auto p = participant->getPosition();
    std::cout << " { " << p.getX() << "," << p.getZ() << "}" << std::endl;
  }
}
