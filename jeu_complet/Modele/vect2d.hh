#pragma once

#include <string> // pour la méthode toString
#include <GL/gl.h> // pour la méthode setGlutColor

using ComposanteVect2D = float;


class Vect2D {

     struct Intervalle {
          int min;
          int max;
     };
     
private:
     ComposanteVect2D _x,_z;

public:
     Vect2D(Intervalle x,Intervalle z); // Créé une position aléatoire
     Vect2D(ComposanteVect2D x,ComposanteVect2D z);
     ~Vect2D() = default;
     Vect2D(const Vect2D & c) = default;

     void setX(ComposanteVect2D x) { _x = x; }
     void setZ(ComposanteVect2D z) { _z = z; }
     ComposanteVect2D getX() const { return _x; }
     ComposanteVect2D getZ() const { return _z; }

     std::string toString() const;

     void setGlutPosition() const;
};
