/* ******************************************************* 
 * Filename		:	Point.h
 * Author		:	Burak Kaleci		
 * Date			:	29.10.2018
 * Description	:	Point Class Interface
 * ******************************************************/
 
// prevent multiple inclusions of header
#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
using namespace std;

// Point class definition
class Point
{

	friend ostream & operator<<(ostream &, const Point &);
public:
	
	/// Default Constructor	
	Point(string n,double X=0, double Y=0);
	/// Set functions
	/// Set x coordinate of the point
	void setX(double);
	/// Set y coordinate of the point
	void setY(double);
	/// Set name of the point
	void setName(string);
	/// Get functions should be const
	/// Return x coordinate of the point
	double getX(void) const;
	/// Return y coordinate of the point
	double getY(void) const;
	/// Return name of the point
	string getName(void) const;
	/// Print point in id( x,y ) format
	//print(void) const;
	/// Destructor
	~Point(void);
	
private:
	
	/// Store x coordinate of the point
	double x;
	/// Store y coordinate of the point
	double y;
	/// Store name of the point
	string name;

};

#endif
