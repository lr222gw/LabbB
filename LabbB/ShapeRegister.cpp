//Lowe Raivio - 9403245930
#include "ShapeRegister.h"

bool ShapeRegister::checkUniqueHeight(float height)const
{//returnerar false om värdet redan finns...

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

	this->capOf_arrOfShapes = this->capOf_arrOfShapes + 2; //vi gör vår array dubbelt så stor...

	Shape **temp = new Shape*[this->capOf_arrOfShapes];
	// Skapar en dubbelpekare som vi ska använda för att förstora vår Array.

	for (int i = 0; i < this->amountOfShapes; i++) { //går igenom alla Shapes i min lista... 
		temp[i] = this->arrOfShapes[i];			// Kopierar pekarna adresserna till vår nya array
	}// OBS detta är ytlig kopiering, då vi inte vill ta bort vår array, bara berätta var den nya arrayen ska vara med de gamla pekarna

	delete[] this->arrOfShapes; 
	//vi raderar vår gamla "array hållare", NOTERA att elementen i arrayen fortfarande är kvar, och vi har adresserna till dessa i vår "temp" array...

	this->arrOfShapes = temp; 
	//Vi sätter vår "array hållare" till vår nya "array hållare" (array hållare = adressen till arrayen...) 


	for (int i = this->amountOfShapes; i < this->capOf_arrOfShapes; i++ ) { 
		//denna forloop kommer gå igenom ALLA element i vår array som inte har något värde
		// och sätta dem till nullpointers

		this->arrOfShapes[i] = nullptr;
	}


}

