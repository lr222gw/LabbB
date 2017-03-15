//Lowe Raivio - 9403245930
#include "Cone.h"

Cone::Cone(float height, float radie)
	: Shape(height)
{
	this->radie = radie;
}

Cone::~Cone()
{
}

string Cone::toStringSpecific() const
{
	return  "| Radius Of Cone(rounded): " + to_string((int)this->getRadie());
}

float Cone::getVolume() const
{
	float PI = std::atan(1.0) * 4; //ett sätt att få fram PI 
				//arcTan 1 multiplicerat med 4 ger oss PI... (http://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c)

	return ((PI*pow(radie, 2) * this->getHeight()) / 3); 
				// (PI * (radie)^2 * height) / 3
}

float Cone::getRadie() const
{
	return this->radie;
}

void Cone::setRadie(float radie)
{
	this->radie = radie;
}

Cone & Cone::operator=(const Cone & ref)
{
	Shape::operator=(ref); //använder basklassens tilldelningsoperator

	this->radie = ref.radie;
	
	return *this;

}

Cone::Cone(const Cone & copy)
	:Shape(copy)			//använder basklassens copyConstruktor
{
	this->radie = copy.radie;
}
