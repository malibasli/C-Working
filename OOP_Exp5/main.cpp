#include <iostream>
#include "GradeBook.h" 
using namespace std;

int main()
{
    const int array[GradeBook::students] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    GradeBook gradebook1("GradeBook1", array);
    gradebook1.displayMessage();
    gradebook1.processGrades();
	         
    return 0;
}
