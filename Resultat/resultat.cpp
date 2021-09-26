#include "./resultat.hpp"

Resultat::Resultat(Result_Player a,Result_Classement b) {
	// Global
	layout = new QGridLayout();

	personnalData = new QGroupBox(this);
	layout->addWidget( personnalData, 1,1, 1,2);
	evolutionData = new QGroupBox(this);
	layout->addWidget( evolutionData, 2,1, 1,1);
	allPlayerData = new QGroupBox(this);
	layout->addWidget( allPlayerData, 2,2, 1,1);

	// Résultat personnel
	
	personnalData_layout = new QHBoxLayout();

	personnalData_Rank = new QLabel("7",personnalData);
	personnalData_Name = new QLabel("Tenshirock",personnalData);
	personnalData_Kill = new QLabel("0",personnalData);
	personnalData_Death = new QLabel("0",personnalData);
	personnalData_SMax = new QLabel("999",personnalData);
	personnalData_SEnd = new QLabel("666",personnalData);

	personnalData_layout->addWidget(personnalData_Rank);
	personnalData_layout->addWidget(personnalData_Name);
	personnalData_layout->addWidget(personnalData_Kill);
	personnalData_layout->addWidget(personnalData_Death);
	personnalData_layout->addWidget(personnalData_SMax);
	personnalData_layout->addWidget(personnalData_SEnd);
	personnalData->setLayout( personnalData_layout );

	// Résultat graphe
	// . . .

	// Classement
	/*
	allPlayerData_layout = new QVBoxLayout();

	std::vector<QLabel*> allPlayerData_playerList;*/
	std::cout << "a" << std::endl;
	this->setLayout(layout);
}

Resultat::Resultat() {
	// Global
	layout = new QGridLayout();

	personnalData = new QGroupBox(this);
	layout->addWidget( personnalData, 1,1, 1,2);
	evolutionData = new QGroupBox(this);
	layout->addWidget( evolutionData, 2,1, 1,1);
	allPlayerData = new QGroupBox(this);
	layout->addWidget( allPlayerData, 2,2, 1,1);

	// Résultat personnel
	
	personnalData_layout = new QHBoxLayout();

	personnalData_Rank = new QLabel("7",personnalData);
	personnalData_Name = new QLabel("Tenshirock",personnalData);
	personnalData_Kill = new QLabel("0",personnalData);
	personnalData_Death = new QLabel("0",personnalData);
	personnalData_SMax = new QLabel("999",personnalData);
	personnalData_SEnd = new QLabel("666",personnalData);

	personnalData_layout->addWidget(personnalData_Rank);
	personnalData_layout->addWidget(personnalData_Name);
	personnalData_layout->addWidget(personnalData_Kill);
	personnalData_layout->addWidget(personnalData_Death);
	personnalData_layout->addWidget(personnalData_SMax);
	personnalData_layout->addWidget(personnalData_SEnd);
	personnalData->setLayout( personnalData_layout );

	// Résultat graphe
	// . . .

	// Classement
	allPlayerData_layout = new QVBoxLayout();

	std::vector<QLabel*> allPlayerData_playerList;
	std::cout << "a" << std::endl;
	this->setLayout(layout);
}