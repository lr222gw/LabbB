//Lowe Raivio - 9403245930
#ifndef SHAPE_REGISTER_SYSTEM_H
#define SHAPE_REGISTER_SYSTEM_H

#include <iostream>
#include "ShapeRegister.h"
#include "TestShapeRegisterr.h"
//skapar v�rt ShapeRegister, �r sj�lva Loopen som vi loopar igenom, visar menyn, l�tar anv�ndaren v�lja val i menyn

using namespace std; 

void init();

void doChoice(char choice, ShapeRegister &reg);

void showMenu();





#endif // !SHAPE_REGISTER_SYSTEM_H
