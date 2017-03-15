//Lowe Raivio - 9403245930
#ifndef SHAPE_REGISTER_SYSTEM_H
#define SHAPE_REGISTER_SYSTEM_H

#include <iostream>
#include "ShapeRegister.h"
#include "TestShapeRegisterr.h"
//skapar vårt ShapeRegister, är själva Loopen som vi loopar igenom, visar menyn, låtar användaren välja val i menyn

using namespace std; 

void init();

void doChoice(char choice, ShapeRegister &reg);

void showMenu();





#endif // !SHAPE_REGISTER_SYSTEM_H
