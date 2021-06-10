#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "boule.hh"

class Food : public Boule{
  public:
    Food():Boule(TAILLE_FOOD){}
    void SeFaireManger();
};
