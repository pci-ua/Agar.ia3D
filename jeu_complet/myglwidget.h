#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <QOpenGLFunctions>
 #include <QMouseEvent>
#include <iostream>
#include <QSurfaceFormat>

#include "terrain.h"
#include "boule.h"
#include "food.h"
#include "joueurs.h"
#include "joueur.h"
#include "ia.h"
#include "constante.h"

#include <array>

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{

    Q_OBJECT
public:
    MyGLWidget(QWidget* parent=nullptr);
    int getnbia(){return nbia;}
    void setnbia(int nb){ this->nbia = nb;}



private:


    void initializeGL() override;
    void paintGL() override;
    void resizeGL(GLsizei Largeur, GLsizei Hauteur) override;
    void mouseMoveEvent(QMouseEvent *event) override ;
    void deplacementia(int i);
    void deplacementJ();
    int nbia = 1;


};

#endif // MYGLWIDGET_H
