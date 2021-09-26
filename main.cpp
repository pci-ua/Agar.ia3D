#include <stdlib.h>      // Initialisation de la seed pour rand() avec srand()
#include <time.h>        // Pour générer une seed différente pour chaque itération de srand()
#include <unistd.h>      // Pour sleep(), pour ralentir l'éxécution

#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QtWidgets>

#include "Controlleur/Partie.hh"

#include "Intelligence/Indila.hh"
#include "Intelligence/Tay.hh"
#include "Intelligence/IPA.hh"
#include "Modele/generateur/position.hh"

#include "Menu/menu.hpp"
#include "Resultat/resultat.hpp"

extern int InitialisationRendu(int argc,char* argv[]);

QApplication* app = nullptr;
Partie* p = nullptr;
Menu* menu = nullptr;
Resultat* result = nullptr;

void Etape3_Recap(Result_Player a,Result_Classement b) {
	result = new Resultat(a,b);
	result->showMaximized();
	app->setActiveWindow(result);
	glutLeaveMainLoop();
}

void Etape2_Jeu(PlayerData pd) {
	menu->close();

	// Création de la partie
	std::vector<Joueur*> v;
	for(int i=0;i<7;i++) {
		v.push_back(new IPA());
		v.push_back(new Tay());
		v.push_back(new Indila());
	}
	std::cout << pd.PlayerName.toStdString() << std::endl;
	p = new Partie(v,1000,1020);

	QObject::connect(p, &Partie::PartieTermine, &Etape3_Recap );

	InitialisationRendu(0,nullptr);
}

void Etape1_Menu() {
	// 1.1 Import du style
    QFile styleFile("./Menu/menu.qss");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());

	// 1.3 Création du menu
    menu = new Menu();
    menu->setStyleSheet(style);

	// 1.2 Liaison d'événements
    QObject::connect(menu, &Menu::EnvoieFormulaire, &Etape2_Jeu);

	// 1.4 Rendu et affichage
	menu->showMaximized();
    app->setActiveWindow(menu);

}

void Initialisation(int argc,char* argv[]) {
	// 0.1 Initilisation générateur random
	srand(time(nullptr));
	
	// 0.2 Création de l'application
    app = new QApplication(argc,argv);
    QCoreApplication::setApplicationName(QString("Agar[IA]"));

}

int main(int argc,char* argv[]) {
	Initialisation(argc,argv);
	Etape1_Menu();
	return app->exec();
}
