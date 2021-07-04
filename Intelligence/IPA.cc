#include "IPA.hh"

#include <iostream>

#include <cmath>         // pour : atan(), π
#include <cstdlib>       // pour : rand()

#include "../constante.hh"


// Si jamais vous avez besoin de π :
#define PI M_PI

IPA::IPA()
  // Seul la couleur est nécessaire par défaut,
  // mais vous pouvez ajouter / modifier ce que vous voulez !
  :Joueur(Couleur(128,255,128)),ite(0),dir(PI/4) {}

double IPA::deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) {
// Ici l'idée est de tracker le joueur le plus proche et le plus petit s'il est plus petit sinon une nourriture

     // étape 1 :
     //  Si on s'approche trop d'une bordure de la carte : on souhaite se rediriger vers le centre de la carte
     /*if(
          getPosition().getX() > CARTE::LONGUEUR ||
          getPosition().getX() < 0 ||
          getPosition().getZ() > CARTE::LARGEUR ||
          getPosition().getZ() < 0
     ) {
          // Affichage pour vérification :
          std::cout << "Redirection centre : ";
          std::cout << "{" << getPosition().getX() << ";" << getPosition().getZ() << "}" ;

          auto debuff = angleVers({CARTE::LONGUEUR/2,CARTE::LARGEUR/2});
          std::cout << debuff << std::endl;
          return debuff + PI;
     }*/

     // étape 2 :
     //  On cherche un joueur plus petit que nous et le plus proche possible
     if(joueurs.size() >= 1) {
          InfoEntitee cible = joueurs[0]; // stock les infos de la cible
          bool cibleTrouver = false; // stock si on a au moin un joueur proche qui est plus petit que soit
          double distanceDuPlusProche;
          for(unsigned int i=0 ; i<joueurs.size() ; i++) {
               if(getTaille() > joueurs.at(i).taille) {
                    double distance = (joueurs.at(i).position - getPosition()).getMagnitude();
                    if( (!cibleTrouver) || (distance<distanceDuPlusProche) ) {
                         cible = joueurs.at(i);
                         cibleTrouver = true;
                         distanceDuPlusProche = distance;
                    }
               }
          }

          if(cibleTrouver) {
               return angleVers(cible.position);
          }
     }

     // étape 3 :
     //  s'il y a au moin une nourriture
     if(nourritures.size() >= 1) {
       bool cibleTrouvern = false; // stock si on a au moin un joueur proche qui est plus petit que soit
       InfoEntitee ciblen = nourritures[0];
       double distanceDuPlusProchen;
       for(unsigned int i=0 ; i<nourritures.size() ; i++) {
          double distancen = (nourritures.at(i).position - getPosition()).getMagnitude();
          if( (!cibleTrouvern) || (distancen<distanceDuPlusProchen) ) {
                    ciblen = nourritures.at(i);
                    cibleTrouvern = true;
                    distanceDuPlusProchen = distancen;
               }
          }
          if(cibleTrouvern) {
               return angleVers(ciblen.position);
          }

    }
    if(ite >= 30) {
         ite = 0;
         dir = static_cast<double>(rand())*((2*PI)/RAND_MAX);
    }ite++;
              return dir; // angle par défaut si on ne trouve personne

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
          return PI + atan(position.getZ()/position.getX());
     }
}
