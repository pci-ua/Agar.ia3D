#include <iostream>

#include "joueur.hh"

#include "../generateur/position.hh"

Joueur::Joueur(Couleur c)
  :Boule(EmplacementRandom(),JOUEUR::TAILLE),vitesse(JOUEUR::VITESSE),couleur(c) {}

void Joueur::manger(Joueur* j) {
  setTaille(getTaille() + j->getTaille());
  j->etre_manger(this);
}

void Joueur::manger(Nourriture* n) {
  setTaille(getTaille() + n->getTaille());
  n->etre_manger();
}

void Joueur::etre_manger(Joueur* j) {
     std::cout << "Le joueur d'id" << this << " a été manger par le joueur d'id : " << j << std::endl;
  setTaille(JOUEUR::TAILLE);
  getPosition() = EmplacementRandom();
}
