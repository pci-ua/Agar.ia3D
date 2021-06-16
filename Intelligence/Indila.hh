#include "../Modele/entitee/joueur.hh"

class Indila
/*
Tourner dans le vide, vide
Tourner dans le vide, il me fait tourner
*/
  :public Joueur {
private:
double i = 0;

public:
  double deplacement() override {
    i+=0.1;
    return i;
  }
};
