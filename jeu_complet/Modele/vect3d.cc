#include "vect3d.hh"

#include <stdlib.h>

std::string Vect3D::toString() const {
     return "("+std::to_string(_x)+","+std::to_string(_y)+","+std::to_string(_z)+")";
}
Vect3D::Vect3D(Intervalle x,Intervalle y,Intervalle z) {
     int xd = x.max - x.min;
     int yd = y.max - y.min;
     int zd = z.max - z.min;
     _x = (rand() % xd) + x.min;
     _y = (rand() % yd) + y.min;
     _z = (rand() % zd) + z.min;
}

Vect3D::Vect3D(ComposanteVect3D x,ComposanteVect3D y,ComposanteVect3D z)
     :_x(x),_y(y),_z(z) {}

void Vect3D::setGlutPosition() const {
     glTranslatef(_x,_y,_z);
}
