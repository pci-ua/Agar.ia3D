#include "boule.h"

boule::~boule(){

}

//dessine la boule à un endroit
void boule::draw() const{
 glPushMatrix();
 {
   glTranslatef(_posX,0,_posZ); //se positionne sur le terrain
   glColor3f(_r,_g,_b);
   glutSolidSphere(_taille,subdivisions_boule,subdivisions_boule); // créer une sphère
 }
 glPopMatrix();
}
