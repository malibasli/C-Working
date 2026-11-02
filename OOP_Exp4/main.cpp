#include <iostream>
#include "GradeBook.h" 
using namespace std;

int main()
{
    GradeBook gradeBook1("EEE102_ComputerProgramming_in_C");
    GradeBook gradeBook2("EEE103_AdvancedProgramming");

    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << endl;
         
   	gradeBook1.determineClassAverage(5); // A þýkký testi
	gradeBook1.determineClassAverage();  // B þýkký testi
	gradeBook1.inputGrades();            // C þýkký testi
	gradeBook1.displayGradeReport();     // D þýkký testi (senin yazdýðýn bu son kýsým)
	         
    return 0;
}
