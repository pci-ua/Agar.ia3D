#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QGLWidget>
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

#include "terrain.hh"
#include "boule.hh"
#include "food.hh"
#include "joueurs.hh"
#include "joueur.hh"
#include "ia.hh"
#include "constante.hh"

#include <array>
#include <QDebug>
#include <QSound>

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{

    Q_OBJECT
public:
    MyGLWidget(QWidget* parent=nullptr);
    int getnbia(){return nbia;}
    void setnbia(int nb){ this->nbia = nb;}
    void setmode(std::string mode){this->_mode_nuit=mode;}
    void setson(int son){this->son=son;}



private:


    void initializeGL() override;
    void paintGL() override;
    void resizeGL(GLsizei Largeur, GLsizei Hauteur) override;
    void LoadGLTextures();
    void mouseMoveEvent(QMouseEvent *event) override ;
    void deplacementia(int i);
    void deplacementJ();
    std::string _mode_nuit="Jour";
    int nbia = 1;
    GLuint tex[1];
    int son=1;


};

#endif // MYGLWIDGET_H
