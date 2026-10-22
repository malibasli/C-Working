#ifndef
#define CCS_H

#include <iostream>
#include <string>

using namespace std;

class CCS {
	private:
		double cs1_item1;
		double cs1_item2; 
		double cs1_item3; 
		double cs2_item1; 
		double cs2_item2; 
		double cs2_item3; 
		
		int choice;
		string conversionType;
	
	public:
		CSS(double i1,double i2, double i3, double i4, double i5, double i6, int x);
		void setCoordinates();
		void setCs1_item1(double a);
		void setCs1_item2(double a);
		void setCs1_item3(double a);
		void setCs2_item1(double a);
		void setCs2_item2(double a);
		void setCs2_item3(double a);
		void setChoice(int a);
		double getCs1_item2();	
		double getCs1_item1();
		double getCs2_item1();
		double getCs1_item3();
		double getCs2_item2();
		double getCs2_item3();
		int getChoice();
		void printMenu();
		void printCoordinates();
	
	private:
		void carToSph();
		void carToCyl();
		void sphToCar()
		void cylToCar();
		double getRadianFromDegree(double a);
		double getDegreeFromRadian(double a);
		string getConversionType();
		
};

#endif
