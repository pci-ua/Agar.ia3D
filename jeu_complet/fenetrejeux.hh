#ifndef FENETREJEUX_H
#define FENETREJEUX_H


#include <QMainWindow>
#include <QWidget>
#include <QtOpenGL>
#include <string>
#include <myglwidget.hh>

namespace Ui {
class fenetrejeux;
}

class fenetrejeux : public QMainWindow
{

    Q_OBJECT
public:

    explicit fenetrejeux(QWidget *parent = 0);
     //~fenetrejeux();
    void initclassement();
    std::string getpseudo();
    void setpseudo(std::string);
    void findepartie();
    void initFenetre();
    QTableWidget* gettable(){return this->tableWidget;}

    void settable(QTableWidget *tableau){this->tableWidget=tableau;}
    void setfenetre(MyGLWidget *fntr){this->fenetre=fntr;}
    void settemps(int tmps){this->temps=tmps;}
    void setcompteur(int compt){this->compteur=compt;}
    void setpsd(std::string psd){this->pseudo=psd;}
    void setnbria(int nbria){this->nombreia=nbria;}
    void setmode(std::string mode){this->_mode_nuit=mode;}
    void setson(int son){this->son=son;}


private slots:

    void classementA();
    void chrono_refresh();

private :

    Ui::fenetrejeux *ui;
    QTableWidget *tableWidget;
    MyGLWidget *fenetre;
    QTimer *timer;
    int temps = 1 ;
    std::string pseudo;
    int nombreia;
    bool fin = false;
    QLCDNumber *afficher_chrono;
    QTime chrono ;
    QTimer *timer_chrono ;
    int compteur;
    std::string _mode_nuit="Jour";
    int son=1;




};

#endif // FENETREJEUX_H
