#include "terrain.h"

terrain::terrain()
{
  //sol
  glBegin(GL_QUADS);
  glVertex3f(10.0,0.0,10.0);
  glVertex3f(-10.0,0.0,10.0);
  glVertex3f(-10.0,0.0,-10.0);
  glVertex3f(10.0,0.0,-10.0);
  glEnd();

  // mur avant
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(10.0,0.0,10.0);
  glVertex3f(-10.0,0.0,10.0);
  glVertex3f(-10.0,2.5,10.0);
  glVertex3f(10.0,2.5,10.0);
  glEnd();

  //mur arrière
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(10.0,0.0,-10.0);
  glVertex3f(-10.0,0.0,-10.0);
  glVertex3f(-10.0,2.5,-10.0);
  glVertex3f(10.0,2.5,-10.0);
  glEnd();

  //mur droit
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(10.0,0.0,-10.0);
  glVertex3f(10.0,0.0,10.0);
  glVertex3f(10.0,2.5,10.0);
  glVertex3f(10.0,2.5,-10.0);
  glEnd();

  //mur gauche
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(-10.0,0.0,-10.0);
  glVertex3f(-10.0,0.0,10.0);
  glVertex3f(-10.0,2.5,10.0);
  glVertex3f(-10.0,2.5,-10.0);
  glEnd();
}
