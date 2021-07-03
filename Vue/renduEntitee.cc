#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include "../constante.hh"

#include "../Modele/entitee/nourriture.hh"

void Nourriture::draw() {
     glColor3f(
          static_cast<float>(getCouleur().getR())/255,
          static_cast<float>(getCouleur().getG())/255,
          static_cast<float>(getCouleur().getB())/255
     );
     glPushMatrix();
     glTranslatef(getPosition().getX(),0,getPosition().getZ());
     glutSolidSphere(getTaille()*2,NOURRITURE::QUALITE,NOURRITURE::QUALITE);
     glPopMatrix();
}

#include "../Modele/entitee/joueur.hh"

void Joueur::draw() {
     glColor3f(
          static_cast<float>(getCouleur().getR())/255,
          static_cast<float>(getCouleur().getG())/255,
          static_cast<float>(getCouleur().getB())/255
     );
     glPushMatrix();
     glTranslatef(getPosition().getX(),0,getPosition().getZ());
     glutSolidSphere(getTaille()*2,JOUEUR::QUALITE,JOUEUR::QUALITE);
     glPopMatrix();
}
