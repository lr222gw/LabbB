//Lowe Raivio - 9403245930
#include <crtdbg.h>
#include <iostream> //F�r setLocale
#include "ShapeRegisterSystem.h"

using namespace std;

int main() {
	setlocale(0, "swedish");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // F�r debug

	init();
	


	return 0;
}