#include "nourriture.hh"

#include "../generateur/position.hh"

Nourriture::Nourriture(Couleur c)
  :Boule(EmplacementRandom(),NOURRITURE::TAILLE),couleur(c) {}
