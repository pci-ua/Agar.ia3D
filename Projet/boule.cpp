#include "boule.h"

extern float longueur;
extern float largeur;

boule::~boule(){

}

void boule::draw() const{
 glPushMatrix();
 {
   glTranslatef(_posX,0,_posZ);
   glColor3f(_r,_g,_b);
   glutSolidSphere(_taille,50,50);
 }
 glPopMatrix();
}
