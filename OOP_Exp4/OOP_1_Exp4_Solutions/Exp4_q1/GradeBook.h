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
		void determineClassAverage(int);		// function that calculates class average
	private:
	string courseName; 						// course name for this GradeBook	
};

#endif
