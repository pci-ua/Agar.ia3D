#pragma once

#include "../objet/boule.hh"
#include "../couleur/couleur.hh"

class Nourriture
  :public Boule{
private:
Couleur couleur;

public:

  // Constructeurs ...
  Nourriture(Couleur c);
  Nourriture(const Nourriture & c) = default;
  ~Nourriture() = default;

};