ShapeRegister::ShapeRegister(int cap)
{
	this->capOf_arrOfShapes = cap; //min standard för hur många shapes vi börjar vår array med... 2 enligt h-filen
	this->amountOfShapes = 0;
	this->arrOfShapes = new Shape*[this->capOf_arrOfShapes]; // arrayen ska vara så stor vi angivit för kapacitet...
								

	//Vi sätter även alla element i vår array till nullptrs, för att undvika eventuella buggar
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

	this->arrOfShapes = new Shape*[copy.capOf_arrOfShapes];// copy.arrOfShapes; // TODO: sätt till ny istället.. vi ska ju INTE göra ytlig kopiering
	

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

//TODO: Lärare, Kolla hit! 
//Notering till den som Checkar uppgiften, Det stod att jag skulle göra om denna operator till const. 
//Jag tyckte det lät lite konstigt så jag kollade med Mats Ola om jag verkligen skulle göra det.
//Mats sa:
//"Tilldelningsoperatorn kan ju inte vara konstant så jag antar att det är ekvivalensoperatorn som avses. Den hade Du väl inte gjort const?"
//Grejjen är ju den att jag inte har någon "==" operator så det gör mig ännu mer förvirrad :S 
//Kunde tyvärr inte kontakta dig som rättade min uppgift, Ali Hassan. Tydligen finns det ett några Ali Hassan på BTH, så det är svårt att veta vem man ska skicka till på ItsLearning :( 
ShapeRegister & ShapeRegister::operator=(const ShapeRegister & ref)
{	
	
	if (this != &ref) { // självtilldelnigns check! 

		//TODO: Lärare, Här är en fråga! :)
		//Lade till denna, testade utan. Får dock inga memory leaks konstigt nog :/  
		//Skummt, troligtvis testade jag utan innehåll i min lista. Måste klara sig då jag sätter till nullptr?...Testade att ta bort nullptrs, men fungerar ändå. :( 
		//Skulle vara intressant om jag kunde få feedback angående mer om dessa minnesläckor, borde ju få dem men 
		//jag får inte även när jag tar bort denna for-loop och kommenterade ut mina nullpointers i min expand ... Hmm
		for (int i = 0; i < this->nrOfShapes(); i++) {
			delete this->arrOfShapes[i];
		}
		delete[] this->arrOfShapes; //memory leak fix! 

		this->capOf_arrOfShapes = ref.capOf_arrOfShapes;
		this->amountOfShapes = ref.amountOfShapes;


		this->arrOfShapes = new Shape*[ref.capOf_arrOfShapes];// copy.arrOfShapes; // TODO: sätt till ny istället.. vi ska ju INTE göra ytlig kopiering

		Box *boxPtr = nullptr; 
		Cone *conePtr = nullptr;

		for (int i = 0; i < ref.amountOfShapes; i++) {

			boxPtr = dynamic_cast<Box*>(ref.arrOfShapes[i]);
			conePtr = dynamic_cast<Cone*>(ref.arrOfShapes[i]);
						

			if (boxPtr != nullptr) {
				this->arrOfShapes[i] = new Box(*boxPtr);	//*boxPtr;	// OBS djupkopiering!  //TODO: detta kan ha blivit fel, möjliglösning "new Shape(copy.arrOfShapes[i])" ...
			}											//
			

			if (conePtr != nullptr) {					//
				this->arrOfShapes[i] = new Cone(*conePtr);	//*conePtr;		
			}

			
		} // OBS vi behöver inte  sätta till nullpointers... det är redan gjort

	}

	return *this;
}

bool ShapeRegister::addCone(float height, float radie)
{
	bool success = false;	

	if (this->checkUniqueHeight(height)) {
		if (this->capOf_arrOfShapes == this->nrOfShapes()) {//utöka om det behövs...
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

		if (this->capOf_arrOfShapes == this->nrOfShapes()) { //utöka om det behövs...
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

	if (!this->checkUniqueHeight(height)) { //Om denna returnerar false så finns den och kan tas bort...
		for (int i = 0; i < this->amountOfShapes; i++) {
			if (this->arrOfShapes[i]->getHeight() == height) { 

				delete this->arrOfShapes[i];
				
				this->arrOfShapes[i] = this->arrOfShapes[this->amountOfShapes-1]; // sista elementet i arrayen byter plats med det aktuella...
						//ytlig kopiering, vi behöver bara det som finns på platsen... Så istället för att kopiera det låter vi adressen vara densamma 
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
	
		if (!this->checkUniqueHeight(height)) { //Om denna returnerar false så finns den och kan den redigeras
			for (int i = 0; i < this->amountOfShapes; i++) {
				if (this->arrOfShapes[i]->getHeight() == height) { // om höjden är samma så är det denna som ska modiferas...															   

																   //Vi har nu den rätta "Shapen", men är den av rätt typ? 

					Cone *conePtr = dynamic_cast<Cone*>(this->arrOfShapes[i]);

					if (conePtr != nullptr) { // om vår boxPekare inte är nullptr så är den av subklassen Box... 

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
	
		if (!this->checkUniqueHeight(height)) { //Om denna returnerar false så finns den och kan den redigeras
			for (int i = 0; i < this->amountOfShapes; i++) {
				if (this->arrOfShapes[i]->getHeight() == height) { // om höjden är samma så är det denna som ska modiferas...
					//dynamic cast, kontrollera om det är en box eller en shape, använd din castade pekare och editera den aktuella...

					//Vi har nu den rätta "Shapen", men är den av rätt typ? 

					Box *boxPtr = dynamic_cast<Box*>(this->arrOfShapes[i]);

					if (boxPtr != nullptr) { // om vår boxPekare inte är nullptr så är den av subklassen Box... 

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

		if (conePtr != nullptr) { // om vår boxPekare inte är nullptr så är den av subklassen Box... 

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

		if (boxPtr != nullptr) { // om vår boxPekare inte är nullptr så är den av subklassen Box... 

			counter++;
		}
	}

	return counter;
}

bool ShapeRegister::getAllShapesAsStrings(string * arr, int capOfArr) const
{
	bool status = false; 

	//textArrayen får INTE vara större än amountOfShapes... 
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

	//textArrayen får INTE vara större än this->nrOfCones()... 
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
