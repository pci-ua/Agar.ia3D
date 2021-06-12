#pragma once

#define NBIAMAX 20 // nombre ia max
#define NBFOOD 325 // nombre food
#define ECART 0.05 // pourcentage de taille d'une sphère
#define COULEUR (float)rand()/(RAND_MAX) // couleur aléatoire entre 0 et 1 (float)
#define TAILLE_FOOD 0.1
#define TAILLE_JOUEURS 0.5
#define VITESSE 0.1 // vitesse de base
#define VITESSE_MIN 0.02
#define MODIF_TAILLE 0.005 // modifie la taille en mangeant une food
#define MODIF_VITESSE 0.0001 // modifie la vitesse en mangeant
#define PALLIER_VITESSE 0.0201 // pallier de vitesse
#define POURCENTAGE_MANGE 0.25 // pourcentage de taille de l'adversaire qui est donné au joueur
#define CAMERA_UP 0.01 //augmente la camera
#define RAFRAICHISSEMENT_TAB 5000 //Intervalle de rafraichissement du tableau des scores, en secondes
#define RAFRAICHISSEMENT_TIME 1000 //Intervalle de rafraichissement de l'horloge , en secondes
#define TEMPSSONFIN 7 // Temps du son chronometre

// Valeur par défaut des joueurs
namespace JOUEUR {
     const float TAILLE = 0.5;
};

// Information sur le terrain
namespace TERRAIN {
     // Taille du terrain
     const float LONGUEUR = 25;
     const float LARGEUR = 25;

     // Taille spawnable du terrain
     const float LONGUEUR_S = LONGUEUR - JOUEUR::TAILLE;
     const float LARGEUR_S = LARGEUR - JOUEUR::TAILLE;
};

namespace RENDU {
     // Qualité de rendu des entités spherique
     const unsigned int SUBDIVISIONS_BOULE = 25;
     const unsigned int SUBDIVISIONS_FOOD = 12;
     const unsigned int SUBDIVISIONS_JOUEUR = 20;
};
