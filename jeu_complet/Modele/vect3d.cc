#include "vect3d.hh"

#include <stdlib.h>
#include <math.h>

std::string Vect3D::toString() const {
     return "("+std::to_string(_x)+","+std::to_string(_y)+","+std::to_string(_z)+")";
}
Vect3D::Vect3D(Intervalle x,Intervalle y,Intervalle z) {
     auto xd = x.max - x.min;
     auto yd = y.max - y.min;
     auto zd = z.max - z.min;
     _x = (rand() % (int)floor(xd)) + x.min;
     _y = (rand() % (int)floor(yd)) + y.min;
     _z = (rand() % (int)floor(zd)) + z.min;
}

Vect3D::Vect3D(ComposanteVect3D x,ComposanteVect3D y,ComposanteVect3D z)
     :_x(x),_y(y),_z(z) {}

void Vect3D::setGlutPosition() const {
     glTranslatef(_x,_y,_z);
}

Vect3D Vect3D::operator+(const Vect3D & v) const {
     return {
          (getX()+v.getX()),
          (getY()+v.getY()),
          (getZ()+v.getZ())
     };
}

Vect3D& Vect3D::operator+=(const Vect3D & v) {
     _x += v.getX();
     _y += v.getY();
     _z += v.getZ();
     return *this;
}

Vect3D Vect3D::operator-(const Vect3D & v) const {
     return {
          (getX()-v.getX()),
          (getY()-v.getY()),
          (getZ()-v.getZ())
     };
}

Vect3D& Vect3D::operator-=(const Vect3D & v) {
     _x -= v.getX();
     _y -= v.getY();
     _z -= v.getZ();
     return *this;
}

ComposanteVect3D Vect3D::length() const {
     return sqrt(pow(_x,2)+pow(_y,2)+pow(_z,2));
}

void Vect3D::setMagnitude(ComposanteVect3D mag) {
     auto scaleRatio = length() / mag;
     _x /= scaleRatio;
     _y /= scaleRatio;
     _z /= scaleRatio;
}

void Vect3D::setToUnitVector() {
     auto currentMag = length();
     _x /= currentMag;
     _y /= currentMag;
     _z /= currentMag;
}

bool Vect3D::operator<(const Vect3D & v) const {
     return (_x < v.getX() && _z < v.getZ() && _y < v.getY());
}
bool Vect3D::operator>(const Vect3D & v) const {
     return (_x > v.getX() && _z > v.getZ() && _y > v.getY());
}
bool Vect3D::operator<=(const Vect3D & v) const {
     return (_x <= v.getX() && _z <= v.getZ() && _y <= v.getY());
}
bool Vect3D::operator>=(const Vect3D & v) const {
     return (_x >= v.getX() && _z >= v.getZ() && _y >= v.getY());
}
bool Vect3D::operator==(const Vect3D & v) const {
     return (_x == v.getX() && _z == v.getZ() && _y == v.getY());
}
bool Vect3D::operator!=(const Vect3D & v) const {
     return !(*this == v);
}
