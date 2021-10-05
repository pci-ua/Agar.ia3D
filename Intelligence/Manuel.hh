#pragma once

#include "../Modele/entitee/joueur.hh"

#include <QObject>

/* Joueur manuel à la souris */

class JoueurManuel
  :public Joueur,public QObject {
private:
	double angle = 0;

public:
  JoueurManuel(int r,int g,int b,QString pseudo)
    :Joueur(Couleur(r, g, b),pseudo) {}
  double deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) override;

public slots:
	void setSouris(int x,int y,int width,int height);
};
