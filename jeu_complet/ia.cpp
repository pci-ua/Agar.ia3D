#include "ia.hh"

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
    float vX = _vitesse * ((float)(_posAleatoireX)) / Magnitude;
    float vZ = _vitesse * ((float)(_posAleatoireY)) / Magnitude;

    //position à la prochaine frame
    float pX = _position.getX() + vX;
    float pZ = _position.getZ() + vZ;

    //si reste dans la bordure on bouge
    if(
      -TERRAIN::LARGEUR + _taille <= pX && pX <= TERRAIN::LARGEUR - _taille
      &&
      -TERRAIN::LONGUEUR + _taille <= pZ && pZ <= TERRAIN::LONGUEUR - _taille
    ) {
      _position.setX( pX );
      _position.setZ( pZ );
    }
  }
}
