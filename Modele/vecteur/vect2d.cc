#include "vect2d.hh"

#include <math.h> // Pour racine carré et puissance

template <typename composante>
Vect2D<composante>::Vect2D(composante _x,composante _z)
 :x(_x),z(_z) {}

// Opérateurs de comparaison
template <typename composante>
bool Vect2D<composante>::operator<(const Vect2D<composante> & a) const
  { return ( getX() < a.getX() ) && ( getZ() < a.getZ() ); }

template <typename composante>
bool Vect2D<composante>::operator>(const Vect2D<composante> & a) const
  { return ( getX() > a.getX() ) && ( getZ() > a.getZ() ); }

template <typename composante>
bool Vect2D<composante>::operator<=(const Vect2D<composante> & a) const
  { return ( getX() <= a.getX() ) && ( getZ() <= a.getZ() ); }

template <typename composante>
bool Vect2D<composante>::operator>=(const Vect2D<composante> & a) const
  { return ( getX() >= a.getX() ) && ( getZ() >= a.getZ() ); }

template <typename composante>
bool Vect2D<composante>::operator==(const Vect2D<composante> & a) const
  { return ( getX() == a.getX() ) && ( getZ() == a.getZ() ); }

template <typename composante>
bool Vect2D<composante>::operator!=(const Vect2D<composante> & a) const
  { return ( getX() != a.getX() ) || ( getZ() != a.getZ() ); }


// Opérateurs arithmétique
template <typename composante>
Vect2D<composante> Vect2D<composante>::operator-(const Vect2D<composante> & a) const
  { return { (getX()-a.getX()) , (getZ()-a.getZ()) }; }

template <typename composante>
Vect2D<composante> Vect2D<composante>::operator+(const Vect2D<composante> & a) const
  { return { (getX()+a.getX()) , (getZ()+a.getZ()) }; }

template <typename composante>
Vect2D<composante> Vect2D<composante>::operator/(composante a) const
  { return { (getX()/a) , (getZ()/a) }; }

template <typename composante>
Vect2D<composante> Vect2D<composante>::operator*(composante a) const
  { return { (getX()*a) , (getZ()*a) }; }


// Opérateurs arithmétique (version in-place)
template <typename composante>
Vect2D<composante>& Vect2D<composante>::operator+=(const Vect2D<composante> & a) {
  x += a.getX();
  z += a.getZ();

  return *this;
}

template <typename composante>
Vect2D<composante>& Vect2D<composante>::operator-=(const Vect2D<composante> & a) {
  x -= a.getX();
  z -= a.getZ();

  return *this;
}

template <typename composante>
Vect2D<composante>& Vect2D<composante>::operator/=(composante a) {
  x /= a;
  z /= a;

  return *this;
}

template <typename composante>
Vect2D<composante>& Vect2D<composante>::operator*=(composante a) {
  x *= a;
  z *= a;

  return *this;
}


// Fonction sur l'intensité sans changement sur la direction
template <typename composante>
composante Vect2D<composante>::getMagnitude() const
  { return sqrt(pow(x,2)+pow(z,2)); }

template <typename composante>
void Vect2D<composante>::setMagnitude(composante a) {
  composante scaleRatio = a / getMagnitude();
  x *= scaleRatio;
  z *= scaleRatio;
}

template <typename composante>
void Vect2D<composante>::setUnitVect() {
  composante mag = getMagnitude();
  x /= mag;
  z /= mag;
}
