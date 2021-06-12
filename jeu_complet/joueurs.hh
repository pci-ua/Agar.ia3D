#pragma once

#include "boule.hh"
#include "food.hh"

#define PI 3.14159265

class Joueurs : public Boule{
public:
     Joueurs():Boule(TAILLE_JOUEURS),_vitesse(VITESSE){}
     ~Joueurs() = default;
     Joueurs(const Joueurs & c) = default;

     void mangerf(Food const & objet);
     void mangerj(Joueurs const & objet);
     void SeFaireManger();
     void draw() const override;
  protected:
    float _vitesse;
};
