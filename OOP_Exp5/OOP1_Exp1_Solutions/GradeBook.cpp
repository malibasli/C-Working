#include<iostream>
#include<iomanip>
#include "GradeBook.h"
using namespace std;

// constructor initializes courseName and grades array
GradeBook::GradeBook(string cName, const int gradesArray [])
{
	// initialize courseName
    setCourseName(cName);
    // copy grades from gradesArray to grades data member
	for (int i = 0; i < students; ++i )
		grades[i]=gradesArray[i];
}

// function to set the course name
void GradeBook::setCourseName(string name)
{
    courseName = name;
}

// function to retrieve the course name
string GradeBook::getCourseName(void)
{
    return courseName;
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage(void)
{
	// this statement calls getCourseName to get the name of the course 
    cout<<"Welcome to the grade book for "<<getCourseName()<<"!"<<endl;
    cout<<endl;
}

// find minimum grade
int GradeBook::getMinimum(void)
{
	// Assign the first values of array as minimum
    int minimum = grades[0];
    // loop through grades array
    for(int i=1;i<students;++i){
    	// if current grade lower than minimum, assign it to minimum
        if(grades[i]<minimum)
            minimum = grades[i];
    }
    return minimum;
}

// find maximum grade
int GradeBook::getMaximum(void)
{
	// Assign the first values of array as maximum
    int maximum = grades[0];
    // loop through grades array
    for(int i=1;i<students;++i){
    	// if current grade higher than maximum, assign it to maximum
        if(grades[i]>maximum)
            maximum = grades[i];
    }
    return maximum;
}

// determine average grade for test
double GradeBook::getAverage(void)
{
	// initialize avg as 0
    double avg = 0;
    // sum grades in array
    for(int i=0;i<students;++i){
        avg+=grades[i];
    }
    // return average of grades
    return avg/students;
}

// output bar chart displaying grade distribution
void GradeBook::outputBarChart(void)
{
	// Define number of bin
    int binNumber = 5;
    // stores frequency of grades in each bin
    int frequencyGrades[binNumber]={0};
    // for each grade, increment the appropriate frequency
    for(int i=0;i<students;++i){
        frequencyGrades[grades[i]/(100/binNumber)]++;
    }
    // for each grade frequency, print bar in chart
    for(int i=0;i<binNumber;++i){
    	// output bar labels ("0-10:", ..., "90-100:")
        cout<<right<<setw(2)<<i*(100/binNumber)<<"-"<<right<<setw(3)<<(i+1)*(100/binNumber)<<" ";
        // print bar of asterisks
        for(int j=0;j<frequencyGrades[i];++j)
            cout<<"*";
        // start a new line of output
        cout<<endl;
    }
}

// output the contents of the grades array
void GradeBook::outputGrades(void)
{   
	cout<<"Grades:"; 
	// output each student's grade
    for(int i=0;i<GradeBook::students;++i){
        cout<<grades[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

// perform various operations on the data
void GradeBook::processGrades(void)
{
	// output grades array
	outputGrades();
	// display average of all grades and minimum and maximum grades
    cout<<"Minimum Value: "<<getMinimum()<<endl;
    cout<<"Maximum Value: "<<getMaximum()<<endl;
    cout<<"Average Value: "<<fixed<<setprecision(2)<<getAverage()<<endl;
    // print grade distribution chart
    outputBarChart();
}

