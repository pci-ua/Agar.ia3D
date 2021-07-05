#pragma once

#include <cstdint>
#include <string>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include <iostream>

using Composant = std::uint8_t;
class Couleur {
private:
  Composant _r,_g,_b;
  GLfloat r,g,b;
  bool glutOpti;

public:

  // Constructeurs ...
  Couleur(Composant r,Composant g,Composant b);
  Couleur(int r,int g,int b);
  Couleur(const Couleur & c) = default;
  ~Couleur() = default;

  // Accesseurs ...
  Composant getR() { return _r; }
  Composant getG() { return _g; }
  Composant getB() { return _b; }
  void setR(Composant r) { _r = r; glutOpti = false;}
  void setG(Composant g) { _g = g; glutOpti = false;}
  void setB(Composant b) { _b = b; glutOpti = false;}

  // Méthode de conversion
  std::string toString();
  std::string toString_rgb();
  std::string toString_hex();
  std::string toString_hsv();
  std::string toString_hsl();

};
