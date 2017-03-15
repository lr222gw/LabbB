//Lowe Raivio - 9403245930
#include "ShapeRegister.h"

bool ShapeRegister::checkUniqueHeight(float height)const
{//returnerar false om v�rdet redan finns...

	bool isUnique = true;

	for (int i = 0; i < this->amountOfShapes; i++) {
		if (this->arrOfShapes[i]->getHeight() == height) {
			isUnique = false;
		}
	}

	return isUnique;
}

void ShapeRegister::expand_arrOfShapes()
{

	this->capOf_arrOfShapes = this->capOf_arrOfShapes + 2; //vi g�r v�r array dubbelt s� stor...

	Shape **temp = new Shape*[this->capOf_arrOfShapes];
	// Skapar en dubbelpekare som vi ska anv�nda f�r att f�rstora v�r Array.

	for (int i = 0; i < this->amountOfShapes; i++) { //g�r igenom alla Shapes i min lista... 
		temp[i] = this->arrOfShapes[i];			// Kopierar pekarna adresserna till v�r nya array
	}// OBS detta �r ytlig kopiering, d� vi inte vill ta bort v�r array, bara ber�tta var den nya arrayen ska vara med de gamla pekarna

	delete[] this->arrOfShapes; 
	//vi raderar v�r gamla "array h�llare", NOTERA att elementen i arrayen fortfarande �r kvar, och vi har adresserna till dessa i v�r "temp" array...

	this->arrOfShapes = temp; 
	//Vi s�tter v�r "array h�llare" till v�r nya "array h�llare" (array h�llare = adressen till arrayen...) 


	for (int i = this->amountOfShapes; i < this->capOf_arrOfShapes; i++ ) { 
		//denna forloop kommer g� igenom ALLA element i v�r array som inte har n�got v�rde
		// och s�tta dem till nullpointers

		this->arrOfShapes[i] = nullptr;
	}


}

ShapeRegister::ShapeRegister(int cap)
{
	this->capOf_arrOfShapes = cap; //min standard f�r hur m�nga shapes vi b�rjar v�r array med... 2 enligt h-filen
	this->amountOfShapes = 0;
	this->arrOfShapes = new Shape*[this->capOf_arrOfShapes]; // arrayen ska vara s� stor vi angivit f�r kapacitet...
								

	//Vi s�tter �ven alla element i v�r array till nullptrs, f�r att undvika eventuella buggar
	for (int i = 0; i < this->capOf_arrOfShapes; i++) {
		this->arrOfShapes[i] = nullptr;
	}


}

ShapeRegister::~ShapeRegister()
{
	
	for (int i = 0; i < this->amountOfShapes; i++) {
		delete this->arrOfShapes[i];
	}

	delete[] this->arrOfShapes; 

}

ShapeRegister::ShapeRegister(const ShapeRegister & copy)
{	
	this->capOf_arrOfShapes = copy.capOf_arrOfShapes;
	this->amountOfShapes = copy.amountOfShapes;

	this->arrOfShapes = new Shape*[copy.capOf_arrOfShapes];// copy.arrOfShapes; // TODO: s�tt till ny ist�llet.. vi ska ju INTE g�ra ytlig kopiering
	

	Box *boxPtr = nullptr;
	Cone *conePtr = nullptr;

	for (int i = 0; i < copy.amountOfShapes; i++) {

		boxPtr = dynamic_cast<Box*>(copy.arrOfShapes[i]);
		conePtr = dynamic_cast<Cone*>(copy.arrOfShapes[i]);


		if (boxPtr != nullptr) {
			this->arrOfShapes[i] = new Box(*boxPtr);	
		}											


		if (conePtr != nullptr) {					
			this->arrOfShapes[i] = new Cone(*conePtr);	
		}


	} 
}

