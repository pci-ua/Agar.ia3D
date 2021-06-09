#include "ia.h"

extern Ia iatest[];

// déplacement de l'ia à la position i dans le tableau ia
void Ia::deplacement (int width,int height){
  // stock un nombre aléatoire entre 0 et la taille de la fenêtre
  int x2= (rand()%width) - width/2;
  int y2= (rand()%height) - height/2;
  // stocke les positions aléatoires dans des variables de la classe ia (_posAleatoireX,_posAleatoireY)
  this->setiaX(x2);
  this->setiaY(y2);

  float Magnitude = sqrt( pow( _posAleatoireX , 2 ) + pow( _posAleatoireY , 2 ) );
  if( Magnitude != 0 ) {
    //Vecteur unitaire de déplacement
    float vX = _vitesse * _posAleatoireX / Magnitude;
    float vZ = _vitesse * _posAleatoireY / Magnitude;

    //position à la prochaine frame
    float pX = this->getX() + vX;
    float pZ = this->getZ() + vZ;

    //si reste dans la bordure on bouge
    if(
      -LARGEUR + _taille <= pX && pX <= LARGEUR - _taille
      &&
      -LONGUEUR + _taille <= pZ && pZ <= LONGUEUR - _taille
    ) {
      this->setX( pX );
      this->setZ( pZ );
    }
  }
}
