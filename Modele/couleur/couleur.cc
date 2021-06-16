#include "couleur.hh"

#include <iomanip>

Couleur::Couleur(Composant r,Composant g,Composant b)
  :_r(r),_g(g),_b(b) {}

Couleur::Couleur(int r,int g,int b) {
  if(r < 0 || r > 255) throw std::out_of_range("Red color componnant must stay between 0 and 255 included ! ");
  if(g < 0 || g > 255) throw std::out_of_range("Green color componnant must stay between 0 and 255 included ! ");
  if(b < 0 || b > 255) throw std::out_of_range("Blue color componnant must stay between 0 and 255 included ! ");
  _r = static_cast<Composant>(r);
  _g = static_cast<Composant>(g);
  _b = static_cast<Composant>(b);
}



std::string Couleur::toString()
  { return toString_rgb(); }

std::string Couleur::toString_rgb()
  { return "rgb("+ std::to_string(_r) +","+ std::to_string(_g) +","+ std::to_string(_b) +")"; }

std::string Couleur::toString_hex() {
  std::stringstream stream;
  stream << "#"
    << std::setfill ('0') << std::setw(2) << std::hex << _r
    << std::setfill ('0') << std::setw(2) << std::hex << _g
    << std::setfill ('0') << std::setw(2) << std::hex << _b;
  return stream.str();
}

std::string Couleur::toString_hsv() { return ""; }
std::string Couleur::toString_hsl() { return ""; }
