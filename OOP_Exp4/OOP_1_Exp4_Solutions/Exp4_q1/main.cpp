#include<iostream>
#include "GradeBook.h"
using namespace std;

int main()
{
	GradeBook myGradeBook("Advanced Programming");			// create an object
	
	myGradeBook.displayMessage();							// call displayMessage function
	myGradeBook.determineClassAverage(5);					// call determineClassAverage function
}
