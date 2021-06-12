#pragma once

#include <math.h>

#include "joueurs.hh"

class Ia : public Joueurs {
public:
  Ia():Joueurs(){}
  void  setiaX(int x){this->_posAleatoireX=x;}
  void  setiaY(int y){this->_posAleatoireY=y;}
  void deplacement(int width,int height);
private:
  int _posAleatoireX;
  int _posAleatoireY;
};
