#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "myglwidget.hh"
#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <QLineEdit>



extern Joueur player;
extern Ia iatest[];



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(838,318);
    ui->setupUi(this);
    setWindowTitle("Agar.ia 3D");

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Fonction qui ce declenche quand le pushboutton "play" est presse
void MainWindow::on_pushButton_clicked()
{


    this->tableWidget = new QTableWidget(ui->centralWidget);
    this->tableWidget->setObjectName(QStringLiteral("tableView"));


    this->pseudo = ui->textEdit->toPlainText().toStdString();
    if(pseudo.empty()){
        pseudo = "Joueur";
    }


    //Initialisation et ouverture de la nouvelle fenetre
        this->fjeux = new fenetrejeux();
        if(ui->checkBox->isChecked()==true){
            fjeux->setson(0);
        }
        if(ui->comboBox->currentText().toStdString()=="Nuit"){
            fjeux->setmode("Nuit");

        }
        fjeux->setpsd(pseudo);
        fjeux->settemps(ui->spinBox_4->value());
        fjeux->setcompteur(ui->spinBox_4->value());
        fjeux->setnbria(ui->spinBox->value());
        fjeux->initFenetre();
        fjeux->show();



    //Desactivation des element du menu , qui reste ouvert
    ui->pushButton->setEnabled(0);
    ui->spinBox->setEnabled(0);
    ui->spinBox_4->setEnabled(0);
    ui->textEdit->setEnabled(0);
    ui->menuQuitter->setEnabled(0);
    ui->pushButton_2->setEnabled(0);
    ui->comboBox->setEnabled(0);
    ui->label_5->setEnabled(0);
    ui->label_6->setEnabled(0);
    ui->checkBox->setEnabled(0);

    //Lancement du Qtimer qui declenche la fonction "fin de partie" au bout du temps choisi par le joueur
    tmps = new QTimer;
    tmps->setInterval(ui->spinBox_4->value()*60000);
    tmps->start();
    connect(tmps,SIGNAL(timeout()),this,SLOT(on_actionfindepartie_triggered()));

    if(ui->checkBox->isChecked()==true){
        sonnor=new QSound("../jeu_complet/Ressources/sonjeu.wav");
        sonnor->setLoops(-1);
        sonnor->play();
    }


}

//Fonction qui se declenche a la fin de la partie : fermeture de la fenetre de jeux et modification du menu pour affichage des score

