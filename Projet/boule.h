#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

class boule{
  public:
    boule(float taille,float posX,float posZ,float r,float g,float b){
      this->_posX = posX;
      this->_posZ = posZ;
      this->_taille = taille;
      this->_r = r;
      this->_g = g;
      this->_b = b;
    }
    ~boule();
    void draw() const;
  protected:
    float _posX;
    float _posZ;
    float _taille;
    float _r;
    float _g;
    float _b;
};

class food : public boule{
  public:
    food():boule(0.1f,(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5,(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5,(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX)){}
};
