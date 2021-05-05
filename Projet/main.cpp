#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "axes.h"
#include "actions.h"
#include "terrain.h"

GLfloat xrot_camera=0.0;
GLfloat yrot_camera=0.0;
GLfloat zrot_camera=0.0;

GLfloat x_objet=0.0;
GLfloat z_objet=0.0;

int xboules=0.0;
int zboules=0.0;

int window;

GLfloat z=-10.0f;

GLfloat x_cam=0.0f;
GLfloat y_cam=10.0f;
GLfloat z_cam=10.0f;

GLvoid Modelisation()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glTranslatef(0.0,0.0,z);
	gluLookAt(x_cam,y_cam,z_cam,x_objet,0.0f,z_objet,0.0,1.0,0.0);

	glRotatef(xrot_camera,1.0f,0.0f,0.0f);
	glRotatef(yrot_camera,0.0f,1.0f,0.0f);
	glRotatef(zrot_camera,0.0f,0.0f,1.0f);

	glColor3f(1.0,1.0,0.0);
	terrain t;

	glPushMatrix();
	{
		glColor3f(1.0,0.0,0.0);
		glRotatef(yrot_camera,0.0f,-1.0f,0.0f);
		glTranslatef(x_objet,0.0f,z_objet);
		glutSolidSphere(0.5,20,20);
	}
	glPopMatrix();
	glutSwapBuffers();
}

GLvoid Redimensionne(GLsizei Largeur, GLsizei Hauteur)
{
	glViewport(0, 0, Largeur, Hauteur);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,((float) Largeur)/((float) Hauteur), 1.0, 100.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Monstre");
	glutDisplayFunc(&Modelisation);
	glutReshapeFunc(&Redimensionne);

	glutKeyboardFunc(&touche_pressee);
  glutSpecialFunc(&touche_speciale_pressee);
	glutPassiveMotionFunc(souris);

	glutIdleFunc(&Modelisation);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();
}
