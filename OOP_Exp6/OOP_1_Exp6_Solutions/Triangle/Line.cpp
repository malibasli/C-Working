/* ******************************************************* 
 * Filename		:	Line.cpp
 * Author		:	Burak Kaleci		
 * Date			:	30.10.2018
 * Description	:	Line Class Implementation
 * ******************************************************/

#include <iostream>	
#include <cmath>
#include "Line.h"	// include definition of class Line
using namespace std;

/// Default Constructor
Line::Line(string n, const Point &pS, const Point &pE)
		:name(n),
		 start(pS),
		 end(pE)
{
	cout << "\n\nLine object constructor for line " << name << endl;
	calculateMagnitude();
}
	
/// Set name of the line
void Line::setName(string n)
{
	name=n;
}
	
/// Set magnitude of the line
void Line::setMagnitude(double m)
{
	magnitude=m;
}

/// Return start point of the line
Point Line::getStartPoint() const
{
	return start;
}
/// Return end point of the line
Point Line::getEndPoint() const
{
	return end;
}
	
/// Return name of the line
string Line::getName() const
{
	return name;
}

/// Return magnitude of the line
double Line::getMagnitude() const
{
	return magnitude;
}

/// Print Line in SP( x,y ) ----------- EP( x,y) format
/*void Line::print(void) const
{
	start.print();
	cout << "--------------";
	end.print();
}*/

/// Calculate and print magnitude of the line segment
void Line::calculateMagnitude(void)
{
	magnitude=sqrt(pow((start.getX()-end.getX()),2)+ pow((start.getY()-end.getY()),2));
	cout << "Magnitude of the line " << name << " " << magnitude << endl;
}

Line::~Line()
{
	//cout << "Point object destructor for line " << name << endl;
}

ostream & operator<<(ostream &output, const Line &l)
{
	output << l.getStartPoint();
	cout << "--------------";
	output << l.getEndPoint();
	return output;
}
