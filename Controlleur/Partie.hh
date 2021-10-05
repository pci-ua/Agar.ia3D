#pragma once

#include "../Modele/entitee/joueur.hh"
#include "../Modele/entitee/nourriture.hh"

#include <vector>
#include <QObject>

struct Result_Player {
	QString pseudo;
	unsigned int rank;
	unsigned int deathCount;
	unsigned int killCount;
	unsigned int maxScore;
	unsigned int finalScore;
};

struct Result_Classement_unit {
	QString pseudo;
	unsigned int score;
};

using Result_Classement = std::vector<Result_Classement_unit>;

class Partie
	:public QObject
{
	Q_OBJECT;

private:
	std::vector<Joueur*> participants;
	std::vector<Nourriture*> nourritures;
	unsigned int tempRestant; /*seconde*/

private:
	Result_Classement getClassement();
	Result_Player getStatPlayer(Joueur* p,const Result_Classement & rc);
	
public:

	Partie(const std::vector<Joueur*> & v,unsigned int duree,int nmbFood);
	Partie(const Partie & p) = delete;
	~Partie();

	Partie& operator=(const Partie & c) = delete;

	// Temporaire
	void renduTerminal();
	auto p_begin() { return participants.begin(); }
	auto p_end() { return participants.end(); }
	auto n_begin() { return nourritures.begin(); }
	auto n_end() { return nourritures.end(); }

	void nextFrame();

	std::vector<InfoEntitee> playerNearFrom(Vect2D<double> pos,double size,Joueur* self) const;
	std::vector<InfoEntitee> foodNearFrom(Vect2D<double> pos,double size) const;

	bool finished = false;

	void FinDePartie();
	
signals:
	void PartieTermine(Result_Player a,Result_Classement b);
};
