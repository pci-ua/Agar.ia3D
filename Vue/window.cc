
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

GLvoid Modelisation();
GLvoid Redimensionne(GLsizei Largeur, GLsizei Hauteur);

extern void updateManuallyHandled(int x,int y,int w,int h);

void gestionSouris(int x,int y) {
	updateManuallyHandled(x,y,900,900);
}

void InitialisationRendu(int argc,char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE , GLUT_ACTION_CONTINUE_EXECUTION );

	glutInitWindowSize(900,900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Agar.ia");
	glutDisplayFunc(&Modelisation);
	glutReshapeFunc(&Redimensionne);

	glutIdleFunc(&Modelisation);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutPassiveMotionFunc(gestionSouris);

	glutSetIconTitle("./Menu/ressource/icon.ico");

	glutMainLoop();

}
