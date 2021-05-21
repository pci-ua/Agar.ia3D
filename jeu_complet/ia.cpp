#include "ia.h"

extern Ia iatest[];

// déplacement de l'ia à la position i dans le tableau ia
void Ia::deplacement (int width,int height){
  // stock un nombre aléatoire entre 0 et la taille de la fenêtre
  int x2=rand()%width;
  int y2=rand()%height;
  // stocke les positions aléatoires dans des variables de la classe ia (_posAleatoireX,_posAleatoireY)
  this->setiaX(x2);
  this->setiaY(y2);
  float coeffdirecteur=0.0;
  // vérification pour ne pas avoir de division par 0 et calcul du coefficient directeur
  if(_posAleatoireX!=width/2){
      coeffdirecteur= (_posAleatoireY-height/2)/(_posAleatoireX-width/2);
  }
  // récupère l'angle en radian par rapport à l'axe des x et la position du "curseur"(non visible mais imaginé par _posAleatoireX,_posAleatoireY) de l'ia
  float angle=atan(coeffdirecteur);
  // l'angle est supérieur à 0 lorsque le "curseur" se trouve en haut à gauche ou en bas à droite
  if(angle>0){
    // si le "curseur" se trouve dans la partie gauche de l'écran (donc en haut à gauche) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    if((width/2>_posAleatoireX) && (this->getX()>-LONGUEUR+this->_taille) && (this->getZ()>-LARGEUR+this->_taille)) {
      // change la position dans la direction du "curseur" avec la vitesse de l'ia
      this->setX(this->getX()-this->_vitesse*(cos(angle)));
      this->setZ(this->getZ()-this->_vitesse*(sin(angle)));
    }
    // si le "curseur" se trouve dans la partie droite de l'écran (donc en bas à droite) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    else if((width/2<_posAleatoireX) && (this->getX()<LONGUEUR-this->_taille) && (this->getZ()<LARGEUR-this->_taille)){
      this->setX(this->getX()+this->_vitesse*(cos(angle)));
      this->setZ(this->getZ()+this->_vitesse*(sin(angle)));
    }
  }
  // l'angle est inférieur à 0 lorsque le "curseur" se trouve en haut à droite ou en bas à gauche
  if(angle<0){
    // si le "curseur" se trouve dans la partie gauche de l'écran (donc en bas à gauche) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    if((width/2>_posAleatoireX) && (this->getX()>-LONGUEUR+this->_taille) && (this->getZ()<LARGEUR-this->_taille)) {
      this->setX(this->getX()-this->_vitesse*(cos(angle)));
      this->setZ(this->getZ()-this->_vitesse*(sin(angle)));
    }
    // si le "curseur" se trouve dans la partie droite de l'écran (donc en haut à droite) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    else if((width/2<_posAleatoireX) && (this->getX()<LONGUEUR-this->_taille) && (this->getZ()>-LARGEUR+this->_taille)){
      this->setX(this->getX()+this->_vitesse*(cos(angle)));
      this->setZ(this->getZ()+this->_vitesse*(sin(angle)));
    }
  }
  // lorsque la souris est dans l'axe vertical ou horizontal
  if(angle==0){
    // si le "curseur" se trouve dans l'axe horizontal à gauche et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    if((width/2>_posAleatoireX) && (this->getX()>-LONGUEUR+this->_taille)){
      this->setX(this->getX()-this->_vitesse*(cos(angle)));
    }
    // si le "curseur" se trouve dans l'axe horizontal à droite et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    else if((width/2<_posAleatoireX) && (this->getX()<LONGUEUR-this->_taille)){
      this->setX(this->getX()+this->_vitesse*(cos(angle)));
    }
    // si le "curseur" se trouve dans l'axe vertical en haut et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    else if((height/2>_posAleatoireY) && (this->getZ()>-LARGEUR+this->_taille)){
      this->setZ(this->getZ()-this->_vitesse*(cos(angle)));
    }
    // si le "curseur" se trouve dans l'axe vertical en bas et qu'il ne va pas sortir du terrain si l'on va dans cette direction
    else if((height/2<_posAleatoireY) && (this->getZ()<LARGEUR-this->_taille)){
      this->setZ(this->getZ()+this->_vitesse*(cos(angle)));
    }
  }
}
