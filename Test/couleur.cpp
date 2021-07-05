#include "../Modele/couleur/couleur.hh"
#include "../Modele/couleur/couleur.cc"
#include "../Modele/generateur/g_couleur.hh"
#include "../Modele/generateur/g_couleur.cc"
#include "err.cc"

int main() {

  // Test basique :
  Couleur c(255,255,255);
  if(c.getR() != 255) throw TestError("Erreur de base sur les couleurs (r)");
  else log_noError("couleur","base",1,6);
  if(c.getG() != 255) throw TestError("Erreur de base sur les couleurs (g)");
  else log_noError("couleur","base",2,6);
  if(c.getB() != 255) throw TestError("Erreur de base sur les couleurs (b)");
  else log_noError("couleur","base",3,6);

  // Test sur le changement
  c.setB(122);
  if(static_cast<int>(c.getB()) != 122) throw TestError("Erreur sur la modification d'une couleur (b)");
  else log_noError("couleur","base",4,6);
  c.setG(32);
  if(static_cast<int>(c.getG()) !=  32) throw TestError("Erreur sur la modification d'une couleur (g)");
  else log_noError("couleur","base",5,6);
  c.setR(44);
  if(static_cast<int>(c.getR()) !=  44) throw TestError("Erreur sur la modification d'une couleur (r)");
  else log_noError("couleur","base",6,6);

  // Test sur des erreurs attendu
  try {
    Couleur a(333,0,4);
    throw TestError("Une erreur était attendu, mais n'a pas été déclenché ! (couleur, out_of_range, more)");
  } catch(std::out_of_range & e) {
    log_noError("couleur","avancé",1,4);
  }

  try {
    Couleur a(-5,0,4);
    throw TestError("Une erreur était attendu, mais n'a pas été déclenché ! (couleur, out_of_range, less)");
  } catch(std::out_of_range & e) {
    log_noError("couleur","avancé",2,4);
  }

  //Test sur les converions :
  Couleur x(3, 107, 252);
  if(x.toString_rgb() != "rgb(3,107,252)") { throw TestError("Erreur lors de la conversion en chaine de caractère d'une couleur au format RGB"); }
  else log_noError("couleur","avancé",3,4);
  if(x.toString_hex() != "#036bfc") { throw TestError("Erreur lors de la conversion en chaine de caractère d'une couleur au format HEX");}
  else log_noError("couleur","avancé",4,4);

  // Test sur des valeurs aléatoires :
  for(int i=0 ; i<10 ; i++) {
    Couleur r = CouleurRandom();
    log_noError("couleur","aléatoire",i+1,10);
  }

  return 0;
}
