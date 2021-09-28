#include <iostream>

#include "joueur.hh"

#include "../generateur/position.hh"

Joueur::Joueur(Couleur c,QString p)
  :Boule(EmplacementRandom(),JOUEUR::TAILLE),vitesse(JOUEUR::VITESSE),couleur(c),pseudo(p) {}

void Joueur::manger(Joueur* j) {
  setTaille(getTaille() + j->getTaille());
  j->etre_manger(this);
  killCount++;
  if(getTaille() > maxScore) maxScore = getTaille();
}

void Joueur::manger(Nourriture* n) {
  setTaille(getTaille() + n->getTaille());
  n->etre_manger();
  if(getTaille() > maxScore) maxScore = getTaille();
}

void Joueur::etre_manger(Joueur* j) {
     std::cout << "Le joueur d'id" << this << " a été manger par le joueur d'id : " << j << std::endl;
  setTaille(JOUEUR::TAILLE);
  getPosition() = EmplacementRandom();
  deathCount++;
}
