#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "joueurs.hh"

class Joueur : public Joueurs{
  public:
    Joueur(int posX, int posY):Joueurs(){
  			this->_posSourisX=posX;
  			this->_posSourisY=posY;
  	}
  	void setsourisX(int x){this->_posSourisX=x;}
  	void setsourisY(int y){this->_posSourisY=y;}
    void deplacement(int width,int height);
    void mangerf(Food const & objet);
    void mangerj(Joueurs const & objet);
    void SeFaireManger();
  private:
    int _posSourisX;
    int _posSourisY;
};

void souris(int x, int y);
