#pragma once
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
    float getX(){ return _posX;}
    float getZ(){ return _posZ;}
    float getTaille(){return _taille;}
    void const setX(float x){this->_posX=x;}
    void const setZ(float z){this->_posZ=z;}
    void SeFaireManger();
  protected:
    float _posX;
    float _posZ;
    float _taille;
    float _r;
    float _g;
    float _b;
};

class joueurs : public boule{
  public:
    joueurs(float _tailleJ):boule(_tailleJ,(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5,(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5,(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX),(float)rand()/(RAND_MAX)){}
    ~joueurs(){}
    void manger();
};

class joueur : public joueurs{
  public:
    joueur():joueurs(0.5f){}
};
