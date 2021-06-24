#include <stdlib.h>      // Initialisation de la seed pour rand() avec srand()
#include <time.h>        // Pour générer une seed différente pour chaque itération de srand()
#include <unistd.h>      // Pour sleep(), pour ralentir l'éxécution


#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include "Controlleur/Partie.hh"

#include "Intelligence/Indila.hh"

extern GLvoid Modelisation();
extern GLvoid Redimensionne(GLsizei Largeur, GLsizei Hauteur);

int main(int argc,char* argv[]) {
	srand(time(nullptr));

/* non nécessaire pour l'instant
	std::vector<Joueur*> v;
	for(int i=0;i<4;i++) {
	v.push_back(new Indila());
	}

	Partie p(v,20,80);
	for(int i=0;i<20;i++) {
     	p.nextFrame();
		p.renduTerminal();
		sleep(1);
	}
*/

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
  return EXIT_SUCCESS;
}
