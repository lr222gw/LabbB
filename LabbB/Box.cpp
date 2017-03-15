//Lowe Raivio - 9403245930
#include "Box.h"

Box::Box(float width, float length, float height)
	: Shape(height)		// Vi använders Shapes konstruktor för att ta hand om delarna vi ärver från shape.. nämligen height
{
	this->width = width;
	this->length = length;
}

Box::~Box()
{
}


float Box::getVolume() const
{
	return (this->width * this->length * this->getHeight());
}

float Box::getWidth() const
{
	return this->width;
}

float Box::getLength() const
{
	return this->length;
}

void Box::setLength(float length)
{
	this->length = length;
}

void Box::setWidth(float width)
{
	this->width = width;
}

Box::Box(const Box & copy)
	:Shape(copy)			// använder oss av basklassens konstruktor för att sätta height...
{
	this->length = copy.length;
	this->width = copy.width;

}

Box &Box::operator=(const Box & ref) 	
{
	Shape::operator=(ref); //Vi använder basklassens tilldelningsoperator

	this->length = ref.length;
	this->width = ref.width;

	return *this;
}

string Box::toStringSpecific() const
{
	return  "| Length Of Box: " + to_string((int)this->getLength()) + " Width Of Box: " + to_string((int)this->getWidth());
}
