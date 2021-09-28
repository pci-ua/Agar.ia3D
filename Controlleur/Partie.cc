#include "Partie.hh"

#include "../Modele/generateur/g_couleur.hh"
#include "../constante.hh"

#include <math.h> // PI (M_PI), cos , sin
#include <iostream>
#include <algorithm>

// Création d'une partie
Partie::Partie(const std::vector<Joueur*> & v,unsigned int duree,int nbFood)
	:tempRestant(duree)
{
	for(const auto & p:v) {
		participants.push_back(p);
	}
	for(int i=0 ; i<nbFood ; i++) {
		nourritures.push_back(new Nourriture(CouleurRandom()));
	}
}

Partie::~Partie() {
	while(participants.size() > 0) {
		delete participants.back();
		participants.pop_back();
	}
	while(nourritures.size() > 0) {
		delete nourritures.back();
		nourritures.pop_back();
	}
}

// Applique les déplacements et interactions pour passer à une frame suivante
void Partie::nextFrame() {
	// Detection de fin de partie (timeout)
	if(tempRestant == 0) {
		if(!finished) {
			finished=true;
			FinDePartie();
		}
		return;
	}
	tempRestant--;

	// Déplacement
	for(auto participant:participants) {
		participant->request_deplacement(*this);
	}

	// Collision
	for(auto participant:participants) {
		// Nourriture
		for(auto nourriture:nourritures) {
			if(participant->collision(*dynamic_cast<Boule*>(nourriture))) {
				participant->manger(nourriture);
			}
		}
		// Joueurs
		for(auto adversaire:participants) {
			if(participant != adversaire) {
				if(participant->collision(*dynamic_cast<Boule*>(adversaire))) {
					if(participant->getTaille() > adversaire->getTaille()) {
						participant->manger(adversaire);
					} else {
						adversaire->manger(participant);
					}
				}
			}
		}
	}
}

// Envoie d'une requête de déplacement à l'IA pour appliquer un déplacement
void Joueur::request_deplacement(const Partie & partie) {
	double angle = deplacement(
		partie.playerNearFrom(getPosition(),getTaille()*JOUEUR::ROV,this),
		partie.foodNearFrom(getPosition(),getTaille()*JOUEUR::ROV)
	);

	Vect2D<double> k(cos(angle),sin(angle));
	k.setMagnitude(vitesse);
	auto pos = getPosition() + k;

	const Vect2D<double> TopLeft(-CARTE::LONGUEUR+getTaille(),-CARTE::LARGEUR+getTaille());
	const Vect2D<double> BotRight(CARTE::LONGUEUR-getTaille(),CARTE::LARGEUR-getTaille());

	if( TopLeft <= pos && pos <= BotRight) {
		getPosition() = pos;
	}
}

// Retourne les joueurs proches du joueur donnée
std::vector<InfoEntitee> Partie::playerNearFrom(Vect2D<double> pos,double distMax,Joueur* self) const {
	std::vector<InfoEntitee> result;
	for(auto participant:participants) {
		if( (self != participant) && ((participant->getPosition()-pos).getMagnitude() <= distMax )) {
			result.push_back({ participant->getPosition(), participant->getTaille() });
		}
	}
	return result;
}

// Retourne les nourritures proches du joueur donnée
std::vector<InfoEntitee> Partie::foodNearFrom(Vect2D<double> pos,double distMax) const {
	std::vector<InfoEntitee> result;
	for(auto nourriture:nourritures) {
		if( (nourriture->getPosition()-pos).getMagnitude() <= distMax ) {
			result.push_back({ nourriture->getPosition(), nourriture->getTaille() });
		}
	}
	return result;
}

bool getClassementSort(Result_Classement_unit a,Result_Classement_unit b) {
	return a.score > b.score;
}

Result_Classement Partie::getClassement() {
	Result_Classement r;

	for(auto participant:participants) {
		unsigned int score = participant->getTaille() > 0 ? participant->getTaille() * 100 : 0;
		r.push_back({participant->getPseudo(),score});
	}
	std::sort( r.begin() , r.end() , getClassementSort);

	return r;
}

Result_Player Partie::getStatPlayer(Joueur* p,const Result_Classement & rc) {
	unsigned int rank = 0; for(auto player:rc) { rank++; if( player.pseudo == p->getPseudo() ) { break; } }

	return {
	/* pseudo */		p->getPseudo(),
	/* rank */			rank,
	/* deathCount */	p->getDeathCount(),
	/* killCount */		p->getKillCount(),
	/* maxScore */		static_cast<unsigned int>(p->getMaxScore()) * 1000,
	/* finalScore */	static_cast<unsigned int>(p->getTaille()) * 1000
	};
}


void Partie::FinDePartie() {
	Result_Classement rc = getClassement();
	Result_Player rp = getStatPlayer( *(participants.begin()) , rc );
	emit PartieTermine( rp, rc );
}