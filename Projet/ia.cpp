#include "ia.h"

extern ia iatest[];

extern float longueur;
extern float largeur;

void ia::deplacement (int i){
	int width=glutGet(GLUT_WINDOW_WIDTH);
	int height=glutGet(GLUT_WINDOW_HEIGHT);

  int x2=rand()%width;
  int y2=rand()%height;
  iatest[i].setiaX(x2);
  iatest[i].setiaY(y2);
	float coeffdirecteur=0.0;
	if(_posAleatoireX!=width/2){
		coeffdirecteur= (_posAleatoireY-height/2)/(_posAleatoireX-width/2);
	}
	//printf("Souris a: %d %d %f %f %f %f %f \n",_posSourisX,_posSourisY, x_objet,z_objet, coeffdirecteur, width, height);
	//float tangente=(coeffdirecteur-0.0)/(1.0+coeffdirecteur*0.0);

	float angle=atan(coeffdirecteur);
	//printf("angle: %f \n", angle);
	float test=cos(angle);
	float test2=sin(angle);
	//printf("angle: %f %f \n", test, test2);
	if(angle>0){
		if((width/2>_posAleatoireX) && (iatest[i].getX()>-longueur+this->_taille) && (iatest[i].getZ()>-largeur+this->_taille)) {
			iatest[i].setX(iatest[i].getX()-this->_vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()-this->_vitesse*(sin(angle)));
		}
		else if((width/2<_posAleatoireX) && (iatest[i].getX()<longueur-this->_taille) && (iatest[i].getZ()<largeur-this->_taille)){
			iatest[i].setX(iatest[i].getX()+this->_vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()+this->_vitesse*(sin(angle)));
		}
	}
	if(angle<0){
		if((width/2>_posAleatoireX) && (iatest[i].getX()>-longueur+this->_taille) && (iatest[i].getZ()<largeur-this->_taille)) {
			iatest[i].setX(iatest[i].getX()-this->_vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()-this->_vitesse*(sin(angle)));
		}
		else if((width/2<_posAleatoireX) && (iatest[i].getX()<longueur-this->_taille) && (iatest[i].getZ()>-largeur+this->_taille)){
			iatest[i].setX(iatest[i].getX()+this->_vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()+this->_vitesse*(sin(angle)));
		}
	}
	// lorsque la souris est dans l'axe vertical ou horizontal
	if(angle==0){
		if((width/2>_posAleatoireX) && (iatest[i].getX()>-longueur+this->_taille)){
			iatest[i].setX(iatest[i].getX()-this->_vitesse*(cos(angle)));
		}
		else if((width/2<_posAleatoireX) && (iatest[i].getX()<longueur-this->_taille)){
			iatest[i].setX(iatest[i].getX()+this->_vitesse*(cos(angle)));
		}
		else if((height/2>_posAleatoireY) && (iatest[i].getZ()>-largeur+this->_taille)){
			iatest[i].setZ(iatest[i].getZ()-this->_vitesse*(cos(angle)));
		}
		else if((height/2<_posAleatoireY) && (iatest[i].getZ()<largeur-this->_taille)){
			iatest[i].setZ(iatest[i].getZ()+this->_vitesse*(cos(angle)));
		}
	}
}
