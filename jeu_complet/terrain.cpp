#include "terrain.hh"

terrain::terrain(float longueur, float largeur)
{
  //sol
  glBegin(GL_QUADS);
  glTexCoord2f(6.0,6.0);
  glVertex3f(longueur,0.0,largeur);
  glTexCoord2f(6.0,0.0);
  glVertex3f(-longueur,0.0,largeur);
  glTexCoord2f(0.0,0.0);
  glVertex3f(-longueur,0.0,-largeur);
  glTexCoord2f(0.0,6.0);
  glVertex3f(longueur,0.0,-largeur);
  glEnd();
  
}
