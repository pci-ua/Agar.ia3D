#pragma once

#include "constante.hh"
#include "Modele/couleur.hh"

class Boule{

public:
	Boule(float taille);
	~Boule() = default;
	Boule(const Boule & c) = default;

	void draw() const;

	float getX() const{ return _posX;}
	float getZ() const{ return _posZ;}
	float getTaille() const{return _taille;}

	void setX(float x){this->_posX=x;}
	void setZ(float z){this->_posZ=z;}

	void setCouleur(Couleur couleur) { _couleur = couleur; }

protected:
	float _posX;
	float _posZ;
	float _taille;

	Couleur _couleur;
};
