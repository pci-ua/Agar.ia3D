#include "nourriture.hh"

#include "../generateur/position.hh"

Nourriture::Nourriture()
  :Boule(EmplacementRandom(),NOURRITURE::TAILLE) {}
