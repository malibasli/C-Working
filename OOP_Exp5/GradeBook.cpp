#include <iostream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name, const int gradesArray[])
{
    setCourseName(name);
    for(int i=0;i<students;i++){
    	grades[i] = gradesArray[i]; // nesne ooluþturuken gönderilen notlarý data member grades e kaydettik.
	}
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

int GradeBook::getMinimum(){
	
	int min=grades[0]; // ilk elemaný min kabul ettik.
	
	for (int i = 0; i < students; i++) {
        if (grades[i] < min) { // Eðer o anki not, bizim min deðerimizden daha küçükse
            min = grades[i];   // Yeni en küçük notumuz bu olsun
        }
    }
	return min;
}

int GradeBook::getMaximum(){
	
	int max=grades[0]; 
	
	for (int i = 0; i < students; i++) {
        if (grades[i] > max) { 
            max = grades[i];   
        }
    }
	return max;	
}

double GradeBook::getAverage() {
    int sum = 0;
    
    for (int i = 0; i < students; i++) {
        sum = sum + grades[i];
    }
    return (double)sum / students; 
}


void GradeBook::outputBarChart(){
	
	cout << "Grade distribution:" << endl;
	
	int frequency[11] = {0};
	
	for (int i = 0; i < students; i++) {
        frequency[grades[i]/10]++;
    }
    
    for (int count = 0; count < 11; count++) {
        // Önce kategorinin etiketini (0-9, 10-19, ..., 100) hizalý bir þekilde basýyoruz
        if (count == 0) {
            cout << "  0-9: ";
        } else if (count == 10) {
            cout << "  100: ";
        } else {
            cout << count * 10 << "-" << (count * 10) + 9 << ": ";
        }

        // O kategorinin frekansý (kiþi sayýsý) kadar yan yana yýldýz basýyoruz
        for (int stars = 0; stars < frequency[count]; stars++) {
            cout << "*";
        }

        cout << endl; // Yýldýzlar bitince alt satýra (sonraki kategoriye) geç
    }	
}


void GradeBook::outputGrades(){
	cout << "Grades:";
	for (int i = 0; i < students; i++) {
        cout<<grades[i]<<" ";
    }
    cout<<endl;
}

void GradeBook::processGrades(){
	outputGrades();
	cout << "\nClass average is " << getAverage() << endl;
    cout << "Lowest grade is " << getMinimum() << endl;
    cout << "Highest grade is " << getMaximum() << "\n" << endl;
	outputBarChart();
}
