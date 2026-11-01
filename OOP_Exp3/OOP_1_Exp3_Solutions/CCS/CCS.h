#ifndef CCS_H
#define CCS_H

#include <string>

using namespace std;

class CCS
{
public:
	///
	CCS(double,double,double,double,double,double,int);
	///
	void setCoordinates(void);
	///
	void setCs1_item1(double);
	///
	void setCs1_item2(double);
	///
	void setCs1_item3(double);
	///
	void setCs2_item1(double);
	///
	void setCs2_item2(double);
	///
	void setCs2_item3(double);
	///
	void setChoice(int);
	///
	double getCs1_item1(void);
	///
	double getCs1_item2(void);
	///
	double getCs1_item3(void);
	///
	double getCs2_item1(void);
	///
	double getCs2_item2(void);
	///
	double getCs2_item3(void);
	///
	int getChoice(void);
	///
	void printMenu(void);
	///
	void printCoordinates(void);
	
	
private:
	
	///
	double cs1_item1;
	///
	double cs1_item2;
	///
	double cs1_item3;
	///
	double cs2_item1;
	///
	double cs2_item2;
	///
	double cs2_item3;
	/// 
	int choice;
	///
	string conversionType;
	
	///
	void carToSph(void);
	///
	void carToCyl(void);
	///
	void sphToCar(void);
	///
	void cylToCar(void);
	
	///
	double getRadianFromDegree(double);
	///
	double getDegreeFromRadian(double);
	/// 
	string getConversionType(void);
	
};

#endif
