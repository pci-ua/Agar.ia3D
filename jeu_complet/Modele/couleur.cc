#include "couleur.hh"

#include <stdlib.h>
#include <stdexcept>

std::string Couleur::toString() const {
     return "rgb("+ std::to_string(_r) +","+ std::to_string(_g) +","+ std::to_string(_b) +")";
}

void Couleur::setGlutColor() const {
     glColor3f(
          static_cast<float>(_r) / 256,
          static_cast<float>(_g) / 256,
          static_cast<float>(_b) / 256
     );
}

Couleur::Couleur(int r,int g,int b) {
     if(
      (r < 0 || r > 255 ) ||
      (g < 0 || g > 255 ) ||
      (b < 0 || b > 255 )
     ) { throw std::out_of_range("Couleur construct expect integer between 0 and 255 only"); }
     _r = r;
     _g = g;
     _b = b;
}

Couleur::Couleur(ComposanteCouleur r,ComposanteCouleur g,ComposanteCouleur b)
     :_r(r),_g(g),_b(b) {}

Couleur::Couleur()
     :_r( rand()%256 ),_g( rand()%256 ),_b( rand()%256 ) {}
