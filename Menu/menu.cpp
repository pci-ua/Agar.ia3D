#include "menu.hpp"

#include <QStringLiteral>
#include <QRegExpValidator>

#include <iostream>

Menu::Menu() {

    layout = new QVBoxLayout();

    /* LABEL */
    _pci_image = new QImage("./Menu/ressource/icon.png");
    _pci = new QLabel();
    _pci->setPixmap(QPixmap::fromImage(*_pci_image));



	/* SELECTION DU PSEUDO */
	_userLayout = new QHBoxLayout();
    _userGroup = new QGroupBox();

    _userGroup->setLayout(_userLayout);
	
	_username = new QLineEdit("");
    _username->setPlaceholderText("Pseudo");
	_username->setObjectName(QStringLiteral("_serverIP"));
	_username->setAlignment(Qt::AlignCenter);
    _usernameIconImage = new QImage("./Menu/ressource/head-icon.png");
    _usernameIcon = new QLabel();
	_usernameIcon->setObjectName(QStringLiteral("_Icon"));
    _usernameIcon->setPixmap(QPixmap::fromImage(*_usernameIconImage));
	
    _userLayout->addWidget(_usernameIcon);
	_userLayout->addWidget(_username);



	/* SELECTION DU SERVEUR */
	_serverLayout = new QHBoxLayout();
    _serverGroup = new QGroupBox();

    _serverGroup->setLayout(_serverLayout);
	
	_serverIP = new QLineEdit("");
    _serverIP->setPlaceholderText("IP serveur");
	_serverIP->setObjectName(QStringLiteral("_serverIP"));
	_serverIP->setAlignment(Qt::AlignCenter);
    _serverIconImage = new QImage("./Menu/ressource/server-icon.png");
    _serverIcon = new QLabel();
	_serverIcon->setObjectName(QStringLiteral("_Icon"));
    _serverIcon->setPixmap(QPixmap::fromImage(*_serverIconImage));
	
	QRegExp hostnameReg ( "^(([a-zA-Z0-9]|[[a-zA-Z0-9][a-zA-Z0-9][a-zA-Z0-9]).)([a-zA-Z0-9]|[a-zA-Z0-9][a-zA-Z0-9]*[a-zA-Z0-9])$" );
	QRegExp ipAdressReg ( "^(([0-9]|[1-9][0-9]1[0-9]{2}|2[0-4][0-9]|25[0-5]).){3}([0-9]|[1-9][0-9]1[0-9]{2}|2[0-4][0-9]|25[0-5])$" );
	
	_hostnameValidator = new QRegExpValidator(hostnameReg, this);
	_IPAdressValidator = new QRegExpValidator(ipAdressReg, this);
	
    _serverLayout->addWidget(_serverIcon);
	_serverLayout->addWidget(_serverIP);



    /* SELECTION DE COULEUR */
    _colorPickerLayout = new QHBoxLayout();

    _colorPicker = new QColorButton("#008080", this);
    _colorPicker->setObjectName(QStringLiteral("_colorPicker"));

    QRegExp er = QRegExp("\\#([0-9A-Fa-f]{3}){1,2}"); // #RGB ou #RRGGBB
    this->_colorValidator = new QRegExpValidator(er, this);
    _colorPickerText = new QLineEdit(_colorPicker->getColor().name());
    _colorPickerText->setAlignment(Qt::AlignCenter);
    _colorPickerText->setObjectName(QStringLiteral("_colorPickerText"));
    _colorPickerText->setValidator(_colorValidator);

    _colorPickerLayout->addWidget(_colorPicker);
    _colorPickerLayout->addWidget(_colorPickerText);


    /* REJOINDRE */
    _rejoindre = new QPushButton("Rejoindre");
    _rejoindre->setObjectName(QStringLiteral("_rejoindre"));


	/* EVENEMENTS */
	
	//ColorPicker
    QObject::connect(_colorPicker, &QColorButton::colorChanged, this, &Menu::setNewTextColor);
    QObject::connect(_colorPickerText, &QLineEdit::editingFinished, this, &Menu::setNewColorText);

	//Bouton Rejoindre
	QObject::connect(_rejoindre, &QPushButton::clicked, this, &Menu::rejoindre);


    /* AJOUT DES ELEMENTS AU LAYOUT */
    layout->addWidget(_pci);
    layout->addWidget(_userGroup, 1);
    layout->addWidget(_serverGroup, 2);
	layout->addLayout(_colorPickerLayout, 3);
    layout->addWidget(_rejoindre);
    layout->setAlignment(Qt::AlignCenter);


    this->setLayout(layout);
}

void Menu::setNewColorText() { _colorPicker->setColor(_colorPickerText->text()); }
void Menu::setNewTextColor() { _colorPickerText->setText(_colorPicker->getColor().name()); }

bool isInputAcceptable(const QLineEdit* input, const QValidator* validator) {
    QString texte = input->text();
    int pos = 0;

    return validator->validate( texte , pos ) == QValidator::Acceptable;
}

void Menu::rejoindre() {
    if(
        (
            isInputAcceptable( _serverIP , _IPAdressValidator ) ||
            isInputAcceptable( _serverIP , _hostnameValidator )
        ) &&
        isInputAcceptable( _colorPickerText , _colorValidator )
    )
    emit EnvoieFormulaire( {
        _username->text(),
        _colorPicker->getColor(),
        _serverIP->text() } );
}
