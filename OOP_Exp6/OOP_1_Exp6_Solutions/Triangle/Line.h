/* ******************************************************* 
 * Filename		:	Line.h
 * Author		:	Burak Kaleci		
 * Date			:	30.10.2018
 * Description	:	Line Class Interface
 * ******************************************************/
 
// prevent multiple inclusions of header
#ifndef LINE_H
#define LINE_H

#include "Point.h"	// include definition of class Point

// Line class definition
class Line
{

	friend ostream & operator<<(ostream &, const Line &);
public:
	
	/// Default Constructor		
	Line(string n, const Point &pS, const Point &pE);
	/// Set functions
	/// Set name of the line
	void setName(string);
	/// Set magnitude of the line
	void setMagnitude(double);
	/// Get functions should be const
	/// Return start point of the line
	Point getStartPoint() const;
	/// Return end point of the line
	Point getEndPoint() const;
	/// Return name of the line
	string getName() const;
	/// Return magnitude of the line
	double getMagnitude() const;	
	/// Print Line in SP( x,y ) ----------- EP( x,y) format
	//void print(void) const;
	/// Destructor
	~Line();

private:
	
	/// Store start point of the line
	const Point start;
	/// Store end point of the line
	const Point end;
	/// Store name of the line
	string name; 
	/// Store magnitude of the line
	double magnitude;
	
	/// Calculate and print magnitude of the line segment
   	void calculateMagnitude(void);
};

#endif
