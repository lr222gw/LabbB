//Lowe Raivio - 9403245930
#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <math.h>

using namespace std;

class Shape {						//Shape �r en abstract klass d� den inneh�ller minst 1 virtuell funktion...

private:
	float height;					// Alla shapes har minst en h�jd, d� h�jd �r vad som g�r en shape unikt i v�rt program...


public:
	virtual float getVolume()const = 0;	//Alla klasser som �rver fr�n Shape m�ste implementera denna funktion...
	float getHeight() const;
	void setHeight(float height);

	virtual string toStringSpecific() const = 0;
	string toString() const;

	Shape &operator=(const Shape &ref);
	bool &operator==(const Shape &ref);

	Shape(const Shape &copy);		//V�r copyConstruktor
	Shape(float height = -1);		// agerar b�de som default konstruktor och konstruktor som tar emot height...

	virtual ~Shape();//TODO: dekonstruktorer ska vara virtuella p� basklassen (?)  MEN VARF�R, minns inte? 

};


#endif // !SHAPE_H
