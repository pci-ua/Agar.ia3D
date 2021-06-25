#include <stdlib.h>      // Initialisation de la seed pour rand() avec srand()
#include <time.h>        // Pour générer une seed différente pour chaque itération de srand()
#include <unistd.h>      // Pour sleep(), pour ralentir l'éxécution

#include "Controlleur/Partie.hh"

#include "Intelligence/Indila.hh"
#include "Intelligence/Tay.hh"

extern void InitialisationRendu(int argc,char* argv[]);

Partie* p = nullptr;

int main(int argc,char* argv[]) {

	srand(time(nullptr));

	// Création de la partie
	std::vector<Joueur*> v;
	for(int i=0;i<10;i++) {
	v.push_back(new Indila());
	}
	for(int i=0;i<10;i++) {
	v.push_back(new Tay());
	}

	p = new Partie(v,20,80);

	InitialisationRendu(argc,argv);

	return EXIT_SUCCESS;
}
