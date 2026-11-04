/* ******************************************************* 
 * Filename		:	Point.cpp
 * Author		:	Burak Kaleci		
 * Date			:	29.10.2018
 * Description	:	Point Class Implementation
 * ******************************************************/

#include <iostream>	
#include "Point.h"	// include definition of class Point
using namespace std;

/// Default Constructor	
Point::Point(string n, double X, double Y)
{
	setX(X);
	setY(Y);
	setName(n);
	
	cout << "\nPoint object constructor for " << name << endl;	
}

/// Set name of the point
void Point::setName(string n)
{
	name=n;
}

/// Set x coordinate of the point
void Point::setX(double X)
{
	x=X;
}
	
/// Set y coordinate of the point
void Point::setY(double Y)
{
	y=Y;	
}
	
/// Return x coordinate of the point
double Point::getX(void) const
{
	return x;
}
	
/// Return y coordinate of the point
double Point::getY(void) const
{
	return y;
}

/// Return name of the point
string Point::getName(void) const
{
	return name;
}

/// Print point in name( x,y ) format
/*Point::print(void) const
{
	cout << name << "( " << x << "," << y << " )";
}*/

/// Destructor
Point::~Point()
{
	//cout << "Point object destructor for " << name << endl;
}

ostream & operator<<(ostream &output, const Point &p)
{
	output << p.getName() << "( " << p.getX() << "," << p.getY() << " )";
	return output;
}



