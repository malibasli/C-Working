#include<iostream>
#include<iomanip>												
#include "GradeBook.h"
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook(string name)
{	
	setCourseName(name);				// call set function to initialize courseName
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

// function that calculates class average
void GradeBook::determineClassAverage(int NOS)
{
	double total = 0;						// total grades that come from user
	int gradeCounter = 0;		// number of student initially	
	while (gradeCounter < NOS)											
	{																
		cout << "Enter the Grade " << gradeCounter+1 << "="; 			
		int grade = 0;
		cin >> grade;
		total = total + grade;			 // total grade			
		gradeCounter = gradeCounter + 1; // total five students	
		
	}															
	double average = total / NOS; 			// average grade calculation
	cout << "\nClass average is " << average << endl;
}

// function that calculates class average
void GradeBook::determineClassAverage()
{
	double total = 0;						// total grades that come from user
	double gradeCounter = 0;		// number of student initially		

	cout << "Enter the grade or -1 to quit ";							
	int grade = 0;
	cin >> grade;
	while (grade!=-1)					// Sentinel or signal value												
	{																	
		total = total + grade;			 // total grade			
		gradeCounter = gradeCounter + 1; // total students	
		cout << "Enter the grade or -1 to quit: ";						
		cin >> grade;												
	}																	

	if(gradeCounter !=0)													
	{																		
		double average = static_cast <double> (total) / gradeCounter;		
		cout << setprecision(2) << fixed;									
		cout << "Class average is " << average << endl;
	}																		
	else
		cout << "No grades were entered" << endl;
}
