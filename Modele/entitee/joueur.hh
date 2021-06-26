#pragma once

#include "../objet/boule.hh"
#include "../couleur/couleur.hh"
#include "../entitee/nourriture.hh"
#include <vector>
// Informations transmises aux IA, à propos des entitées à proximités
struct InfoEntitee {
     Vect2D<double> position;
     double taille;
};

class Partie;

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
  void request_deplacement(const Partie & p);
  virtual double deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) = 0;

  // Interraction inter-entitée
  void manger(Joueur* j);
  void manger(Nourriture* n);
  void etre_manger(Joueur* j);

  // Accesseurs ...
  Couleur getCouleur() { return couleur; }

};
