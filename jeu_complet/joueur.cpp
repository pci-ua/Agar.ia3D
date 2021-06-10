#include "joueur.hh"

extern Joueur player;

extern GLfloat x_cam;
extern GLfloat y_cam;
extern GLfloat z_cam;

// appelle la méthode de joueurs et augmente la position de la caméra
void Joueur::mangerf(Food const & objet) {
  Joueurs::mangerf(objet);
	y_cam+=CAMERA_UP;
  z_cam+=CAMERA_UP;
}

// appelle la méthode de joueurs et augmente la position de la caméra en fonction de la taille du joueur mangé
void Joueur::mangerj(Joueurs const & objet) {
  Joueurs::mangerj(objet);
    y_cam+=(objet.getTaille()*POURCENTAGE_MANGE);
  z_cam+=(objet.getTaille()*POURCENTAGE_MANGE);
}

// appelle la méthode de joueurs et réinitialise la position de la caméra sur la position du joueur
void Joueur::SeFaireManger(){
  Joueurs::SeFaireManger();
	x_cam=this->_posX;
	y_cam=7.0;
    z_cam=this->_posZ+5;
}

// récupère la position de la souris et la stock dans _posSourisX,_posSourisY
void souris (int x, int y){
	player.setsourisX(x);
	player.setsourisY(y);
}


void Joueur::deplacement (int width,int height){
  float sourisCenterX = _posSourisX - width/2 ;
  float sourisCenterY = _posSourisY - height/2;
  float Magnitude = sqrt( pow( sourisCenterX , 2 ) + pow( sourisCenterY , 2 ) );
  if( Magnitude != 0 ) {
    //Vecteur unitaire de déplacement
    float vX = _vitesse * sourisCenterX / Magnitude;
    float vZ = _vitesse * sourisCenterY / Magnitude;

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
      x_cam += vX;
      z_cam += vZ;
    }
  }
}

