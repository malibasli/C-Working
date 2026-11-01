#include<iostream>
#include "GradeBook.h"
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook(string name)
{	
	setCourseName(name);				// call set function to initialize courseName
	aCount = 0;						
	bCount = 0;						
	cCount = 0;					
	dCount = 0;						
	fCount = 0;						
}

// function that sets the course name
void GradeBook::setCourseName(string name)
{
	courseName = name;					// store the course name in the object
}

// function that gets the course name
string GradeBook::getCourseName()
{
	return courseName;					// return the object'S courseName
}

// function that displays a welcome message
void GradeBook::displayMessage()
{
	cout << "Welcome to the GradeBook for " << getCourseName() << "!" << endl;
}

// function that takes grades
void GradeBook::inputGrades()
{
	int grade;
	cout << "Enter the letter grades." << endl
		 << "Enter the EOF character to end input." << endl;
	
	while ((grade = cin.get()) != EOF)
	{
		switch(grade)
		{
			case 'A':
			case 'a':
				++aCount;
				break;
				
			case 'B':
			case 'b':
				++bCount;
				break;
				
			case 'C':
			case 'c':
				++cCount;
				break;
				
			case 'D':
			case 'd':
				++dCount;
				break;
		
			case 'F':
			case 'f':
				++fCount;
				break;
				
			case '\n':
			case '\t':
			case ' ':
				break;
			
			default: // catch all other characters
				cout << "Incorrect letter grade entered." 
				<< " Enter a new grade" << endl;
				break;				
		}
	}
}

// function that shows grade report
void GradeBook::displayGradeReport()
{
	cout << "\n\nNumber of students who received each letter grade:"
		 << "\nGrade A: " << aCount
		 << "\nGrade B: " << bCount
		 << "\nGrade C: " << cCount
		 << "\nGrade D: " << dCount
		 << "\nGrade F: " << fCount
		 << endl;
} 

