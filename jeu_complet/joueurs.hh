#pragma once

#include "constante.hh"

#include "boule.hh"
#include "food.hh"

#define PI 3.14159265

class Joueurs : public Boule{
public:
     Joueurs():Boule(JOUEUR::TAILLE),_vitesse(JOUEUR::VITESSE){}
     ~Joueurs() = default;
     Joueurs(const Joueurs & c) = default;

     void mangerf(Food const & objet);
     void mangerj(Joueurs const & objet);
     void SeFaireManger();
     void draw() const override;
  protected:
    float _vitesse;
};
