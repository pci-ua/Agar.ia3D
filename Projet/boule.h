#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "constante.h"

// Super-classe de toutes les entitées
class boule{
  public:
    boule(float taille){
      // rand et RAND_MAX viennent de la bibliothèque stdlib.h
      // le calcul suivant correspond à prendre un nombre aléatoire (flottant) compris dans le terrain
      this->_posX = (float)rand()/(RAND_MAX)*(longueur-marge+longueur-marge)-longueur+marge;
      this->_posZ = (float)rand()/(RAND_MAX)*(largeur-marge+largeur-marge)-largeur+marge;
      this->_taille = taille;
      this->_r = couleur; // nombre flottant aléatoire entre 0 et 1
      this->_g = couleur;
      this->_b = couleur;
    }
    ~boule();
    void draw() const;
    float getX() const{ return _posX;}
    float getZ() const{ return _posZ;}
    float getTaille() const{return _taille;}
    void setX(float x){this->_posX=x;}
    void setZ(float z){this->_posZ=z;}
  protected:
    float _posX;
    float _posZ;
    float _taille;
    float _r;
    float _g;
    float _b;
};
