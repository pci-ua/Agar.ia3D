#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColor>
#include <QColorDialog>
#include <QImage>
#include <QGroupBox>
#include <QtMultimedia>
#include <QtMultimediaWidgets>

#include "./colorbutton.hpp"

struct PlayerData {
    QString PlayerName;
    QColor PlayerColor;
    QString ServerAdress;
};

class Menu : public QWidget {
    Q_OBJECT

    private:
        // Vidéo en fond du menu
        QMediaPlayer* backgroundVideoPlayer;
        QVideoWidget* backgroundVideoWidget;
        QMediaPlaylist* backgroundVideoPlaylist;

        QVBoxLayout* layout;

        QLabel* _pci;
        QImage* _pci_image;
        
        //Selection du pseudo
        QGroupBox* _userGroup;
        QHBoxLayout* _userLayout;
        QLabel* _usernameIcon;
        QImage* _usernameIconImage;
        QLineEdit* _username;
        
        //Selection du serveur
        QGroupBox* _serverGroup;
        QHBoxLayout* _serverLayout;
        QLabel* _serverIcon;
        QImage* _serverIconImage;
        QLineEdit* _serverIP;

        //Selection de la couleur
        QHBoxLayout* _colorPickerLayout;
        QLineEdit* _colorPickerText;
        QColorButton* _colorPicker;

	//Rejoindre
        QPushButton* _rejoindre;

        // Validation saisie texte
        QValidator* _IPAdressValidator;
        QValidator* _hostnameValidator;
        QValidator* _colorValidator;

	private slots:
        void setNewColorText();
        void setNewTextColor();
		
		void rejoindre();

    public:
        Menu();
        void setAnimatedBackground();
        void resizeEvent(QResizeEvent* event) override;

    signals:
        void EnvoieFormulaire(PlayerData d);
};
