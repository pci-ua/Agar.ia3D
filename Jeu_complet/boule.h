#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>


extern float longueur;
extern float largeur;

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
    void  setX(float x){this->_posX=x;}
    void  setZ(float z){this->_posZ=z;}
  protected:
    float _posX;
    float _posZ;
    float _taille;
    float _r;
    float _g;
    float _b;
};
