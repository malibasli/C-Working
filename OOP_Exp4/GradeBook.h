#include <string>
using namespace std;

class GradeBook
{
public:
    GradeBook(string);
    void setCourseName(string);
    string getCourseName();
    void displayMessage();
    void determineClassAverage(int);
    void determineClassAverage();
    void inputGrades();
    void displayGradeReport();

private:
    string courseName;
    int a=0,b=0,c=0,d=0,f=0;
};
