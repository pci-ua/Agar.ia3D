#include "Tay.hh"

// Si jamais vous avez besoin de π :
#define PI 3.1415927

// Mettez ici, la couleur que vous souhaitez pour votre joueur (au format RGB) ! :
//pour pouvoir la choisir vous pouvez par exemple utiliser https://www.google.com/search?q=color+picker
const int R = 255;
const int G = 127;
const int B =   0;

// Vous pouvez rajoutez ci-dessous des sous-programmes(fonction ou méthode),
// des constantes, des variables, etc...

/* Remplacez moi ! */

// à partir d'ici, c'est le code principal
// il doit retourner un angle vers lequel se diriger
// - Angle en radian
// - 0rad signifie un mouvement vers la droite
// - On augmente dans le sens anti-horaire( sens trigonométrique )
double Tay::deplacement() {
  //Pour l'instant on va toujours en bas à gauche !
  return (5*PI) / 4;
}
