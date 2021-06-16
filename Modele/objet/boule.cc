#include "boule.hh"

Boule::Boule(Vect2D<double> _position,double _taille)
  :position(_position),taille(_taille) {}

// Accesseurs ...
Vect2D<double> Boule::getPosition() const { return position; }
double Boule::getTaille() const { return taille; }
Vect2D<double>& Boule::getPosition() { return position; }
void Boule::setTaille(double t) { taille = t; }

// Méthodes ...
bool Boule::collision(const Boule & b) const {
  auto positionRelative = getPosition() - b.getPosition();
  return (positionRelative.getMagnitude()) < (getTaille() + b.getTaille());
}
