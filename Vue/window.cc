
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

GLvoid Modelisation();
GLvoid Redimensionne(GLsizei Largeur, GLsizei Hauteur);

void InitialisationRendu(int argc,char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	int window = glutCreateWindow("Agar.ia");
	glutDisplayFunc(&Modelisation);
	glutReshapeFunc(&Redimensionne);

	glutIdleFunc(&Modelisation);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();

}
