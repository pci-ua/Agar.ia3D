#pragma once

#include "constante.hh"

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
	void setr(float r){this->_r=r;}
	void setg(float g){this->_g=g;}
	void setb(float b){this->_b=b;}

protected:
	float _posX;
	float _posZ;
	float _taille;

	float _r;
	float _g;
	float _b;
};
