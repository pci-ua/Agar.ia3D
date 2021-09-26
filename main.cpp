#include <stdlib.h>      // Initialisation de la seed pour rand() avec srand()
#include <time.h>        // Pour générer une seed différente pour chaque itération de srand()
#include <unistd.h>      // Pour sleep(), pour ralentir l'éxécution

#include "Controlleur/Partie.hh"

#include "Intelligence/Indila.hh"
#include "Intelligence/Tay.hh"
#include "Intelligence/IPA.hh"
#include "Intelligence/Manuel.hh"

#include "Modele/generateur/position.hh"
extern void InitialisationRendu(int argc,char* argv[]);

Partie* p = nullptr;
JoueurManuel* m = nullptr;

#include <iostream>
int main(int argc,char* argv[]) {

	srand(time(nullptr));

	// Création de la partie
	m = new JoueurManuel(255,255,255);

	std::vector<Joueur*> v;

	v.push_back(m);
	for(int i=0;i<7;i++) {
		v.push_back(new IPA());
		v.push_back(new Tay());
		v.push_back(new Indila());
	}

	p = new Partie(v,4800,1020);

	InitialisationRendu(argc,argv);

	return EXIT_SUCCESS;
}

void updateManuallyHandled(int x,int y,int w,int h) {
	m->setSouris(x,y,w,h);
}
