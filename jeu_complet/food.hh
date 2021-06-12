#pragma once

#include "constante.hh"

#include "boule.hh"

class Food : public Boule{
  public:
    Food():Boule(FOOD::TAILLE){}
    void SeFaireManger();
    void draw() const override;
};
