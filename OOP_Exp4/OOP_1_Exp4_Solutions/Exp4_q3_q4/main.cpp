#include<iostream>
#include "GradeBook.h"
using namespace std;

int main()
{
	GradeBook myGradeBook("Advanced Programming");
	
	myGradeBook.displayMessage();
	myGradeBook.inputGrades();
	myGradeBook.displayGradeReport();					
}
