#pragma once

#include "../objet/boule.hh"
#include "../couleur/couleur.hh"
#include "../entitee/nourriture.hh"

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

  // Interraction inter-entitée
  void manger(Joueur* j);
  void manger(Nourriture* n);
  void etre_manger(Joueur* j);

};
