#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "../constante.hh"

void Modelisation() {
	// Initialisation
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// Caméra
	gluLookAt(0,0.6,30,0,0,0,0,1,0);

	// Terrain
	glBegin(GL_QUADS);
	glColor3f(0.0,0.7,0.0);
	glVertex3f(CARTE::LONGUEUR,0.0,CARTE::LARGEUR);
	glVertex3f(-CARTE::LONGUEUR,0.0,CARTE::LARGEUR);
	glVertex3f(-CARTE::LONGUEUR,0.0,-CARTE::LARGEUR);
	glVertex3f(CARTE::LONGUEUR,0.0,-CARTE::LARGEUR);
	glEnd();

	// Sphere
	glPushMatrix();
	glTranslatef(4,0,-4); //se positionne sur le terrain
	glColor3f(1,0,0);
	glutSolidSphere(5,30,30); // créer une sphère
	glPopMatrix();

	// Finition
	glutSwapBuffers();
}
