#pragma once

#include "../objet/boule.hh"

class Nourriture
  :public Boule{
private:

public:

  // Constructeurs ...
  Nourriture();
  Nourriture(const Nourriture & c) = default;
  ~Nourriture() = default;

};
