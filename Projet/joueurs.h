#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "boule.h"
#include "food.h"

#define PI 3.14159265

class joueurs : public boule{
  public:
    joueurs():boule(taille_joueurs),_vitesse(vitesse){}
    ~joueurs(){}
    void mangerf(food const & objet);
    void mangerj(joueurs const & objet);
    void SeFaireManger();
  protected:
    float _vitesse;
};
