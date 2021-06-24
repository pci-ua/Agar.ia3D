#include <stdlib.h>      // Initialisation de la seed pour rand() avec srand()
#include <time.h>        // Pour générer une seed différente pour chaque itération de srand()
#include <unistd.h>      // Pour sleep(), pour ralentir l'éxécution

#include "Controlleur/Partie.hh"

#include "Intelligence/Indila.hh"

extern void InitialisationRendu(int argc,char* argv[]);

int main(int argc,char* argv[]) {
	
	srand(time(nullptr));

/* non nécessaire pour l'instant
	std::vector<Joueur*> v;
	for(int i=0;i<4;i++) {
	v.push_back(new Indila());
	}

	Partie p(v,20,80);
	for(int i=0;i<20;i++) {
     	p.nextFrame();
		p.renduTerminal();
		sleep(1);
	}
*/
	InitialisationRendu(argc,argv);

	return EXIT_SUCCESS;
}
