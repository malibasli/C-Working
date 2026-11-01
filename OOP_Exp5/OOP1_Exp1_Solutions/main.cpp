#include<iostream>
#include "GradeBook.h"
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand(time(0));	
	
	// Define array with size of student which is static public data member and initialize to zero.
	int grades[GradeBook::students]={0.0};
	// Assign each student's grade randomly between 0-100
    for(int i=0;i<GradeBook::students;++i)
        grades[i] = rand()%101;
    // create an object
    GradeBook p1("Programming",grades);
    // call displayMessage function
    p1.displayMessage();
    // call processGrades function
    p1.processGrades();
}

