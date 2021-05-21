#include "fenetrejeux.h"
#include "ui_fenetrejeux.h"
extern Joueur player;
extern Ia iatest[];


fenetrejeux::fenetrejeux(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fenetrejeux)
 {
     ui->setupUi(this);
 }


void fenetrejeux::initFenetre(){


    //recuperation de la taille de l'ecran de l'utilisateur pour l'affichage de la fenetre de jeux
    QDesktopWidget *pleinecran = QApplication::desktop();
    this->setMinimumSize(QSize(pleinecran->width(),pleinecran->height()));
    this->showFullScreen();

    //Initialisation de la fenetre opengl
    this->fenetre = new MyGLWidget(ui->centralwidget);
    this->fenetre->setObjectName(QStringLiteral("fenetre"));
    this->fenetre->setGeometry(QRect(20, 10, 121, 101));
    this->fenetre->setnbia(this->nombreia);
    this->fenetre->setMinimumSize(QSize(pleinecran->width()-270,pleinecran->height()));

    this->setCentralWidget(ui->centralwidget);

    //Initialisation tableau de score
    this->tableWidget = new  QTableWidget(ui->centralwidget);
    this->tableWidget->move(pleinecran->width()-250,10);
    this->tableWidget->setMinimumSize(pleinecran->width()-(pleinecran->width()-200),pleinecran->height());
    this->tableWidget->show();
    this->initclassement();

    this->fenetre->move(10,10);
    this->fenetre->show();


    //Boucle qui active le rafraichissement du classement
    for(int i=0;i<((temps*60)/5);i++){

           timer= new QTimer;
           timer->setInterval(RAFRAICHISSEMENT_TAB);
           timer->start();
           connect (timer,SIGNAL (timeout()),this, SLOT (classementA()));

   }


}






void fenetrejeux::initclassement(){

    //Initialisation d'un tableau vide
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);
    tableWidget->insertColumn(tableWidget->columnCount());
    tableWidget->insertColumn(tableWidget->columnCount());

        //remplissage de du titre de la colonne
        QStringList nom;
        nom.append(QString::fromStdString("Nom"));
        nom.append(QString::fromStdString("Score"));
        tableWidget->setHorizontalHeaderLabels(nom);


        tableWidget->insertRow(tableWidget->rowCount());
           std::string mot = this->pseudo;
           std::string score = std::to_string(player.getTaille()*1000-500);
           tableWidget-> setItem(0,0,new QTableWidgetItem(QString::fromStdString(mot)));
           tableWidget->setItem(0,1,new QTableWidgetItem(QString::fromStdString(score)));


        for(int i=0;i<fenetre->getnbia();i++){
            tableWidget->insertRow(tableWidget->rowCount());
            std::string nom = "ia " + std::to_string(i);
            std::string score = std::to_string(iatest[i].getTaille()*1000-500);
            tableWidget-> setItem(i+1,0,new QTableWidgetItem(QString::fromStdString(nom)));
            tableWidget->setItem(i+1,1,new QTableWidgetItem(QString::fromStdString(score)));
        }


    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}


//Fonction de rafraichissement du tableau
void fenetrejeux::classementA(){

std::array<std::string,10>  name;
std::array<float,10> point;

name[0] = this->pseudo;
point[0] = player.getTaille();

for(unsigned long i=0;i<static_cast<unsigned long>(fenetre->getnbia());i++){

name[i+1] = "ia " + std::to_string(i);
point[i+1] =  iatest[i].getTaille();

}

//tri du tableau
float a = 0;
std::string var;
bool s = false;

do{
     s = false;
     for(int i = 0;i < fenetre->getnbia();i++){

         if(point[static_cast<unsigned long>(i)]> point[static_cast<unsigned long>(i)+1])
         {
             a = point[static_cast<unsigned long>(i)];
             point[static_cast<unsigned long>(i)]= point[static_cast<unsigned long>(i)+1];
             point[static_cast<unsigned long>(i)+1] = a;


                var = name[static_cast<unsigned long>(i)];
                name[static_cast<unsigned long>(i)] = name[static_cast<unsigned long>(i)+1];
                name[static_cast<unsigned long>(i)+1] = var;


             s = true;

         }

        }
     } while (s==true);

    int vartab = 0;

    //insertion des tableau dans le widget table
   for(int i=fenetre->getnbia();i>-1;i--){

       tableWidget-> setItem(vartab,0,new QTableWidgetItem(QString::fromStdString(name[static_cast<unsigned long>(i)])));

        tableWidget->setItem(vartab,1,new QTableWidgetItem(QString::fromStdString(std::to_string(point[static_cast<unsigned long>(i)]*1000-500))));

        vartab++;
    }



}






