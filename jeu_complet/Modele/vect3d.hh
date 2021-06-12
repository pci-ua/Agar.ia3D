#pragma once

#include <string> // pour la méthode toString
#include <GL/gl.h> // pour la méthode setGlutColor

using ComposanteVect3D = float;


class Vect3D {

     struct Intervalle {
          ComposanteVect3D min;
          ComposanteVect3D max;
     };

private:
     ComposanteVect3D _x,_y,_z;

public:
     Vect3D(Intervalle x,Intervalle y,Intervalle z); // Créé une position aléatoire
     Vect3D(ComposanteVect3D x,ComposanteVect3D y,ComposanteVect3D z);
     ~Vect3D() = default;
     Vect3D(const Vect3D & c) = default;

     void setX(ComposanteVect3D x) { _x = x; }
     void setY(ComposanteVect3D y) { _y = y; }
     void setZ(ComposanteVect3D z) { _z = z; }
     ComposanteVect3D getX() const { return _x; }
     ComposanteVect3D getY() const { return _y; }
     ComposanteVect3D getZ() const { return _z; }

     std::string toString() const;

     void setGlutPosition() const;
     ComposanteVect3D length() const;

     Vect3D operator+(const Vect3D & v) const;
     Vect3D& operator+=(const Vect3D & v);

     Vect3D operator-(const Vect3D & v) const;
     Vect3D& operator-=(const Vect3D & v);
};
