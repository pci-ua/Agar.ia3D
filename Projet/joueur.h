#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "joueurs.h"

class joueur : public joueurs{
  public:
    joueur(int posX, int posY):joueurs(){
  			this->_posSourisX=posX;
  			this->_posSourisY=posY;
  	}
  	void setsourisX(int x){this->_posSourisX=x;}
  	void setsourisY(int y){this->_posSourisY=y;}
    void deplacement();
    void mangerf(food const & objet);
    void mangerj(joueurs const & objet);
    void SeFaireManger();
  private:
    int _posSourisX;
    int _posSourisY;
};

void souris(int x, int y);
