#ifndef FENETREJEUX_H
#define FENETREJEUX_H


#include <QMainWindow>
#include <QWidget>
#include <QtOpenGL>
#include <string>
#include <myglwidget.h>

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
    bool victoire();
    void initFenetre();
    QTableWidget* gettable(){return this->tableWidget;}

    void settable(QTableWidget *tableau){this->tableWidget=tableau;}
    void setfenetre(MyGLWidget *fntr){this->fenetre=fntr;}
    void settemps(int tmps){this->temps=tmps;}
    void setpsd(std::string psd){this->pseudo=psd;}
    void setnbria(int nbria){this->nombreia=nbria;}


private slots:

    void classementA();
    void chrono_refresh();

private :

    Ui::fenetrejeux *ui;
    QTableWidget *tableWidget;
    MyGLWidget *fenetre;
    QTimer *timer;
    int temps = 60 ;
    std::string pseudo;
    int nombreia;
    bool fin = false;
    QLCDNumber *afficher_chrono;
    QTime chrono ;
    QTimer *timer_chrono ;



};

#endif // FENETREJEUX_H
