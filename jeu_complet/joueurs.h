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
    joueurs():boule(0.5f,(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5,(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5,(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX)),_vitesse(0.1){}
    ~joueurs(){}
    void mangerf(food objet);
    void mangerj(joueurs objet);
    void SeFaireManger();
  protected:
    float _vitesse;
};
