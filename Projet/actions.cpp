#include "actions.h"
#include <stdio.h>


extern GLfloat xrot_camera;
extern GLfloat yrot_camera;

extern GLfloat xrot_objet;
extern GLfloat yrot_objet;
extern GLfloat zrot_objet;

extern GLfloat x_objet;
extern GLfloat z_objet;

extern GLfloat x_cam;
extern GLfloat y_cam;
extern GLfloat z_cam;

extern GLfloat z;

void touche_pressee(unsigned char key, int x, int y)
{
	usleep(100);

	switch (key) {
	case ESCAPE:
		exit(1);
		break;
	case 'z':
		if(z_objet>-10){
			z_objet=z_objet-0.1;
			z_cam=z_cam-0.1;
		}
		break;
	case 's':
		if(z_objet<10){
			z_objet=z_objet+0.1;
			z_cam=z_cam+0.1;
		}
		break;
	case 'q':
		if(x_objet>-10){
			x_objet=x_objet-0.1;
			x_cam=x_cam-0.1;
		}
		break;
	case 'd':
		if(x_objet<10){
			x_objet=x_objet+0.1;
			x_cam=x_cam+0.1;
		}
		break;
	}

}
void touche_speciale_pressee(int key, int x, int y)
{

	usleep(100);

	switch (key) {
	case GLUT_KEY_UP:
		xrot_camera +=5.0f;
	break;

	case GLUT_KEY_DOWN:
		xrot_camera -=5.0f;
	break;

	case GLUT_KEY_LEFT:
		yrot_camera -=2.0f;
	break;

	case GLUT_KEY_RIGHT:
		yrot_camera +=2.0f;
	break;

	default:
	break;
	}
}
