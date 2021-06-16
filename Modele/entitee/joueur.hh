#pragma once

#include "../objet/boule.hh"

class Joueur
  :public Boule{
private:
  float vitesse;

public:

  // Constructeurs ...
  Joueur();
  Joueur(const Joueur & c) = delete;
  virtual ~Joueur() = default;

  // Méthode lié au déplacement
  void request_deplacement();
  virtual double deplacement() = 0;
};
