#pragma once

// Nécessaire pour s'incruster dans le jeu !
#include "../Modele/entitee/joueur.hh"

/* ♫♫♫
Tourner dans le vide, vide
Tourner dans le vide, il me fait tourner
 ♫♫♫ */

class Indila // N'hésitez pas à renommer votre IA !
  :public Joueur { // Doit étendre Joueur pour pouvoir participer au jeu !

// Quelques éléments obligatoires ! :
public:
  // Constructeur, nécessaire ! (Pour transmettre des paramètres aux classes hérités ! )
  Indila();

  // Fonction à implémenter ! (Une implémentation par défaut est proposée ! )
  // Doit retourner l'angle vers lequel l'ia doit se diriger
  //  Angle en radian, 0 correspondant à la droite et tournant dans le sens anti-horaire
  double deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) override;


// À partir d'ici vous êtes libres !
private:
  double i = 0; // Sert seulement pour l'exemple d'implémentation de la fonction déplacement

};
