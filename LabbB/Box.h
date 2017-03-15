//Lowe Raivio - 9403245930
#ifndef BOX_H
#define BOX_H

#include "Shape.h"

class Box : public Shape{ //Box �rver fr�n shape...

private:
	float width;  // Width och length �r unikt f�r v�r box... 
	float length;

public:

	Box(float width =-1.0f, float length = -1.0f, float height = -1.0f); // konstruktor och defaultkonstruktor
	~Box();

	float getVolume()const;
	float getWidth()const;
	float getLength()const;
	void setLength(float length);
	void setWidth(float width);

	Box(const Box &copy);

	Box &operator=(const Box &ref);

	string toStringSpecific() const;

};

#endif // !BOX_H
