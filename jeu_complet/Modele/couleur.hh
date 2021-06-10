#pragma once

#include <cstdint> // int custom (requiert C++11 ou plus), pour optimisation en ram
#include <string> // pour la méthode toString
#include <GL/gl.h> // pour la méthode setGlutColor

using ComposanteCouleur = std::uint8_t; // 0 à 255

class Couleur {
private:
     ComposanteCouleur _r,_g,_b;

public:
     Couleur(); // Créé une couleur aléatoire
     Couleur(int r,int g,int b);
     Couleur(ComposanteCouleur r,ComposanteCouleur g,ComposanteCouleur b);
     ~Couleur() = default;
     Couleur(const Couleur & c) = default;

     void setR(ComposanteCouleur r) { _r = r; }
     void setG(ComposanteCouleur g) { _g = g; }
     void setB(ComposanteCouleur b) { _b = b; }
     ComposanteCouleur getR() const { return _r; }
     ComposanteCouleur getG() const { return _g; }
     ComposanteCouleur getB() const { return _b; }

     std::string toString() const;

     void setGlutColor() const;
};
