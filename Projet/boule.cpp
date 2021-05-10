#include "boule.h"


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

void boule::SeFaireManger() {
  this->_posX=(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5;
  this->_posZ=(float)rand()/(RAND_MAX)*(9.5+9.5)-9.5;
}

void joueurs::manger() {
  this->_taille+=0.01f;
}
