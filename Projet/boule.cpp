#include "boule.h"

extern GLfloat x_cam;
extern GLfloat y_cam;
extern GLfloat z_cam;

extern joueur Player;
extern ia iatest[];

extern float longueur;
extern float largeur;

boule::~boule(){

}

void boule::draw() const{
 glPushMatrix();
 {
   glTranslatef(_posX,0,_posZ);
   glColor3f(_r,_g,_b);
   glutSolidSphere(_taille,50,50);
 }
 glPopMatrix();
}

void boule::SeFaireManger() {
  this->_posX=(float)rand()/(RAND_MAX)*(longueur-0.5+longueur-0.5)-longueur+0.5;
  this->_posZ=(float)rand()/(RAND_MAX)*(largeur-0.5+largeur-0.5)-largeur+0.5;
}

void joueurs::manger() {
  this->_taille+=0.005f;
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
  float vitesse=0.1;
	//printf("angle: %f %f \n", test, test2);
	if(angle>0){
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille) && (Player.getZ()>-largeur+this->_taille)) {
			Player.setX(Player.getX()-vitesse*(cos(angle)));
			x_cam=x_cam-vitesse*(cos(angle));
			Player.setZ(Player.getZ()-vitesse*(sin(angle)));
			z_cam=z_cam-vitesse*(sin(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille) && (Player.getZ()<largeur-this->_taille)){
			Player.setX(Player.getX()+vitesse*(cos(angle)));
			x_cam=x_cam+vitesse*(cos(angle));
			Player.setZ(Player.getZ()+vitesse*(sin(angle)));
			z_cam=z_cam+vitesse*(sin(angle));
		}
	}
	if(angle<0){
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille) && (Player.getZ()<largeur-this->_taille)) {
			Player.setX(Player.getX()-vitesse*(cos(angle)));
			x_cam=x_cam-vitesse*(cos(angle));
			Player.setZ(Player.getZ()-vitesse*(sin(angle)));
			z_cam=z_cam-vitesse*(sin(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille) && (Player.getZ()>-largeur+this->_taille)){
			Player.setX(Player.getX()+vitesse*(cos(angle)));
			x_cam=x_cam+vitesse*(cos(angle));
			Player.setZ(Player.getZ()+vitesse*(sin(angle)));
			z_cam=z_cam+vitesse*(sin(angle));
		}
	}
	// lorsque la souris est dans l'axe vertical ou horizontal
	if(angle==0){
		if((width/2>_posSourisX) && (Player.getX()>-longueur+this->_taille)){
			Player.setX(Player.getX()-vitesse*(cos(angle)));
			x_cam=x_cam-vitesse*(cos(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<longueur-this->_taille)){
			Player.setX(Player.getX()+vitesse*(cos(angle)));
			x_cam=x_cam+vitesse*(cos(angle));
		}
		else if((height/2>_posSourisY) && (Player.getZ()>-largeur+this->_taille)){
			Player.setZ(Player.getZ()-vitesse*(cos(angle)));
			z_cam=z_cam-vitesse*(cos(angle));
		}
		else if((height/2<_posSourisY) && (Player.getZ()<largeur-this->_taille)){
			Player.setZ(Player.getZ()+vitesse*(cos(angle)));
			z_cam=z_cam+vitesse*(cos(angle));
		}
	}
}

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
  float vitesse=0.1;
	//printf("angle: %f %f \n", test, test2);
	if(angle>0){
		if((width/2>_posAleatoireX) && (iatest[i].getX()>-longueur+this->_taille) && (iatest[i].getZ()>-largeur+this->_taille)) {
			iatest[i].setX(iatest[i].getX()-vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()-vitesse*(sin(angle)));
		}
		else if((width/2<_posAleatoireX) && (iatest[i].getX()<longueur-this->_taille) && (iatest[i].getZ()<largeur-this->_taille)){
			iatest[i].setX(iatest[i].getX()+vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()+vitesse*(sin(angle)));
		}
	}
	if(angle<0){
		if((width/2>_posAleatoireX) && (iatest[i].getX()>-longueur+this->_taille) && (iatest[i].getZ()<largeur-this->_taille)) {
			iatest[i].setX(iatest[i].getX()-vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()-vitesse*(sin(angle)));
		}
		else if((width/2<_posAleatoireX) && (iatest[i].getX()<longueur-this->_taille) && (iatest[i].getZ()>-largeur+this->_taille)){
			iatest[i].setX(iatest[i].getX()+vitesse*(cos(angle)));
			iatest[i].setZ(iatest[i].getZ()+vitesse*(sin(angle)));
		}
	}
	// lorsque la souris est dans l'axe vertical ou horizontal
	if(angle==0){
		if((width/2>_posAleatoireX) && (iatest[i].getX()>-longueur+this->_taille)){
			iatest[i].setX(iatest[i].getX()-vitesse*(cos(angle)));
		}
		else if((width/2<_posAleatoireX) && (iatest[i].getX()<longueur-this->_taille)){
			iatest[i].setX(iatest[i].getX()+vitesse*(cos(angle)));
		}
		else if((height/2>_posAleatoireY) && (iatest[i].getZ()>-largeur+this->_taille)){
			iatest[i].setZ(iatest[i].getZ()-vitesse*(cos(angle)));
		}
		else if((height/2<_posAleatoireY) && (iatest[i].getZ()<largeur-this->_taille)){
			iatest[i].setZ(iatest[i].getZ()+vitesse*(cos(angle)));
		}
	}
}
