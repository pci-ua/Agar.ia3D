#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#define PI 3.14159265

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
    float getX(){ return _posX;}
    float getZ(){ return _posZ;}
    float getTaille() { return _taille;}
    void const setX(float x){this->_posX=x;}
    void const setZ(float z){this->_posZ=z;}
    void manger();
};

class joueur : public joueurs{
  public:
    joueur(int posX, int posY):joueurs(0.5f){
  			this->_posSourisX=posX;
  			this->_posSourisY=posY;
  	}
  	void const setsourisX(int x){this->_posSourisX=x;}
  	void const setsourisY(int y){this->_posSourisY=y;}
    void deplacement();

  private:
    int _posSourisX;
    int _posSourisY;
};

void souris(int x, int y);

class ia : public joueurs {
public:
  ia():joueurs(0.5f){}
  void const setiaX(int x){this->_posAleatoireX=x;}
  void const setiaY(int y){this->_posAleatoireY=y;}
  void deplacement(int i);

private:
  int _posAleatoireX;
  int _posAleatoireY;
};
