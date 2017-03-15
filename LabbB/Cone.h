//Lowe Raivio - 9403245930
#ifndef CONE_H
#define CONE_H

#include "Shape.h"

class Cone : public Shape { //cone �rver fr�n shape...
private:
	float radie; // Unikt f�r Cone..

public:


	string toStringSpecific() const;

	float getVolume()const;
	float getRadie()const;
	void setRadie(float radie);

	Cone &operator=(const Cone &ref);
	
	Cone(const Cone &copy);				//copy konstruktor
	Cone(float height = -1.0f, float radie = -1.0f);	//konstruktor och detfault konstruktor
	~Cone();

};

#endif // !CONE_H
