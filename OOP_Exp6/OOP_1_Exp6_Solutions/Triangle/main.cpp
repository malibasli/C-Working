#include <iostream>
#include <cmath>

#include "Triangle.h"
using namespace std;


main() 
{
	const Point A("A",-2,3);
	//A.print();
	cout << A << endl;
	const Point B("B",-5,-4);
	cout << B << endl;
	//B.print();
	const Point C("C",2,-1);
	//C.print();
	cout << C << endl;
	
	//cout << A << B << C;
	
	const Line a("a", B,C);
	cout << a << endl;
	//a.print();
	const Line b("b", A,C);
	//b.print();
	cout << b << endl;
	const Line c("c", A,B);
	//c.print();
	cout << c << endl;
	
	Triangle t("t",a,b,c);
	t.outputProperties();
}
