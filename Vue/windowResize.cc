#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

GLvoid Redimensionne(GLsizei Largeur, GLsizei Hauteur)
{
	glViewport(0, 0, Largeur, Hauteur);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,1, 1.0, 100.0);
}
