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

extern float longueur;
extern float largeur;

class food : public boule{
  public:
    food():boule(0.1f,(float)rand()/(RAND_MAX)*(longueur-0.5+longueur-0.5)-longueur+0.5,(float)rand()/(RAND_MAX)*(largeur-0.5+largeur-0.5)-largeur+0.5,(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX)){}
    void SeFaireManger();
};
