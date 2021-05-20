#include "joueurs.h"

// augmente la taille du joueurs et diminue sa vitesse
void joueurs::mangerf(food const & objet) {
  this->_taille+=0.005f;
  if(this->_vitesse>0.0201f)
    this->_vitesse-=0.0001f;
  else if (this->_vitesse>0.02f)
    this->_vitesse=0.02f;
}

// augmente la taille du joueurs et diminue sa vitesse en fonction de la taille du joueurs mangé
void joueurs::mangerj(joueurs const & objet){
  this->_taille+=(objet.getTaille()/4);
  if(this->_vitesse>0.0001f*objet.getTaille()*10)
    this->_vitesse-=0.0001f*objet.getTaille()*10;
  else this->_vitesse=0.02f;
}

// réinitialise la taille du joueurs et change sa position
void joueurs::SeFaireManger(){
  this->_posX=(float)rand()/(RAND_MAX)*(longueur-0.5+longueur-0.5)-longueur+0.5;
  this->_posZ=(float)rand()/(RAND_MAX)*(largeur-0.5+largeur-0.5)-largeur+0.5;
  this->_taille=0.5;
}
