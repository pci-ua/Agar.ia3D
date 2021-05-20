#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myglwidget.h"
#include <QtOpenGL>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <QLineEdit>



extern joueur Player;
extern ia iatest[];



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->setMinimumSize(838,318);
    ui->setupUi(this);
    setWindowTitle("Agario 3D");
    std::cout<<this->width()<<" "<<this->height();




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    this->tableWidget = new QTableWidget(ui->centralWidget);
    this->tableWidget->setObjectName(QStringLiteral("tableView"));



    this->pseudo = ui->textEdit->toPlainText().toStdString();
    if(pseudo.empty()){
        pseudo = "Joueur";
    }
   this->fjeux = new fenetrejeux();

        fjeux->setpsd(pseudo);
        fjeux->settemps(ui->spinBox_4->value());
        fjeux->setnbria(ui->spinBox->value());
        fjeux->initFenetre();
        fjeux->show();


    ui->pushButton->setEnabled(0);
    ui->spinBox->setEnabled(0);
    ui->spinBox_4->setEnabled(0);
    ui->textEdit->setEnabled(0);
    ui->menuQuitter->setEnabled(0);


    QTimer *tmps = new QTimer;
    tmps->setInterval(ui->spinBox_4->value()*60000);
    tmps->start();
    connect(tmps,SIGNAL(timeout()),this,SLOT(on_actionfindepartie_triggered()));



}

//Fonction qui se declenche a la fin de la partie et affiche l'ecran de fin de partie

void MainWindow::findepartie(){

    ui->label->close();
    ui->label_2->close();
    ui->textEdit->close();
    ui->pushButton->close();
    ui->menuQuitter->setEnabled(1);


    this->tabldeScore=this->fjeux->gettable();
    this->fjeux->close();

    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(0);
    tableWidget->insertColumn(tableWidget->columnCount()); //insertion d'une colonne dans le tableau sur laquelle on va afficher le classement
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
    tableWidget->setFixedSize(420,250);
    tableWidget->setColumnWidth(0,200);
    tableWidget->setColumnWidth(1,170);
    ui->spinBox->close();
    ui->spinBox_4->close();
    ui->label_9->close();
    ui->label_3->close();
    ui->spinBox->close();

    // On s'ocuppe du tableau : sa derniere version est égale au classement final
    tableWidget->move(this->width()-420,10);
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
        affichagescore->setText("Avec un score de "+ (this->tableWidget->item(0,1)->text()) + " points ! Impressionant ");

        affichagefin->show();
        affichagescore->show();
        affichagepseudo->show();
        centralWidget()->show();


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

    }

}


//Fonction qui renvoi si oui ou non le joueur à gagner la partie en comparant son pseudo avec le pseudo du premier place.


void MainWindow::on_actionQuitter_triggered()
{
    MainWindow::close();
}

void MainWindow::on_actionfindepartie_triggered()
{
    this->findepartie();
}

bool MainWindow::victoire(){

    if(this->pseudo == this->tableWidget->item(0,0)->text().toStdString()){

        return true;
    }
    return false;
}

