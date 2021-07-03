#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "../constante.hh"
#include "../Controlleur/Partie.hh"
extern Partie* p;
#include <iostream>
bool fini = false;
void Modelisation() {
	// Update entitée
	if( ! fini ) {
		try {
			p->nextFrame();
		} catch(char const* e) {
			fini = true;
		}
	}

	// Initialisation du rendu
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Positionnement de la Caméra
	auto posCam = (*p->p_begin())->getPosition();
	gluLookAt(
		// Caméra:
		posCam.getX()-15,45,posCam.getZ(),
		// Cible
		posCam.getX(),0,posCam.getZ(),
		// Orientation
		0.1,1,0
	);

	// Terrain
    	glLineWidth(3);
	if(fini) {
		glColor3f(0.83,1.0,1.0);
	} else {
		glColor3f(0.2,1.0,0.0);
	}
	glBegin(GL_LINE_LOOP);
	glVertex3f(CARTE::LONGUEUR,0.0,CARTE::LARGEUR);
	glVertex3f(-CARTE::LONGUEUR,0.0,CARTE::LARGEUR);
	glVertex3f(-CARTE::LONGUEUR,0.0,-CARTE::LARGEUR);
	glVertex3f(CARTE::LONGUEUR,0.0,-CARTE::LARGEUR);
	glEnd();

	// Sphere
	for(auto participant=p->p_begin();participant != p->p_end();participant++) {
		(*participant)->draw();
	}
	for(auto nourriture=p->n_begin();nourriture != p->n_end();nourriture++) {
		(*nourriture)->draw();
	}


	// Finition

    glLineWidth(3);
        glColor3f(0.7,0.0,0.0);
        glBegin(GL_LINES);
        glVertex3f(00.0,01.0,00.0);
        glVertex3f(15.0,01.0,00.0);
        glEnd();
            glColor3f(0.0,0.7,0.0);
            glBegin(GL_LINES);
            glVertex3f(00.0,01.0,00.0);
            glVertex3f(00.0,15.0,00.0);
            glEnd();
                glColor3f(0.0,0.0,0.7);
                glBegin(GL_LINES);
                glVertex3f(00.0,01.0,00.0);
                glVertex3f(00.0,01.0,15.0);
                glEnd();

	glutSwapBuffers();
}
