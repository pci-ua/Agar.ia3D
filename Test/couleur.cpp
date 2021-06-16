#include "../Modele/couleur/couleur.hh"
#include "../Modele/couleur/couleur.cc"
#include "err.cc"

int main() {

  // Test basique :
  Couleur c(255,255,255);
  if(c.getR() != 255) throw TestError("Erreur de base sur les couleurs (r)");
  if(c.getG() != 255) throw TestError("Erreur de base sur les couleurs (g)");
  if(c.getB() != 255) throw TestError("Erreur de base sur les couleurs (b)");

  // Test sur le changement
  c.setB(122);
  if(static_cast<int>(c.getB()) != 122) throw TestError("Erreur sur la modification d'une couleur (b)");
  c.setG(32);
  if(static_cast<int>(c.getG()) !=  32) throw TestError("Erreur sur la modification d'une couleur (g)");
  c.setR(44);
  if(static_cast<int>(c.getR()) !=  44) throw TestError("Erreur sur la modification d'une couleur (r)");

  // Test sur des erreurs attendu
  try {
    Couleur a(333,0,4);
    throw TestError("Une erreur était attendu, mais n'a pas été déclenché ! (couleur, out_of_range, more)");
  } catch(std::out_of_range & e) {
    // Normal on continu
  }

  try {
    Couleur a(-5,0,4);
    throw TestError("Une erreur était attendu, mais n'a pas été déclenché ! (couleur, out_of_range, less)");
  } catch(std::out_of_range & e) {
    // Normal on continu
  }

  //Test sur les converions :
  Couleur x(3, 107, 252);
  if(x.toString_rgb() != "rgb(3,107,252)") { throw TestError("Erreur lors de la conversion en chaine de caractère d'une couleur au format RGB"); }
  if(x.toString_hex() != "#036bfc") { throw TestError("Erreur lors de la conversion en chaine de caractère d'une couleur au format HEX");}




  return 0;
}
