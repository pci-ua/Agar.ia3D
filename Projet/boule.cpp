#include "boule.h"

boule::~boule(){

}

//dessine la boule à un endroit
void boule::draw() const{
 glPushMatrix();
 {
   glTranslatef(_posX,0,_posZ); //se positionne sur le terrain
   glColor3f(_r,_g,_b);
   glutSolidSphere(_taille,50,50); // créer une sphère
 }
 glPopMatrix();
}
