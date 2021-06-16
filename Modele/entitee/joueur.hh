#pragma once

#include "../objet/boule.hh"
#include "../couleur/couleur.hh"

class Joueur
  :public Boule{
private:
  float vitesse;
  Couleur couleur;

public:

  // Constructeurs ...
  Joueur(Couleur c);
  Joueur(const Joueur & c) = delete;
  virtual ~Joueur() = default;

  // Méthode lié au déplacement
  void request_deplacement();
  virtual double deplacement() = 0;
};
