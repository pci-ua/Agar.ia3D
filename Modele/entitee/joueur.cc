#include "joueur.hh"

#include "../generateur/position.hh"

#include <math.h> // PI (M_PI), cos , sin

Joueur::Joueur(Couleur c)
  :Boule(EmplacementRandom(),JOUEUR::TAILLE),vitesse(JOUEUR::VITESSE),couleur(c) {}

void Joueur::request_deplacement() {
   double angle = deplacement();
   Vect2D<double> k(cos(angle),sin(angle));
   k.setMagnitude(vitesse);
   auto p = getPosition() + k;

   const Vect2D<double> TopLeft(0,0);
   const Vect2D<double> BotRight(CARTE::LARGEUR,CARTE::LONGUEUR);

   if( TopLeft <= p && p <= BotRight) {
     getPosition() = p;
   }
}

void Joueur::manger(Joueur* j) {
  setTaille(getTaille() + j->getTaille());
  j->etre_manger(this);
}

void Joueur::manger(Nourriture* n) {
  setTaille(getTaille() + n->getTaille());
  n->etre_manger();
}

void Joueur::etre_manger(Joueur* j) {
  setTaille(JOUEUR::TAILLE);
  getPosition() = EmplacementRandom();
}
