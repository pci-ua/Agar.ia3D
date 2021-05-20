#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL>
#include <string>
#include <myglwidget.h>
#include "fenetrejeux.h"



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



private slots:

    void on_pushButton_clicked();

    void on_actionQuitter_triggered();

    void on_actionfindepartie_triggered();

private:

    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    QTableWidget *tabldeScore;
    fenetrejeux *fjeux;
    std::string pseudo;




};



#endif // MAINWINDOW_H
