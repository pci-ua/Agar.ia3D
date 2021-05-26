#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL>
#include <string>
#include <myglwidget.h>
#include "fenetrejeux.h"

    #include <QMediaPlayer>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void findepartie();
    bool victoire();
    void replaceColor(QPushButton *b,QColor c);



private slots:

    void on_pushButton_clicked();

    void on_actionQuitter_triggered();

    void on_actionfindepartie_triggered();

    void on_pushButton_2_clicked();

private:

    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    QTableWidget *tabldeScore;
    fenetrejeux *fjeux;
    std::string pseudo;
    QColor _couleur = Qt::red;
    QTimer *tmps;
    float _r;
    float _g;
    float _b;
    QSound *sonnor;


};



#endif // MAINWINDOW_H
