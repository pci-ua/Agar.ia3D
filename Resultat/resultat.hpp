#pragma once

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>

#include <vector>

#include "../Controlleur/Partie.hh"

class Resultat
	:public QWidget
{
	Q_OBJECT;
public:
	Resultat(Result_Player a,Result_Classement b);
	Resultat();

private:
	// Interface
	QGridLayout* layout;

	QGroupBox* personnalData;
	QGroupBox* evolutionData;
	QGroupBox* allPlayerData;

	// Interface - Info joueur
	QHBoxLayout* personnalData_layout;

	QLabel* personnalData_Rank;
	QLabel* personnalData_Name;
	QLabel* personnalData_Kill;
	QLabel* personnalData_Death;
	QLabel* personnalData_SMax;
	QLabel* personnalData_SEnd;

	// Interface - Classement
	QVBoxLayout* allPlayerData_layout;

	
};