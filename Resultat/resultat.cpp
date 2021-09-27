#include "./resultat.hpp"

Resultat::Resultat(Result_Player a,Result_Classement b) {

	// Global

	layout = new QGridLayout();

	personnalData = new QGroupBox(this);
	personnalData->setObjectName("_result_personnal");
	layout->addWidget( personnalData, 1,1, 1,2);
	evolutionData = new QGroupBox(this);
	evolutionData->setObjectName("_result_evolution");
	layout->addWidget( evolutionData, 2,1, 1,1);
	allPlayerData = new QGroupBox(this);
	allPlayerData->setObjectName("_result_everyone");
	layout->addWidget( allPlayerData, 2,2, 1,1);

	// Résultat personnel
	
	personnalData_layout = new QHBoxLayout();

	personnalData_Rank = new QLabel(QString::number(a.rank),personnalData);
	personnalData_Name = new QLabel(a.pseudo,personnalData);
	personnalData_Kill = new QLabel(QString::number(a.killCount) + QString("🗡️"),personnalData);
	personnalData_Death = new QLabel(QString::number(a.deathCount) + QString("☠️"),personnalData);
	personnalData_SMax = new QLabel(QString::number(a.maxScore),personnalData);
	personnalData_SEnd = new QLabel(QString::number(a.finalScore),personnalData);

	personnalData_Rank->setObjectName("rank");
	personnalData_Name->setObjectName("pseudo");
	personnalData_Kill->setObjectName("killCount");
	personnalData_Death->setObjectName("deathCount");
	personnalData_SMax->setObjectName("scoreMax");
	personnalData_SEnd->setObjectName("scoreFinal");

	personnalData_layout->addWidget(personnalData_Rank);
	personnalData_layout->addWidget(personnalData_Name);
	personnalData_layout->addWidget(personnalData_Kill);
	personnalData_layout->addWidget(personnalData_Death);
	personnalData_layout->addWidget(personnalData_SMax);
	personnalData_layout->addWidget(personnalData_SEnd);

	personnalData->setLayout( personnalData_layout );

	switch(a.rank) {
		case 1: personnalData_Rank->setStyleSheet(" color: #FFD700;"); break;
		case 2: personnalData_Rank->setStyleSheet(" color: #C0C0C0;"); break;
		case 3: personnalData_Rank->setStyleSheet(" color: #B87333;"); break;
		default: personnalData_Rank->setStyleSheet(" color: white;");
	}

	// Résultat graphe
	// . . .

	// Classement

	allPlayerData_layout = new QVBoxLayout();

	for(auto player:b) {
		QLabel* k = new QLabel(player.pseudo + " > " + QString::number(player.score),allPlayerData);
		allPlayerData_playerList.push_back(k);
		allPlayerData_layout->addWidget(k);
	}

	allPlayerData->setLayout(allPlayerData_layout);

	// fin
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