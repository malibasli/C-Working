#include <iostream>
#include "ccs.h"

using namespace std;

int main(int argc, char** argv) {
    CCS myCCS(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0);
    
    do {
        myCCS.printMenu();
        myCCS.setCoordinates();
        myCCS.printCoordinates();
    } while (myCCS.getChoice() != 5);
    
    return 0;
}
