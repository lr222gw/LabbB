//Lowe Raivio - 9403245930
#include "Shape.h"

string Shape::toString() const
{
	return "Height: " +to_string(int(this->getHeight())) + " | " + " Volume: " + to_string(this->getVolume()) + +" | " + this->toStringSpecific(); //returnerar str�ngen som subklasserna har...
} //typkastar till int f�r att slippa decimaler :)

Shape & Shape::operator=(const Shape & ref)
{
	this->height = ref.getHeight(); // enda att kopiera �ver �r height...
	return *this;					// returnerar this ocks�, ifall vi vill skriva s�h�r shape1 = shape2 = shape3...
}

bool & Shape::operator==(const Shape & ref)
{
	bool status = ref.height == this->height; // om de �r samma, true
	return status;
}

float Shape::getHeight() const
{
	return this->height; 
}

void Shape::setHeight(float height)
{
	this->height = height;
}


Shape::Shape(const Shape & copy)
{
	this->height = copy.height;
}

Shape::Shape(float height)
{
	this->height = height;
}

Shape::~Shape()
{
}
