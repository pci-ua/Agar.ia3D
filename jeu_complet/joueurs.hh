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
#include "food.hh"

#define PI 3.14159265

class Joueurs : public Boule{
  public:
    Joueurs():Boule(TAILLE_JOUEURS),_vitesse(VITESSE){}
    ~Joueurs(){}
    void mangerf(Food const & objet);
    void mangerj(Joueurs const & objet);
    void SeFaireManger();
  protected:
    float _vitesse;
};
