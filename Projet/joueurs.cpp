#include "joueurs.h"

// augmente la taille du joueurs et diminue sa vitesse
void joueurs::mangerf(food const & objet) {
  this->_taille+=modif_taille;
  if(this->_vitesse>pallier_vitesse)
    this->_vitesse-=modif_vitesse;
  else if (this->_vitesse>vitesse_min)
    this->_vitesse=vitesse_min;
}

// augmente la taille du joueurs et diminue sa vitesse en fonction de la taille du joueurs mangé
void joueurs::mangerj(joueurs const & objet){
  this->_taille+=(objet.getTaille()*pourcentage_mange);
  if(this->_vitesse>modif_vitesse*objet.getTaille()*10)
    this->_vitesse-=modif_vitesse*objet.getTaille()*10;
  else this->_vitesse=vitesse_min;
}

// réinitialise la taille du joueurs et change sa position
void joueurs::SeFaireManger(){
  this->_posX=(float)rand()/(RAND_MAX)*(longueur-marge+longueur-marge)-longueur+marge;
  this->_posZ=(float)rand()/(RAND_MAX)*(largeur-marge+largeur-marge)-largeur+marge;
  this->_taille=taille_joueurs;
  this->_vitesse=vitesse;
}