//TODO: L�rare, Kolla hit! 
//Notering till den som Checkar uppgiften, Det stod att jag skulle g�ra om denna operator till const. 
//Jag tyckte det l�t lite konstigt s� jag kollade med Mats Ola om jag verkligen skulle g�ra det.
//Mats sa:
//"Tilldelningsoperatorn kan ju inte vara konstant s� jag antar att det �r ekvivalensoperatorn som avses. Den hade Du v�l inte gjort const?"
//Grejjen �r ju den att jag inte har n�gon "==" operator s� det g�r mig �nnu mer f�rvirrad :S 
//Kunde tyv�rr inte kontakta dig som r�ttade min uppgift, Ali Hassan. Tydligen finns det ett n�gra Ali Hassan p� BTH, s� det �r sv�rt att veta vem man ska skicka till p� ItsLearning :( 
ShapeRegister & ShapeRegister::operator=(const ShapeRegister & ref)
{	
	
	if (this != &ref) { // sj�lvtilldelnigns check! 

		//TODO: L�rare, H�r �r en fr�ga! :)
		//Lade till denna, testade utan. F�r dock inga memory leaks konstigt nog :/  
		//Skummt, troligtvis testade jag utan inneh�ll i min lista. M�ste klara sig d� jag s�tter till nullptr?...Testade att ta bort nullptrs, men fungerar �nd�. :( 
		//Skulle vara intressant om jag kunde f� feedback ang�ende mer om dessa minnesl�ckor, borde ju f� dem men 
		//jag f�r inte �ven n�r jag tar bort denna for-loop och kommenterade ut mina nullpointers i min expand ... Hmm
		for (int i = 0; i < this->nrOfShapes(); i++) {
			delete this->arrOfShapes[i];
		}
		delete[] this->arrOfShapes; //memory leak fix! 

		this->capOf_arrOfShapes = ref.capOf_arrOfShapes;
		this->amountOfShapes = ref.amountOfShapes;


		this->arrOfShapes = new Shape*[ref.capOf_arrOfShapes];// copy.arrOfShapes; // TODO: s�tt till ny ist�llet.. vi ska ju INTE g�ra ytlig kopiering

		Box *boxPtr = nullptr; 
		Cone *conePtr = nullptr;

		for (int i = 0; i < ref.amountOfShapes; i++) {

			boxPtr = dynamic_cast<Box*>(ref.arrOfShapes[i]);
			conePtr = dynamic_cast<Cone*>(ref.arrOfShapes[i]);
						

			if (boxPtr != nullptr) {
				this->arrOfShapes[i] = new Box(*boxPtr);	//*boxPtr;	// OBS djupkopiering!  //TODO: detta kan ha blivit fel, m�jligl�sning "new Shape(copy.arrOfShapes[i])" ...
			}											//
			

			if (conePtr != nullptr) {					//
				this->arrOfShapes[i] = new Cone(*conePtr);	//*conePtr;		
			}

			
		} // OBS vi beh�ver inte  s�tta till nullpointers... det �r redan gjort

	}

	return *this;
}

bool ShapeRegister::addCone(float height, float radie)
{
	bool success = false;	

	if (this->checkUniqueHeight(height)) {
		if (this->capOf_arrOfShapes == this->nrOfShapes()) {//ut�ka om det beh�vs...
			this->expand_arrOfShapes();
		}

		this->arrOfShapes[this->amountOfShapes] = new Cone(height, radie);

		this->amountOfShapes++;

		success = true;
	}
	return success;
}

bool ShapeRegister::addBox(float height, float width, float length)
{
	bool success = false;

	if (this->checkUniqueHeight(height)) {

		if (this->capOf_arrOfShapes == this->nrOfShapes()) { //ut�ka om det beh�vs...
			this->expand_arrOfShapes();
		}

		this->arrOfShapes[this->amountOfShapes] = new Box(width, length, height);

		this->amountOfShapes++;

		success = true;
	}
	return success;
}

bool ShapeRegister::removeShape(float height)
{
	bool success = false;

	if (!this->checkUniqueHeight(height)) { //Om denna returnerar false s� finns den och kan tas bort...
		for (int i = 0; i < this->amountOfShapes; i++) {
			if (this->arrOfShapes[i]->getHeight() == height) { 

				delete this->arrOfShapes[i];
				
				this->arrOfShapes[i] = this->arrOfShapes[this->amountOfShapes-1]; // sista elementet i arrayen byter plats med det aktuella...
						//ytlig kopiering, vi beh�ver bara det som finns p� platsen... S� ist�llet f�r att kopiera det l�ter vi adressen vara densamma 
				this->amountOfShapes--;
				success = true;
			}
		}
	}
	return success;
}

