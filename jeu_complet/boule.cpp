#include "boule.hh"

Boule::~Boule(){

}

//dessine la boule à un endroit
void Boule::draw() const{
 glPushMatrix();
 {
   glTranslatef(_posX,0,_posZ); //se positionne sur le terrain
   glColor3f(_r,_g,_b);
   glutSolidSphere(static_cast<double>(_taille),SUBDIVISIONS_BOULE,SUBDIVISIONS_BOULE); // créer une sphère
 }
 glPopMatrix();
}
