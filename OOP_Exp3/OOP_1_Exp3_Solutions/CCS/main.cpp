#include <iostream>
#include "CCS.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	CCS myCCS(0.0,0.0,0.0,0.0,0.0,0.0,0);
	myCCS.printMenu();
	myCCS.setCoordinates();
	myCCS.printCoordinates();
	
	return 0;
}