bool ShapeRegister::editACone(float height, float radie, float newHight)
{
	bool success = false;
	if (this->checkUniqueHeight(newHight)) {
	
		if (!this->checkUniqueHeight(height)) { //Om denna returnerar false s� finns den och kan den redigeras
			for (int i = 0; i < this->amountOfShapes; i++) {
				if (this->arrOfShapes[i]->getHeight() == height) { // om h�jden �r samma s� �r det denna som ska modiferas...															   

																   //Vi har nu den r�tta "Shapen", men �r den av r�tt typ? 

					Cone *conePtr = dynamic_cast<Cone*>(this->arrOfShapes[i]);

					if (conePtr != nullptr) { // om v�r boxPekare inte �r nullptr s� �r den av subklassen Box... 

						conePtr->setRadie(radie);
						conePtr->setHeight(newHight);

						success = true;
					}

				}
			}
		}
	}
	return success;
}

bool ShapeRegister::editABox(float height, float width, float length, float newHight)
{
	bool success = false;
	if (this->checkUniqueHeight(newHight)) {
	
		if (!this->checkUniqueHeight(height)) { //Om denna returnerar false s� finns den och kan den redigeras
			for (int i = 0; i < this->amountOfShapes; i++) {
				if (this->arrOfShapes[i]->getHeight() == height) { // om h�jden �r samma s� �r det denna som ska modiferas...
					//dynamic cast, kontrollera om det �r en box eller en shape, anv�nd din castade pekare och editera den aktuella...

					//Vi har nu den r�tta "Shapen", men �r den av r�tt typ? 

					Box *boxPtr = dynamic_cast<Box*>(this->arrOfShapes[i]);

					if (boxPtr != nullptr) { // om v�r boxPekare inte �r nullptr s� �r den av subklassen Box... 

						boxPtr->setLength(length);
						boxPtr->setWidth(width);
						boxPtr->setHeight(newHight);

						success = true;
					}
				
				}
			}
		}
	}
	return success;
}

int ShapeRegister::nrOfShapes() const
{
	return this->amountOfShapes;
}

int ShapeRegister::nrOfCones() const
{
	int counter = 0;


	for (int i = 0; i < this->amountOfShapes; i++) {
															
		Cone *conePtr = dynamic_cast<Cone*>(this->arrOfShapes[i]);

		if (conePtr != nullptr) { // om v�r boxPekare inte �r nullptr s� �r den av subklassen Box... 

			counter++;
		}
		
	}
	
	return counter;
}

int ShapeRegister::nrOfboxes() const
{
	int counter = 0;

	for (int i = 0; i < this->amountOfShapes; i++) {

		Box *boxPtr = dynamic_cast<Box*>(this->arrOfShapes[i]);

		if (boxPtr != nullptr) { // om v�r boxPekare inte �r nullptr s� �r den av subklassen Box... 

			counter++;
		}
	}

	return counter;
}

bool ShapeRegister::getAllShapesAsStrings(string * arr, int capOfArr) const
{
	bool status = false; 

	//textArrayen f�r INTE vara st�rre �n amountOfShapes... 
	if (capOfArr >= this->amountOfShapes) {
		for (int i = 0; i < capOfArr; i++) {
			arr[i] = this->arrOfShapes[i]->toString();
		}
		status = true;
	}	

	return status;
}

bool ShapeRegister::getAllConesAsStrings(string * arr, int capOfArr) const
{
	bool status = false;
	int coneCounter = 0;

	//textArrayen f�r INTE vara st�rre �n this->nrOfCones()... 
	if (capOfArr >= this->nrOfCones()) {

		Cone *tempArr = new Cone[this->nrOfCones()];

		Cone *conePtr = nullptr;
		for (int i = 0; i < this->amountOfShapes; i++) {

			conePtr = dynamic_cast<Cone*>(this->arrOfShapes[i]);
			
			if (conePtr != nullptr) {

				tempArr[coneCounter] = *conePtr;
				
				coneCounter++;
			}			
		}

		for (int i = 0; i < coneCounter; i++) { 
			arr[i] = tempArr[i].toString();
		}		

		delete[] tempArr; 
	}

	return status;
}

bool ShapeRegister::getAllBoxesAsStrings(string * arr, int capOfArr) const
{
	bool status = false;
	int boxCounter = 0;
	
	if (capOfArr >= this->nrOfCones()) {

		Box *tempArr = new Box[this->nrOfCones()];

		Box *boxPtr = nullptr;
		for (int i = 0; i < this->amountOfShapes; i++) {

			boxPtr = dynamic_cast<Box*>(this->arrOfShapes[i]);

			if (boxPtr != nullptr) {

				tempArr[boxCounter] = *boxPtr;

				boxCounter++;
			}
		}

		for (int i = 0; i < boxCounter; i++) { 
			arr[i] = tempArr[i].toString();
		}

		delete[] tempArr; 
	}

	return status;
}
