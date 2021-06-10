#include "vect2d.hh"

#include <stdlib.h>

std::string Vect2D::toString() const {
     return "("+std::to_string(_x)+","+std::to_string(_z)+")";
}
Vect2D::Vect2D(Intervalle x,Intervalle z) {
     int xd = x.max - x.min;
     int zd = z.max - z.min;
     _x = (rand() % xd) + x.min;
     _z = (rand() % zd) + z.min;
}

Vect2D::Vect2D(ComposanteVect2D x,ComposanteVect2D z)
     :_x(x),_z(z) {}

void Vect2D::setGlutPosition() const {
     glTranslatef(_x,0,_z);
}
