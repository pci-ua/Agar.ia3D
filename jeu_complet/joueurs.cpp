#include "joueurs.h"

// augmente la taille du joueurs et diminue sa vitesse
void Joueurs::mangerf(Food const & objet) {
  this->_taille+=(MODIF_TAILLE/(this->_taille));
  if(this->_vitesse>PALLIER_VITESSE)
    this->_vitesse-=MODIF_VITESSE;
  else if (this->_vitesse>VITESSE_MIN)
    this->_vitesse=VITESSE_MIN;
}

// augmente la taille du joueurs et diminue sa vitesse en fonction de la taille du joueurs mangé
void Joueurs::mangerj(Joueurs const & objet){
  this->_taille+=((objet.getTaille()*POURCENTAGE_MANGE)/(this->_taille));
  if(this->_vitesse>MODIF_VITESSE*objet.getTaille()*10)
    this->_vitesse-=MODIF_VITESSE*objet.getTaille()*10;
  else this->_vitesse=VITESSE_MIN;
}

// réinitialise la taille, la vitesse du joueurs et change sa position
void Joueurs::SeFaireManger(){
  this->_posX=(float)rand()/(RAND_MAX)*(LONGUEUR-MARGE+LONGUEUR-MARGE)-LONGUEUR+MARGE;
  this->_posZ=(float)rand()/(RAND_MAX)*(LARGEUR-MARGE+LARGEUR-MARGE)-LARGEUR+MARGE;
  this->_taille=TAILLE_JOUEURS;
  this->_vitesse=VITESSE;
}
