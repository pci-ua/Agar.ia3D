#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "joueurs.h"

class ia : public joueurs {
public:
  ia():joueurs(){}
  void const setiaX(int x){this->_posAleatoireX=x;}
  void const setiaY(int y){this->_posAleatoireY=y;}
  void deplacement(int i);
private:
  int _posAleatoireX;
  int _posAleatoireY;
};
