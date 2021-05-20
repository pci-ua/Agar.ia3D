#include "joueur.h"

extern joueur Player;

extern GLfloat x_cam;
extern GLfloat y_cam;
extern GLfloat z_cam;

// appelle la méthode de joueurs et augmente la position de la caméra
void joueur::mangerf(food const & objet) {
  joueurs::mangerf(objet);
	y_cam+=0.02f;
  z_cam+=0.02f;
}

// appelle la méthode de joueurs et augmente la position de la caméra en fonction de la taille du joueur mangé
void joueur::mangerj(joueurs const & objet) {
  joueurs::mangerj(objet);
	y_cam+=(objet.getTaille()/4);
  z_cam+=(objet.getTaille()/4);
}

// appelle la méthode de joueurs et réinitialise la position de la caméra sur la position du joueur
void joueur::SeFaireManger(){
  joueurs::SeFaireManger();
	x_cam=this->_posX;
	y_cam=7.0;
	z_cam=this->_posZ+5;
}

// récupère la position de la souris et la stock dans _posSourisX,_posSourisY
void souris (int x, int y){
	Player.setsourisX(x);
	Player.setsourisY(y);
}

void joueur::deplacement (){
  // récupère la taille de la fenêtre
	float width=glutGet(GLUT_WINDOW_WIDTH);
	float height=glutGet(GLUT_WINDOW_HEIGHT);
	float coeffdirecteur=0.0;
  // vérification pour ne pas avoir de division par 0 et calcul du coefficient directeur
	if(_posSourisX!=width/2){
		coeffdirecteur= (_posSourisY-height/2)/(_posSourisX-width/2);
	}
  // récupère l'angle en radian par rapport à l'axe des x et la position du curseur de la souris (stocké dans _posSourisX,_posSourisY grâ à la methode souris)
	float angle=atan(coeffdirecteur);
	//printf("angle: %f \n", angle);
  // l'angle est supérieur à 0 lorsque le curseur se trouve en haut à gauche ou en bas à droite
	if(angle>0){
    // si le curseur se trouve dans la partie gauche de l'écran (donc en haut à gauche) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille) && (Player.getZ()>-largeur+this->_taille)) {
      // change la position dans la direction du curseur avec la vitesse de l'ia et fait suivre la caméra
      Player.setX(Player.getX()-this->_vitesse*(cos(angle)));
			x_cam=x_cam-this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()-this->_vitesse*(sin(angle)));
			z_cam=z_cam-this->_vitesse*(sin(angle));
		}
    // si le curseur se trouve dans la partie droite de l'écran (donc en bas à droite) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille) && (Player.getZ()<largeur-this->_taille)){
			Player.setX(Player.getX()+this->_vitesse*(cos(angle)));
			x_cam=x_cam+this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()+this->_vitesse*(sin(angle)));
			z_cam=z_cam+this->_vitesse*(sin(angle));
		}
	}
  // l'angle est inférieur à 0 lorsque le curseur se trouve en haut à droite ou en bas à gauche
	if(angle<0){
    // si le curseur se trouve dans la partie gauche de l'écran (donc en bas à gauche) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille) && (Player.getZ()<largeur-this->_taille)) {
			Player.setX(Player.getX()-this->_vitesse*(cos(angle)));
			x_cam=x_cam-this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()-this->_vitesse*(sin(angle)));
			z_cam=z_cam-this->_vitesse*(sin(angle));
		}
    // si le curseur se trouve dans la partie droite de l'écran (donc en haut à droite) et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille) && (Player.getZ()>-largeur+this->_taille)){
			Player.setX(Player.getX()+this->_vitesse*(cos(angle)));
			x_cam=x_cam+this->_vitesse*(cos(angle));
			Player.setZ(Player.getZ()+this->_vitesse*(sin(angle)));
			z_cam=z_cam+this->_vitesse*(sin(angle));
		}
	}
	// lorsque la souris est dans l'axe vertical ou horizontal
	if(angle==0){
    // si le curseur se trouve dans l'axe horizontal à gauche et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille)){
			Player.setX(Player.getX()-this->_vitesse*(cos(angle)));
			x_cam=x_cam-this->_vitesse*(cos(angle));
		}
    // si le curseur se trouve dans l'axe horizontal à droite et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille)){
			Player.setX(Player.getX()+this->_vitesse*(cos(angle)));
			x_cam=x_cam+this->_vitesse*(cos(angle));
		}
    // si le curseur se trouve dans l'axe vertical en haut et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		else if((height/2>_posSourisY) && (Player.getZ()>-largeur+this->_taille)){
			Player.setZ(Player.getZ()-this->_vitesse*(cos(angle)));
			z_cam=z_cam-this->_vitesse*(cos(angle));
		}
    // si le curseur se trouve dans l'axe vertical en bas et qu'il ne va pas sortir du terrain si l'on va dans cette direction
		else if((height/2<_posSourisY) && (Player.getZ()<largeur-this->_taille)){
			Player.setZ(Player.getZ()+this->_vitesse*(cos(angle)));
			z_cam=z_cam+this->_vitesse*(cos(angle));
		}
	}
}
