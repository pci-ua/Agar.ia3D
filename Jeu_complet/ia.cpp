#include "ia.h"

extern ia iatest[];

extern float longueur;
extern float largeur;

void ia::deplacement (int width,int height){


  int x2=rand()%width;
  int y2=rand()%height;
  this->setiaX(x2);
  this->setiaY(y2);
    float coeffdirecteur=0.0;
    if(_posAleatoireX!=width/2){
        coeffdirecteur= (_posAleatoireY-height/2)/(_posAleatoireX-width/2);
    }


    float angle=atan(coeffdirecteur);
       if(angle>0){
        if((width/2>_posAleatoireX) && (this->getX()>-longueur+this->_taille) && (this->getZ()>-largeur+this->_taille)) {
            this->setX(this->getX()-this->_vitesse*(cos(angle)));
            this->setZ(this->getZ()-this->_vitesse*(sin(angle)));
        }
        else if((width/2<_posAleatoireX) && (this->getX()<longueur-this->_taille) && (this->getZ()<largeur-this->_taille)){
            this->setX(this->getX()+this->_vitesse*(cos(angle)));
            this->setZ(this->getZ()+this->_vitesse*(sin(angle)));
        }
    }
    if(angle<0){
        if((width/2>_posAleatoireX) && (this->getX()>-longueur+this->_taille) && (this->getZ()<largeur-this->_taille)) {
            this->setX(this->getX()-this->_vitesse*(cos(angle)));
            this->setZ(this->getZ()-this->_vitesse*(sin(angle)));
        }
        else if((width/2<_posAleatoireX) && (this->getX()<longueur-this->_taille) && (this->getZ()>-largeur+this->_taille)){
            this->setX(this->getX()+this->_vitesse*(cos(angle)));
            this->setZ(this->getZ()+this->_vitesse*(sin(angle)));
        }
    }
    // lorsque la souris est dans l'axe vertical ou horizontal
    if(angle==0){
        if((width/2>_posAleatoireX) && (this->getX()>-longueur+this->_taille)){
            this->setX(this->getX()-this->_vitesse*(cos(angle)));
        }
        else if((width/2<_posAleatoireX) && (this->getX()<longueur-this->_taille)){
            this->setX(this->getX()+this->_vitesse*(cos(angle)));
        }
        else if((height/2>_posAleatoireY) && (this->getZ()>-largeur+this->_taille)){
            this->setZ(this->getZ()-this->_vitesse*(cos(angle)));
        }
        else if((height/2<_posAleatoireY) && (this->getZ()<largeur-this->_taille)){
            this->setZ(this->getZ()+this->_vitesse*(cos(angle)));
        }
    }
}

