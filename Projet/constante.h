#pragma once

#define marge 0.5 // pour ne pas que la boule apparaissent au bord du terrain
#define longueur (40.0/2) // 40 doit être modifiable
#define largeur (40.0/2)
#define nbia 5 // nombre ia
#define nbfood 400 // nombre food
#define ecart 0.05 // pourcentage de taille d'une sphère
#define subdivisions_boule 30 // nombbre de subdivision lors de la création de la sphère
#define couleur (float)rand()/(RAND_MAX) // couleur aléatoire entre 0 et 1 (float)
#define taille_food 0.1
#define taille_joueurs 0.5
#define vitesse 0.1 // vitesse de base
#define vitesse_min 0.02
#define modif_taille 0.005 // modifie la taille en mangeant une food
#define modif_vitesse 0.0001 // modifie la vitesse en mangeant
#define pallier_vitesse 0.0201 // pallier de vitesse
#define pourcentage_mange 0.25 // pourcentage de taille de l'adversaire qui est donné au joueur
#define camera_up 0.02 //augmente la camera