void MainWindow::findepartie(){

    this->tmps->stop();
    if(ui->checkBox->isChecked()==true){
        this->sonnor->stop();
    }

    ui->label->close();
    ui->label_2->close();
    ui->textEdit->close();
    ui->pushButton->close();
    ui->menuQuitter->setEnabled(1);
    ui->pushButton_2->close();
    ui->label_3->close();
    ui->label_4->close();
    ui->label_5->close();
    ui->label_6->close();
    ui->comboBox->close();
    ui->checkBox->close();

    this->tabldeScore=this->fjeux->gettable();
    this->fjeux->findepartie();
    this->fjeux->close();

    //affichage tableau score final

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);
    tableWidget->insertColumn(tableWidget->columnCount());
    tableWidget->insertColumn(tableWidget->columnCount());
    tableWidget->insertRow(tableWidget->rowCount());
    tableWidget->horizontalHeader()->setStretchLastSection(true);

    this->setFixedSize(1100,400);

    for(int i=0;i<ui->spinBox->value()+1;i++){

     tableWidget->setItem(i,0,new QTableWidgetItem(this->tabldeScore->item(i,0)->text()));
     tableWidget->setItem(i,1,new QTableWidgetItem(this->tabldeScore->item(i,1)->text()));
     if(i!=ui->spinBox->value()){

         tableWidget->insertRow(tableWidget->rowCount());

     }

    }
    tableWidget->setFixedSize(450,350);
    tableWidget->setColumnWidth(0,200);
    tableWidget->setColumnWidth(1,170);
    ui->spinBox->close();
    ui->spinBox_4->close();
    ui->label_9->close();
    ui->label_3->close();
    ui->spinBox->close();

    tableWidget->move(this->width()-470,10);

    // CHangement du titre de la colonne du tableau
    QStringList nom;
    nom.append(QString::fromStdString("Classement Final"));
    nom.append(QString::fromStdString("Score"));
    tableWidget->setHorizontalHeaderLabels(nom);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->show();

    if(victoire() == true){ //Le joueur a gagne la partie : affichage personalise


        QLabel *affichagefin = new  QLabel(ui->centralWidget);
        affichagefin->setObjectName(QStringLiteral("affichagefin"));
        affichagefin->move(this->width()/8,100);
        affichagefin->setText("Victoire !");


        QLabel *affichagepseudo = new  QLabel(ui->centralWidget);
        affichagepseudo->setObjectName(QStringLiteral("affichagefin"));
        affichagepseudo->move(this->width()/8,130);
        affichagepseudo->setText("Bravo "+ QString::fromStdString(this->pseudo));


        QLabel *affichagescore = new  QLabel(ui->centralWidget);
        affichagescore->setObjectName(QStringLiteral("affichagescore"));
        affichagescore->move(this->width()/8,170);
        affichagescore->setText("Avec un score de "+ (this->tableWidget->item(0,1)->text()) + " points ! Impressionnant ");

        affichagefin->show();
        affichagescore->show();
        affichagepseudo->show();
        centralWidget()->show();

        if(ui->checkBox->isChecked()==true){
            sonnor=new QSound("../jeu_complet/Ressources/gagner.wav");
            sonnor->setLoops(-1);
            sonnor->play();
        }


    }else { // Le joueur a perdu la partie


        QLabel *affichagefin = new  QLabel(ui->centralWidget);
        affichagefin->setObjectName(QStringLiteral("affichagefin"));
        affichagefin->move(this->width()/8,100);
        affichagefin->setText("Defaite  !");


        QLabel *affichagepseudo = new  QLabel(ui->centralWidget);
        affichagepseudo->setObjectName(QStringLiteral("affichagefin"));
        affichagepseudo->move(this->width()/8,130);
        affichagepseudo->setText("Dommage "+ QString::fromStdString(this->pseudo) +", "+ this->tableWidget->item(0,0)->text()+" a été meilleur que vous !");


        QLabel *affichagescore = new  QLabel(ui->centralWidget);
        affichagescore->setObjectName(QStringLiteral("affichagescore"));
        affichagescore->move(this->width()/8,170);
        affichagescore->setText("Retentez votre chance !");

        affichagefin->show();
        affichagescore->show();
        affichagepseudo->show();
        centralWidget()->show();

        if(ui->checkBox->isChecked()==true){
            sonnor=new QSound("../jeu_complet/Ressources/perdu.wav");
            sonnor->setLoops(-1);
            sonnor->play();
        }

    }

}


//Fonction qui renvoi si oui ou non le joueur à gagner la partie en comparant son pseudo avec le pseudo de la  premiere place.

void MainWindow::on_actionQuitter_triggered()
{
    MainWindow::close();
}

void MainWindow::on_actionfindepartie_triggered()
{
    this->findepartie();
}


//verif condition victoire
bool MainWindow::victoire(){

    if(this->pseudo == this->tableWidget->item(0,0)->text().toStdString()){

        return true;
    }
    return false;
}


void MainWindow::on_pushButton_2_clicked()
{
    QColor c = QColorDialog::getColor(this->_couleur);
    if(c.isValid()){
            this->_couleur = c;

            this->replaceColor(ui->pushButton_2,this->_couleur);

     }

    player.setr(this->_couleur.redF());
    player.setg(this->_couleur.greenF());
    player.setb(this->_couleur.blueF());
}

void MainWindow::replaceColor(QPushButton *b,QColor c){

    QPalette pal = b->palette();
    pal.setColor(QPalette::Button,c);
    b->setAutoFillBackground(true);
    b->setFlat(true);
    b->setPalette(pal);
    b->update();
}
