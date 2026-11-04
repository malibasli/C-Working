
#include <iostream>	
#include <cmath>
#include "Triangle.h"
using namespace std;

/// Default Constructor
Triangle::Triangle(string n, const Line &x, const Line &y, const Line &z)
			:name(n),
		 	 a(x),
		 	 b(y),
		 	 c(z)
{
	cout << "\n\nTriangle object constructor for " << name << endl;
}

/// Output properties of the rectangle
void Triangle::outputProperties(void)
{
	calculateAngles();
	calculateArea();
	calculatePerimeter();
	determineTypeAngles();
	determineTypeEdges();
}

/// Utility function: Calculate angles of the triangle
void Triangle::calculateAngles(void)
{
	double magA=a.getMagnitude();
	double magB=b.getMagnitude();
	double magC=c.getMagnitude();
	
	angleA=acos((pow(magB,2)+pow(magC,2)-pow(magA,2))/(2*magB*magC))*180/M_PI;
	angleB=acos((pow(magA,2)+pow(magC,2)-pow(magB,2))/(2*magA*magC))*180/M_PI;
	angleC=acos((pow(magA,2)+pow(magB,2)-pow(magC,2))/(2*magA*magB))*180/M_PI;
	
	cout << "Angle A = " << angleA << endl;
	cout << "Angle B = " << angleB << endl;
	cout << "Angle C = " << angleC << endl;
}

/// Utility function: Calculate area of the triangle
void Triangle::calculateArea(void)
{
	double temp=0.5*(a.getMagnitude()*b.getMagnitude())*sin(angleC*M_PI/180);
	cout << "The area of the triangle is " << temp << endl;
}

/// Utility function: Calculate perimeter of the triangle
void Triangle::calculatePerimeter(void)
{
	int temp=a.getMagnitude()+b.getMagnitude()+c.getMagnitude();
	cout << "The perimeter of the triangle is " << temp << endl;
}

/// Utility function: Determine type of the triangle in terms of angles	
void Triangle::determineTypeAngles(void)
{
	if (angleA==90 || angleB==90 || angleC==90)
		cout << "The triangle is a right triangle " << endl;
	else if (angleA>90 || angleB>90 || angleC>90)
		cout << "The triangle is an obtuse triangle " << endl;
	else 
		cout << "The triangle is a acute triangle " << endl;
}	

/// Utility function: Determine type of the triangle in terms of edges
void Triangle::determineTypeEdges(void)
{
	double magA=a.getMagnitude();
	double magB=b.getMagnitude();
	double magC=c.getMagnitude();
	
	if (magA==magB && magB==magC)
		cout << "The triangle is a equilateral triangle " << endl;
	else if (magA==magB || magA==magC || magB==magC)
		cout << "The triangle is a isosceles triangle " << endl;
	else 
		cout << "The triangle is a scalene triangle " << endl;
}

/// Destructor
Triangle::~Triangle()
{
	//cout << "Triangle object destructor for " << name << endl;
}
