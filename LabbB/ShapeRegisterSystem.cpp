//Lowe Raivio - 9403245930
#include "ShapeRegisterSystem.h"

void init()
{

	char choice = 'a';
	ShapeRegister *reg = new ShapeRegister();

	while (choice != 'q') {
		
		showMenu();		
				
		cin >> choice;
		cin.ignore();
		doChoice(choice, *reg);

	}


	delete reg;

}
void showInventory(ShapeRegister &reg) {

	int arrLength = reg.nrOfShapes();

	if (arrLength != 0) {
		string *arr = new string[arrLength];

		reg.getAllShapesAsStrings(arr, arrLength);

		for (int i = 0; i < arrLength; i++) {
			cout << arr[i] << endl;
		}	
		delete[] arr;
	}
	else {
		cout << "Nothing in inventory" << endl;
	}

	
}

void showInventoryCone(ShapeRegister &reg) {

	int arrLength = reg.nrOfCones();
	if (arrLength != 0) {
		string *arr = new string[arrLength];
		reg.getAllConesAsStrings(arr, arrLength);

		for (int i = 0; i < arrLength; i++) {
			cout << arr[i] << endl;
		}

		delete[] arr;
	}
	else {
		cout << "No Cones in inventory" << endl;
	}


}
void showInventoryBox(ShapeRegister &reg) {
	int arrLength = reg.nrOfboxes();

	if (arrLength != 0) {
		string *arr = new string[arrLength];
		reg.getAllBoxesAsStrings(arr, arrLength);

		for (int i = 0; i < arrLength; i++) {
			cout << arr[i] << endl;
		}
		delete[] arr;
	}
	else {
		cout << "No Boxes in inventory" << endl;
	}
	
}

void addACone(ShapeRegister &reg) {
	float height, radius;
	cout << "Type in the Height" << endl;
	cin >> height; 
	cout << "Type in the Radius" << endl;
	cin >> radius;

	if (!reg.addCone(height, radius)) {
		cout << "a shape with that Height already exists" << endl;
	}
	else {
		cout << "The shape was added" << endl;
	}

}

void addABox(ShapeRegister &reg) {
	float height, width, length;
	cout << "Type in the Height" << endl;
	cin >> height;
	cout << "Type in the Width" << endl;
	cin >> width;
	cout << "Type in the Length" << endl;
	cin >> length;

	if (!reg.addBox(height, width, length)) {
		cout << "a shape with that Height already exists" << endl;
	}
	else {
		cout << "The shape was added" << endl;
	}

}
void editCone(ShapeRegister &reg) {
	float height, radius, newHeight;
	cout << "Type in the Height of the Cone you want to edit" << endl;
	cin >> height;
	cout << "Type in the new Radius" << endl;
	cin >> radius;
	cout << "Type in the new Height" << endl;
	cin >> newHeight;



	if (!reg.editACone(height, radius, newHeight)) {
		cout << "No Cone with that height exists" << endl;
	}
	else {
		cout << "The cone was edited" << endl;
	}
}

void editBox(ShapeRegister &reg) {
	float height, length, width, newHeight;
	cout << "Type in the Height of the Box you want to edit" << endl;
	cin >> height;
	cout << "Type in the new Width" << endl;
	cin >> width;
	cout << "Type in the new length" << endl;
	cin >> length;
	cout << "Type in the new Height" << endl;
	cin >> newHeight;


	if (!reg.editABox(height,width, length, newHeight)) {
		cout << "No Box with that height exists" << endl;
	}
	else {
		cout << "The box was edited" << endl;
	}
}

void removeShape(ShapeRegister &reg) {

	float height;
	cout << "Type in the Height of the Shape you want to remove" << endl;
	cin >> height;

	if (!reg.removeShape(height)) {
		cout << "No Shape with that height exists" << endl;
	}
	else {
		cout << "The Shape was removed" << endl;
	}

	
}

void doChoice(char choice, ShapeRegister &reg )
{
	switch (choice) {
	case '1': {

		showInventory(reg);

	}
		break;
	case '2': {
		showInventoryCone(reg);
	}
		break;
	case '3': {
		showInventoryBox(reg);
	}
		break;
	case '4': {
		addACone(reg);
	}
		break;
	case '5': {
		addABox(reg);
	}
		break;
	case '6': {
		editCone(reg);
	}
		break;
	case '7': {
		editBox(reg);
	}
		break;
	case '8': {
		removeShape(reg);
	}
		 break;
	case '9': {
		test();
	}
		break;
	case 'q': {
		cout << "Good Bye\n";
	}
			  break;
	default: {
		cout << "not a valid choice" << endl;
	}

	}
}

void showMenu()
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "1. Show inventory" << endl;
	cout << "2. Show only Cones" << endl;
	cout << "3. Show only Boxes" << endl;
	cout << "4. Add a Cone" << endl;
	cout << "5. Add a Box" << endl;
	cout << "6. Edit a Cone" << endl;
	cout << "7. Edit a Box" << endl;
	cout << "8. Remove a Shape" << endl;
	cout << "9. Run testCode" << endl;	
	cout << "q. stänga av programmet..." << endl;

	cout << "-----------------------------------------------------------------" << endl;
}
