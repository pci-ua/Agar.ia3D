#pragma once

#define MARGE 0.5 // pour ne pas que la boule apparaissent au bord du terrain
#define LONGUEUR (50.0/2) // taille du terrain
#define LARGEUR (50.0/2)
#define NBIAMAX 20 // nombre ia max
#define NBFOOD 325 // nombre food
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
#define RAFRAICHISSEMENT_TAB 5000 //Intervalle de rafraichissement du tableau des scores, en secondes
#define RAFRAICHISSEMENT_TIME 1000 //Intervalle de rafraichissement de l'horloge , en secondes
