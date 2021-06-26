#include "IPA.hh"

#include <cmath> // pour atan()
// Si jamais vous avez besoin de π :
#define PI 3.1415927

IPA::IPA()
  // Seul la couleur est nécessaire par défaut,
  // mais vous pouvez ajouter / modifier ce que vous voulez !
  :Joueur(Couleur(128,255,128)) {}

double IPA::deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) {
  // Ici l'idée est de tracker le joueur le plus proche et le plus petit s'il est plus petit sinon une nourriture
  // étape 1 : on cherche un joueur plus petit que nous et le plus proche possible
  InfoEntitee cible = joueurs[0]; // stock les infos de la cible
  bool cibleTrouver = false; // stock si on a au moin un joueur proche qui est plus petit que soit
  double distanceDuPlusProche;
  for(unsigned int i=0 ; i<joueurs.size() ; i++) {
     if(getTaille() < joueurs.at(i).taille) {
          double distance = (joueurs.at(i).position - getPosition()).getMagnitude();
          if( (!cibleTrouver) || (distance<distanceDuPlusProche) ) {
               cible = joueurs.at(i);
               cibleTrouver = true;
               distanceDuPlusProche = distance;
          }
     }
  }
  if(cibleTrouver){
     return angleVers(cible.position);
  } else {
       // étape 2 : s'il y a au moin une nourriture
     if(nourritures.size() >= 1) {
          return angleVers(nourritures[0].position);
     } else {
          return PI/4; // angle par défaut si on ne trouve personne
     }
  }
}

// Objectif : retourne l'angle pour allez de soit à une cible
double IPA::angleVers(Vect2D<double> position) {
     // étape 1 : déplacer l'origine (mathématiquement parlant) sur soit
     position -= getPosition();
     // étape 2 : SOH CAH TOA -> tan(θ) = opposé/adjacent -> θ = atan(opposé/adjacent) -> θ = atan(z/x)
     // ⚠ on fait une division et x peut être null !!! et heuresement arctan() est définie sur tout réel
     if(position.getX() == 0) {
          return PI/2;
     } else {
          return atan(position.getZ()/position.getX());
     }
}
