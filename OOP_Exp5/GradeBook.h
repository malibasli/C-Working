#include <string>
using namespace std;

class GradeBook
{
public:
    GradeBook(string, const int[]);
    void setCourseName(string);
    string getCourseName();
    void displayMessage();
    void processGrades();
    
    static const int students=10;

private:
    string courseName;
    int grades[students];
    
    int getMinimum();
    int getMaximum();
    double getAverage();
    void outputBarChart();
    void outputGrades();
};
