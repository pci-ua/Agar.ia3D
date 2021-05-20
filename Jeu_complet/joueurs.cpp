#include "joueurs.h"

void joueurs::mangerf(food objet) {
  this->_taille+=0.005f;
  if(this->_vitesse>0.0201f)
    this->_vitesse-=0.0001f;
  else if (this->_vitesse>0.02f)
    this->_vitesse=0.02f;
}

void joueurs::mangerj(joueurs objet){
  this->_taille+=(objet.getTaille()/4);
  if(this->_vitesse>0.0001f*objet.getTaille()*10)
    this->_vitesse-=0.0001f*objet.getTaille()*10;
  else this->_vitesse=0.02f;
}

void joueurs::SeFaireManger(){
  this->_posX=(float)rand()/(RAND_MAX)*(longueur-0.5+longueur-0.5)-longueur+0.5;
  this->_posZ=(float)rand()/(RAND_MAX)*(largeur-0.5+largeur-0.5)-largeur+0.5;
  this->_taille=0.5;
}
