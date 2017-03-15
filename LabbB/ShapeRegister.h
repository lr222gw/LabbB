//Lowe Raivio - 9403245930
#ifndef SHAPE_REGISTER_H
#define SHAPE_REGISTER_H

#include "Shape.h"
#include "Box.h"	// Box och Cone inkluderas då vi behöver kunna skapa dessa...
#include "Cone.h"

class ShapeRegister {
private:
	
	Shape** arrOfShapes; 
	int capOf_arrOfShapes;
	int amountOfShapes;

	bool checkUniqueHeight(float height) const; // privat då den bara används inom klassen...
			//^hade varit bättre om den returnerade det ID i arrayen den fanns på och "-1" om platsen var ledig... Hade blivit mindre for loopar...
	void expand_arrOfShapes();
public:

	ShapeRegister(int cap = 2);
	~ShapeRegister();

	ShapeRegister(const ShapeRegister & copy); // copy constructor...
	ShapeRegister &operator=(const ShapeRegister & ref);//vår överskuggning av tilldelningsoperatorn, "ref" för referens... vet inte om det är ett bra val..

	bool addCone(float height, float radie);					// bool berättar om funktionen lyckades...
	bool addBox(float height, float width, float length );
	
	bool removeShape(float height); // ta bort baserat på höjd

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
