#include "mainwindow.hh"

#include <QApplication>
#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
     srand(time(nullptr));
    glutInit(&argc,argv);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    return a.exec();
}
