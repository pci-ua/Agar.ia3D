#pragma once

template <typename composante>
class Vect2D {
private:
  composante x,z;

public:

  // Constructeurs ...
  Vect2D(composante x,composante z);
  Vect2D(const Vect2D & c) = default;
  ~Vect2D() = default;

  // Accesseurs ...
  composante getX() const { return x; }
  composante getZ() const { return z; }
  void setX(composante x) { this->x = x; }
  void setZ(composante z) { this->z = z; }

  // Opérateurs de comparaison
  bool operator<(const Vect2D & a) const;
  bool operator>(const Vect2D & a) const;
  bool operator<=(const Vect2D & a) const;
  bool operator>=(const Vect2D & a) const;
  bool operator==(const Vect2D & a) const;
  bool operator!=(const Vect2D & a) const;

  // Opérateurs arithmétique de base (Entre vecteur)
  Vect2D operator-(const Vect2D & a) const;
  Vect2D operator+(const Vect2D & a) const;
  Vect2D& operator+=(const Vect2D & a);
  Vect2D& operator-=(const Vect2D & a);

  // Opérateurs arithmétique de base (Entre vecteur et scalaire)
  Vect2D operator/(composante a) const;
  Vect2D operator*(composante a) const;
  Vect2D& operator/=(composante a);
  Vect2D& operator*=(composante a);

  // Fonction sur l'intensité sans changement sur la direction
  composante getMagnitude() const;
  void setMagnitude(composante a);
  void setUnitVect();

  // Fonction sur la direction sans changement sur l'intensité
  /// TO DO : méthode qui donne l'angle du vecteur par rapport à l'axe des abscices
  /// TO DO : méthode qui change l'orientation du vecteur sans changer l'intensité( nouvelle direction donnée en paramètre par un angle)
  /// TO DO : méthode qui retourne si deux vecteur sont colinéaire ou non(passage par discriminant ?)

  // Cartésien ➔ Polaire
  /// TO DO : Fonction d'obtention des données polaires

};

template class Vect2D<double>;
