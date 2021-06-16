#pragma once

#include <cstdint>
#include <string>

using Composant = std::uint8_t;
class Couleur {
private:
  Composant _r,_g,_b;

public:

  // Constructeurs ...
  Couleur(Composant r,Composant g,Composant b);
  Couleur(int r,int g,int b);
  Couleur(const Couleur & c) = default;
  ~Couleur() = default;

  // Accesseurs ...
  Composant getR() { return _r; }
  Composant getG() { return _r; }
  Composant getB() { return _r; }
  void setR(Composant r) { _r = r; }
  void setG(Composant g) { _g = g; }
  void setB(Composant b) { _b = b; }

  // Méthode de conversion
  std::string toString();
  std::string toString_rgb();
  std::string toString_hex();
  std::string toString_hsv();
  std::string toString_hsl();

};
