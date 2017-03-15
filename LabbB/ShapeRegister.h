//Lowe Raivio - 9403245930
#ifndef SHAPE_REGISTER_H
#define SHAPE_REGISTER_H

#include "Shape.h"
#include "Box.h"	// Box och Cone inkluderas d� vi beh�ver kunna skapa dessa...
#include "Cone.h"

class ShapeRegister {
private:
	
	Shape** arrOfShapes; 
	int capOf_arrOfShapes;
	int amountOfShapes;

	bool checkUniqueHeight(float height) const; // privat d� den bara anv�nds inom klassen...
			//^hade varit b�ttre om den returnerade det ID i arrayen den fanns p� och "-1" om platsen var ledig... Hade blivit mindre for loopar...
	void expand_arrOfShapes();
public:

	ShapeRegister(int cap = 2);
	~ShapeRegister();

	ShapeRegister(const ShapeRegister & copy); // copy constructor...
	ShapeRegister &operator=(const ShapeRegister & ref);//v�r �verskuggning av tilldelningsoperatorn, "ref" f�r referens... vet inte om det �r ett bra val..

	bool addCone(float height, float radie);					// bool ber�ttar om funktionen lyckades...
	bool addBox(float height, float width, float length );
	
	bool removeShape(float height); // ta bort baserat p� h�jd

	bool editACone(float height, float radie, float newHeight);
	bool editABox(float height, float width, float length, float newHeight);

	int nrOfShapes()const;
	int nrOfCones()const;
	int nrOfboxes()const;

	bool getAllShapesAsStrings(string *arr, int capOfArr)const; //TODO string *arr eller string arr[] ? 
	bool getAllConesAsStrings(string *arr, int capOfArr)const;
	bool getAllBoxesAsStrings(string *arr, int capOfArr)const;



};

#endif // !SHAPE_REGISTER_H
