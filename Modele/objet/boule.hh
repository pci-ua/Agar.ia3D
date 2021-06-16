#pragma once

#include "../vecteur/vect2d.hh"

class Boule {
private:
  Vect2D<double> position;
  double taille;

public:

  // Constructeurs ...
  Boule(Vect2D<double> p,double taille);
  Boule(const Boule & c) = default;
  ~Boule() = default;

  // Accesseurs ...
  Vect2D<double> getPosition() const;
  Vect2D<double>& getPosition();
  double getTaille() const;
  void setTaille(double t);

  // Méthodes ...
  bool collision(const Boule & b) const;

};
