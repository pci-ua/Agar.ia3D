#pragma once

#include <math.h>
#include "Modele/vect2d.hh"
#include "joueurs.hh"

class Ia : public Joueurs {
public:
  Ia():Joueurs(),_cible(Vect2D(0,0)){}
  void deplacement(int width,int height);
private:
     Vect2D _cible;
};
