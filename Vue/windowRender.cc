#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "../constante.hh"
#include "../Controlleur/Partie.hh"
extern Partie* p;

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
	gluLookAt(
		// Caméra:
		0,100,0,
		// Cible
		0,0,0,
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
	glVertex3f(CARTE::LONGUEUR+1,1.0,CARTE::LARGEUR+1);
	glVertex3f(-CARTE::LONGUEUR-1,1.0,CARTE::LARGEUR+1);
	glVertex3f(-CARTE::LONGUEUR-1,1.0,-CARTE::LARGEUR-1);
	glVertex3f(CARTE::LONGUEUR+1,1.0,-CARTE::LARGEUR-1);
	glEnd();

	// Sphere

	for(auto participant=p->p_begin();participant != p->p_end();participant++) {
		auto pos = (*participant)->getPosition();
		auto color = (*participant)->getCouleur();
		auto taille = (*participant)->getTaille();
		glPushMatrix();
		glTranslatef((pos.getX()-CARTE::LONGUEUR/2)*2,0,(pos.getZ()-CARTE::LARGEUR/2)*2); //se positionne sur le terrain
		glColor3f(static_cast<float>(color.getR())/255,static_cast<float>(color.getG())/255,static_cast<float>(color.getB())/255);
		glutSolidSphere(taille*2,30,30); // créer une sphère
		glPopMatrix();
	}
	for(auto nourriture=p->n_begin();nourriture != p->n_end();nourriture++) {
		auto pos = (*nourriture)->getPosition();
		auto color = (*nourriture)->getCouleur();
		auto taille = (*nourriture)->getTaille();
		glPushMatrix();
		glTranslatef((pos.getX()-CARTE::LONGUEUR/2)*2,0,(pos.getZ()-CARTE::LARGEUR/2)*2); //se positionne sur le terrain
  		glColor3f(static_cast<float>(color.getR())/255,static_cast<float>(color.getG())/255,static_cast<float>(color.getB())/255);
  		glutSolidSphere(taille*2,30,30); // créer une sphère
  		glPopMatrix();
	}


	// Finition
	glutSwapBuffers();
}
