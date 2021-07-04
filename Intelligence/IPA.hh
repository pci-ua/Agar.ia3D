#pragma once

// Nécessaire pour s'incruster dans le jeu !
#include "../Modele/entitee/joueur.hh"

/* 🍺🍺🍺
India Pale Ale
🍺🍺🍺 */

class IPA // N'hésitez pas à renommer votre IA !
  :public Joueur { // Doit étendre Joueur pour pouvoir participer au jeu !

// Quelques éléments obligatoires ! :
public:
  // Constructeur, nécessaire ! (Pour transmettre des paramètres aux classes hérités ! )
  IPA();

  // Fonction à implémenter ! (Une implémentation par défaut est proposée ! )
  // Doit retourner l'angle vers lequel l'ia doit se diriger
  //  Angle en radian, 0 correspondant à la droite et tournant dans le sens anti-horaire
  double deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) override;


// À partir d'ici vous êtes libres !
private:
     double angleVers(Vect2D<double> position);
     int ite;
     double dir;
};
