
#include <iostream>
#include "TransRot.h"

int main() {
	TransRot p1, p2;

    p1.setXYZ(3,4,5);
    p1.translateAlongY(10);
    p1.printResult();
    p1.rotateAroundZ(90);
    p1.printResult();

    p2.setX(20);
    p2.setY(15);
    p2.setZ(50);
    p2.rotateAroundZ(135);
    p2.printResult();
    p2.updateCoordinates();
    p2.translateAlongZ(-20);
    p2.printResult();

    return 0;
}
