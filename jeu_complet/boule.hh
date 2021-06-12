#pragma once

#include "Modele/couleur.hh"
#include "Modele/vect2d.hh"

class Boule{

public:
	Boule(float taille);
	~Boule() = default;
	Boule(const Boule & c) = default;

	virtual void draw() const;

	Vect2D getPosition() const { return _position; }
	Vect2D& getPosition() { return _position; }
	float getTaille() const{return _taille;}

	void setPosition(Vect2D pos) { _position = pos; }
	void setCouleur(Couleur couleur) { _couleur = couleur; }

	bool collision(const Boule & b) const;

protected:
	float _taille;
	Vect2D _position;
	Couleur _couleur;
};
