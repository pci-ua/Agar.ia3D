#ifndef __ACTIONS
#define __ACTIONS

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ESCAPE 27
#define ESPACE 32

#define PI 3.14159265

#define OBJET 1
#define CAMERA 2

class Joueur{
	public :
		Joueur(int posX, int posY) {
			this->_posSourisX=posX;
			this->_posSourisY=posY;
		}
		void const setX(int x){this->_posSourisX=x;}
		void const setY(int y){this->_posSourisY=y;}
    void deplacement();

	private:
		int _posSourisX;
		int _posSourisY;
};

void touche_pressee(unsigned char key, int x, int y);
void touche_speciale_pressee(int key, int x, int y);
void souris(int x, int y);

#endif
