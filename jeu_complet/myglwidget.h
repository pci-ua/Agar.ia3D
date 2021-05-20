#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <joueur.h>
#include <ia.h>



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
