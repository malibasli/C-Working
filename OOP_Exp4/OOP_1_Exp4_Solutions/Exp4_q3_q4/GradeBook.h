#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include<string>
using namespace std;

// GradeBook Class Definition
class GradeBook
{
public:
	
	GradeBook(string);					// constructor that initializes courseName
	void setCourseName(string);			// function that sets the course name
	string getCourseName();				// function that gets the course name
	void displayMessage();				// function that displays a welcome message
	void inputGrades();					// function that takes grades
	void displayGradeReport();			// function that shows grade report		
		
private:
	
	string courseName; 			// course name for this GradeBook	
	int aCount;					// number of A grade							
	int bCount;					// number of B grade							
	int cCount;					// number of C grade							
	int dCount;					// number of D grade							
	int fCount;					// number of F grade							
};

#endif

