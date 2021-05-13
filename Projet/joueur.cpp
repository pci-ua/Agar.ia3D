#include "joueur.h"

extern joueur Player;

extern GLfloat x_cam;
extern GLfloat y_cam;
extern GLfloat z_cam;

extern float longueur;
extern float largeur;

/*void joueur::mangerj() {
  this->_taille+=0.005f;
  //diminutionvitesse();
  y_cam+=0.01f;
  z_cam+=0.01f;
}*/


void joueur::SeFaireManger(){
  joueurs::SeFaireManger();
  y_cam=10.0f;
  z_cam=10.0f;
}


void souris (int x, int y){
	Player.setsourisX(x);
	Player.setsourisY(y);
}

void joueur::deplacement (){
	float width=glutGet(GLUT_WINDOW_WIDTH);
	float height=glutGet(GLUT_WINDOW_HEIGHT);
	float coeffdirecteur=0.0;
	if(_posSourisX!=width/2){
		coeffdirecteur= (_posSourisY-height/2)/(_posSourisX-width/2);
	}
	//printf("Souris a: %d %d %f %f %f %f %f \n",_posSourisX,_posSourisY, x_objet,z_objet, coeffdirecteur, width, height);
	//float tangente=(coeffdirecteur-0.0)/(1.0+coeffdirecteur*0.0);

	float angle=atan(coeffdirecteur);
	//printf("angle: %f \n", angle);
	float test=cos(angle);
	float test2=sin(angle);
	//printf("angle: %f %f \n", test, test2);
	if(angle>0){
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille) && (Player.getZ()>-largeur+this->_taille)) {
			Player.setX(Player.getX()-this->_vitesse*(cos(angle)));
			x_cam=x_cam-this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()-this->_vitesse*(sin(angle)));
			z_cam=z_cam-this->_vitesse*(sin(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille) && (Player.getZ()<largeur-this->_taille)){
			Player.setX(Player.getX()+this->_vitesse*(cos(angle)));
			x_cam=x_cam+this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()+this->_vitesse*(sin(angle)));
			z_cam=z_cam+this->_vitesse*(sin(angle));
		}
	}
	if(angle<0){
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille) && (Player.getZ()<largeur-this->_taille)) {
			Player.setX(Player.getX()-this->_vitesse*(cos(angle)));
			x_cam=x_cam-this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()-this->_vitesse*(sin(angle)));
			z_cam=z_cam-this->_vitesse*(sin(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille) && (Player.getZ()>-largeur+this->_taille)){
			Player.setX(Player.getX()+this->_vitesse*(cos(angle)));
			x_cam=x_cam+this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()+this->_vitesse*(sin(angle)));
			z_cam=z_cam+this->_vitesse*(sin(angle));
		}
	}
	// lorsque la souris est dans l'axe vertical ou horizontal
	if(angle==0){
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille)){
			Player.setX(Player.getX()-this->_vitesse*(cos(angle)));
			x_cam=x_cam-this->_vitesse*(cos(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille)){
			Player.setX(Player.getX()+this->_vitesse*(cos(angle)));
			x_cam=x_cam+this->_vitesse*(cos(angle));
		}
		else if((height/2>_posSourisY) && (Player.getZ()>-largeur+this->_taille)){
			Player.setZ(Player.getZ()-this->_vitesse*(cos(angle)));
			z_cam=z_cam-this->_vitesse*(cos(angle));
		}
		else if((height/2<_posSourisY) && (Player.getZ()<largeur-this->_taille)){
			Player.setZ(Player.getZ()+this->_vitesse*(cos(angle)));
			z_cam=z_cam+this->_vitesse*(cos(angle));
		}
	}
}
