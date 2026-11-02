#include <iostream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name)
{
    setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
    if (name.length() <= 30) 
        courseName = name; 
    else {
        courseName = name.substr(0, 30); 
        cout << "Name \"" << name << "\" exceeds maximum length (30).\n"
             << "Limiting courseName to first 30 characters.\n" << endl;
    }
}

string GradeBook::getCourseName()
{
    return courseName; 
}

void GradeBook::displayMessage()
{
    cout << "Welcome to the Grade Book for " << getCourseName() << "!" << endl;
}

void GradeBook::determineClassAverage(int numberOfStudent){
	
	int sum=0;
	int grade;
	

	for(int i=1;i<=numberOfStudent;i++){
		cout<<i<<". student grade: "<<endl;
		cin>>grade;
		sum = grade + sum;
	}
	
	double average = (double)sum/numberOfStudent;
	
	cout<<"Grades Average is : "<<average<<endl;	
}

void GradeBook::determineClassAverage(){
	
	int grade=0;
	int sum=0;
	int count=0;
	double average=0;
	
	while(1){
		cout<<"Enter Grade: ";
		cin>>grade;
		if(0<=grade && grade<=100){
			count++;
			sum = sum + grade;
		}else{
			break;
		}
	}	
	if(count != 0){average = (double)sum/count;}
	
	cout<<"Grades Average is : "<<average<<endl;
}

void GradeBook::inputGrades(){	
	string grade;
	
	cout<<"Enter Grade 'E' to exit."<<endl;	
	while(1){
			cout<<"Enter Letter Grades (please A,B,C,D,F): ";
			cin>>grade;
			if(grade == "A"){
				a++;
			}else if(grade == "B"){
				b++;
			}else if(grade == "C"){
				c++;
			}else if(grade == "D"){
				d++;
			}else if(grade == "F"){
				f++;
			}else if(grade == "E"){
				break;
			}else{
				cout<<"This letter grade is not valid."<<endl;
			}						
	}	
}

void GradeBook::displayGradeReport(){
	cout<<"A: "<<a<<endl
		<<"B: "<<b<<endl
		<<"C: "<<c<<endl
		<<"D: "<<d<<endl
		<<"F: "<<f<<endl;		
}
