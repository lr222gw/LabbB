//Lowe Raivio - 9403245930
#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <math.h>

using namespace std;

class Shape {						//Shape är en abstract klass då den innehåller minst 1 virtuell funktion...

private:
	float height;					// Alla shapes har minst en höjd, då höjd är vad som gör en shape unikt i vårt program...


public:
	virtual float getVolume()const = 0;	//Alla klasser som ärver från Shape måste implementera denna funktion...
	float getHeight() const;
	void setHeight(float height);

	virtual string toStringSpecific() const = 0;
	string toString() const;

	Shape &operator=(const Shape &ref);
	bool &operator==(const Shape &ref);

	Shape(const Shape &copy);		//Vår copyConstruktor
	Shape(float height = -1);		// agerar både som default konstruktor och konstruktor som tar emot height...

	virtual ~Shape();//TODO: dekonstruktorer ska vara virtuella på basklassen (?)  MEN VARFÖR, minns inte? 

};


#endif // !SHAPE_H
