#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include<string>
using namespace std;


class GradeBook
{
    public:
    	// constant number of students who took the test
    	static const int students = 10;
    	
    	// constructor initializes course name and array of grades
        GradeBook(string, const int []);       
		// function to set the course name 
        void setCourseName(string);
        // function to retrieve the course name
        string getCourseName(void);
        // display a welcome message
        void displayMessage(void);
        // perform various operations on the grade data
        void processGrades(void);    

                    
    private:
    	// course name for this grade book
        string courseName;
        // array of student grades
        int grades[students];
        
        // find the minimum grade for the test
        int getMinimum(void);
        // find the maximum grade for the test
        int getMaximum(void);
        // determine the average grade for the test
        double getAverage(void);
        // output bar chart of grade distribution
        void outputBarChart(void);
        // output the contents of the grades array
        void outputGrades(void); 
						
};

#endif

