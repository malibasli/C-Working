/* ******************************************************* 
 * Filename		:	Triangle.h
 * Author		:	Burak Kaleci		
 * Date			:	30.10.2018
 * Description	:	Triangle Class Interface
 * ******************************************************/
 
// prevent multiple inclusions of header
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Line.h" // include definition of class Line

// Triangle class definition
class Triangle
{

public:
	
	/// Default Constructor	
	Triangle(string n, const Line &x, const Line &y, const Line &z);
	/// Output properties of the rectangle	
	void outputProperties(void);
	/// Destructor
	~Triangle();

private:
	
	/// Store Line a from b to c
	const Line a;		
	/// Store Line b from a to c
	const Line b;		
	/// Store Line c from a to b
	const Line c;		
	/// Store name of the triangle
	string name;
	/// Store angle A
	double angleA;
	/// Store angle B
	double angleB;
	/// Store angle C
	double angleC;
	
	/// Utility function: Calculate angles of the triangle
	void calculateAngles(void);
	/// Utility function: Calculate area of the triangle
	void calculateArea(void);
	/// Utility function: Calculate perimeter of the triangle
	void calculatePerimeter(void);
	/// Utility function: Determine type of the triangle in terms of angles
	void determineTypeAngles(void);
	/// Utility function: Determine type of the triangle in terms of edges
	void determineTypeEdges(void);
	
};

#endif
