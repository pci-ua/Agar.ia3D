#include "couleur.hh"

#include <iomanip>
#include <algorithm>
#include <cmath>

// Constructeurs ...
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


// Méthode de conversion
std::string Couleur::toString()
  { return toString_rgb(); }

std::string Couleur::toString_rgb()
  { return "rgb("+ std::to_string(_r) +","+ std::to_string(_g) +","+ std::to_string(_b) +")"; }

std::string Couleur::toString_hex() {
  std::stringstream stream;
  stream << "#"
    << std::setfill ('0') << std::setw(2) << std::hex << static_cast<int>(_r)
    << std::setfill ('0') << std::setw(2) << std::hex << static_cast<int>(_g)
    << std::setfill ('0') << std::setw(2) << std::hex << static_cast<int>(_b);
  return stream.str();
}

std::string Couleur::toString_hsv() {
  float rp = static_cast<float>(_r)/255;
  float gp = static_cast<float>(_g)/255;
  float bp = static_cast<float>(_b)/255;
  float cmax = std::max(std::max(rp,gp),bp);
  float cmin = std::min(std::min(rp,gp),bp);
  float delta = cmax - cmin;

  float H;
  if(delta == 0) H = 0;
  else {
    if(cmax == rp) { H = ((gp-bp)/delta); while(H>6) { H-=6;} while(H<0) { H+=6; } } else
    if(cmax == gp) H = ((bp-rp)/delta)+2; else
    if(cmax == bp) H = ((rp-gp)/delta)+4;
    H*= 60;
  }

  float S;
  if(cmax == 0) S = 0;
  else S = delta / cmax;

  float V = cmax;

  return "hsv(" +std::to_string(H)+ "°," +std::to_string(S)+ "%," +std::to_string(V)+ "%)";
 }
std::string Couleur::toString_hsl() {
  float rp = static_cast<float>(_r)/255;
  float gp = static_cast<float>(_g)/255;
  float bp = static_cast<float>(_b)/255;
  float cmax = std::max(std::max(rp,gp),bp);
  float cmin = std::min(std::min(rp,gp),bp);
  float delta = cmax - cmin;

  float H;
  if(delta == 0) H = 0;
  else {
    if(cmax == rp) { H = ((gp-bp)/delta); while(H>6) { H-=6;} while(H<0) { H+=6; } } else
    if(cmax == gp) H = ((bp-rp)/delta)+2; else
    if(cmax == bp) H = ((rp-gp)/delta)+4;
    H*= 60;
  }

  float L = (cmax + cmin)/2;

  float S;
  if(delta == 0) S = 0;
  else S = delta / (1-abs(2*L -1));

  return "hsl(" +std::to_string(H)+ "°," +std::to_string(S)+ "%," +std::to_string(L)+ "%)";
}
