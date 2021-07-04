#pragma once

#include "../Modele/entitee/joueur.hh"

/* 📜📜📜
23 mars 2016 - 23 mars 2016
30 mars 2016 - 30 mars 2016
📜📜📜 */

extern const int R;
extern const int G;
extern const int B;

class Tay
  :public Joueur {

public:
  Tay()
    :Joueur(Couleur(R,G,B)) {}
  double deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) override;
};
