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

extern void InitialisationRendu(int argc,char* argv[]);

Partie* p = nullptr;

#include <iostream>	


void Etape2_Jeu(PlayerData pd) {
	// Création de la partie
	std::vector<Joueur*> v;
	for(int i=0;i<7;i++) {
		v.push_back(new IPA());
		v.push_back(new Tay());
		v.push_back(new Indila());
	}

	p = new Partie(v,4800,1020);

	InitialisationRendu(0,nullptr);

}

void Etape1_Menu(QApplication & app) {
	// 1.1 Import du style
    QFile styleFile("./Menu/menu.qss");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());

	// 1.3 Création du menu
    Menu* menu = new Menu();
    menu->setStyleSheet(style);

	// 1.2 Liaison d'événements
    QObject::connect(menu, &Menu::EnvoieFormulaire, &Etape2_Jeu);

	// 1.4 Rendu et affichage
	menu->showMaximized();
    app.setActiveWindow(menu);

}

QApplication* Initialisation(int argc,char* argv[]) {
	// 0.1 Initilisation générateur random
	srand(time(nullptr));
	
	// 0.2 Création de l'application
    QApplication* app = new QApplication(argc,argv);
    QCoreApplication::setApplicationName(QString("Agar[IA]"));

	return app;
}

int main(int argc,char* argv[]) {
    QApplication app(argc,argv);
    QCoreApplication::setApplicationName(QString("Agar[IA]"));

	Etape1_Menu(app);
	return app.exec();
}
