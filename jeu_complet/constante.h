#pragma once

#define MARGE 0.5 // pour ne pas que la boule apparaissent au bord du terrain
#define LONGUEUR (40.0/2) // 40 doit être modifiable
#define LARGEUR (40.0/2)
//#define NBIA 5 // nombre ia
#define NBFOOD 400 // nombre food
#define ECART 0.05 // pourcentage de taille d'une sphère
#define SUBDIVISIONS_BOULE 30 // nombbre de subdivision lors de la création de la sphère
#define COULEUR (float)rand()/(RAND_MAX) // couleur aléatoire entre 0 et 1 (float)
#define TAILLE_FOOD 0.1
#define TAILLE_JOUEURS 0.5
#define VITESSE 0.1 // vitesse de base
#define VITESSE_MIN 0.02
#define MODIF_TAILLE 0.005 // modifie la taille en mangeant une food
#define MODIF_VITESSE 0.0001 // modifie la vitesse en mangeant
#define PALLIER_VITESSE 0.0201 // pallier de vitesse
#define POURCENTAGE_MANGE 0.25 // pourcentage de taille de l'adversaire qui est donné au joueur
#define CAMERA_UP 0.02 //augmente la camera
