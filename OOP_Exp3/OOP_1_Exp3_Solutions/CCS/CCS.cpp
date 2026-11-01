#include <iostream>
#include <cmath>
#include "CCS.h"

using namespace std;

CCS::CCS(double cs1_1,double cs1_2,double cs1_3,double cs2_1,double cs2_2,double cs2_3,int s)
{
	setCs1_item1(cs1_1);
	setCs1_item2(cs1_2);
	setCs1_item3(cs1_3);
	setCs2_item1(cs2_1);
	setCs2_item2(cs2_2);
	setCs2_item3(cs2_3);
	setChoice(s);
}

void CCS::printMenu(void)
{
	do {
		cout << "*******************************************************" << endl;
		cout << "1. Cartesian to Spherical" << endl;
		cout << "2. Cartesian to Cylindrical" << endl;
		cout << "3. Spherical to Cartesian" << endl;
		cout << "4. Cylindrical to Cartesian" << endl;
		cout << "5. Exit"<< endl;
		cout << "*******************************************************" << endl;
		
		cout << "Enter your choice " << endl;
		cin >> choice; 
		
		if (choice>5 || choice<0)
			cout << "Wrong Choice! Try Again" << endl;
		
	}while(choice>5 || choice<0);
		
}

void CCS::setCoordinates(void)
{
	double a,b,c;
	switch(choice){
		
		case 1:
		case 2:	
			cout << "Enter x, y, and z coordinates " << endl;
			cin>> a >> b >> c;
			break;
		case 3:
			cout << "Enter r, theta, and phi coordinates " << endl;
			cin>> a >> b >> c;
			break;
		case 4:
			cout << "Enter rho, phi, and z coordinates " << endl;
			cin>> a >> b >> c;
			break;
		case 5:
			cout << "Thank you..." << endl;		
	}
	setCs1_item1(a);
	setCs1_item2(b);
	setCs1_item3(c);
}

void CCS::printCoordinates(void)
{
	
	switch(choice){
		
		case 1:
			carToSph();
			conversionType="Cartesian to Spherical";
			cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")" 
				<< "=====" << getConversionType() << "========>" 
				<< " PCON(" << getCs2_item1() << "," << getDegreeFromRadian(getCs2_item2()) << "," 
				<< getDegreeFromRadian(getCs2_item3()) << ")" << endl;
			break;
		case 2:	
			carToCyl();
			conversionType="Cartesian to Cylindrical";
			cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")" 
				<< "=====" << getConversionType() << "========>" 
				<< " PCON(" << getCs2_item1() << "," << getDegreeFromRadian(getCs2_item2()) << "," 
				<< getCs2_item3() << ")" << endl;
			break;
		case 3:
			sphToCar();
			conversionType="Spherical to Cartesian";
			cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")" 
				<< "=====" << getConversionType() << "========>" 
				<< " PCON(" << getCs2_item1() << "," << getCs2_item2()<< "," << getCs2_item3() << ")"
				 << endl;
			break;
		case 4:
			cylToCar();
			conversionType="Cylindrical to Cartesian";
			cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")" 
				<< "=====" << getConversionType() << "========>" 
				<< " PCON(" << getCs2_item1() << "," << getCs2_item2()<< "," << getCs2_item3() << ")"
				 << endl;
			break;	
	}
}


void CCS::setCs1_item1(double a)
{
	cs1_item1=a;
}


void CCS::setCs1_item2(double a)
{
	cs1_item2=a;
}


void CCS::setCs1_item3(double a)
{
	cs1_item3=a;
}


void CCS::setCs2_item1(double a)
{
	cs2_item1=a;
}

void CCS::setCs2_item2(double a)
{
	cs2_item2=a;
}

void CCS::setCs2_item3(double a)
{
	cs2_item3=a;
}

void CCS::setChoice(int a)
{
	choice=a;
}

///
double CCS::getCs1_item1(void)
{
	return cs1_item1;
}	
	
///
double CCS::getCs1_item2(void)
{
	return cs1_item2;
}
	
	
///
double CCS::getCs1_item3(void)
{
	return cs1_item3;
}
	
	
///
double CCS::getCs2_item1(void)
{
	return cs2_item1;
}
	
	
///
double CCS::getCs2_item2(void)
{
	return cs2_item2;
}
	
	
///
double CCS::getCs2_item3(void)
{
	return cs2_item3;
}
	
	
///
int CCS::getChoice(void)
{
	return choice;
}


///
void CCS::carToSph(void)
{
	cs2_item1=sqrt((pow(cs1_item1,2)+pow(cs1_item2,2)+pow(cs1_item3,2)));
	cs2_item2=atan2(sqrt(pow(cs1_item1,2)+pow(cs1_item2,2)),cs1_item3);
	cs2_item3=atan2(cs1_item2,cs1_item1);
}


///
void CCS::carToCyl(void)
{
	cs2_item1=sqrt(pow(cs1_item1,2)+pow(cs1_item2,2));
	cs2_item2=atan2(cs1_item2,cs1_item1);
	cs2_item3=cs1_item3;
}
	

///
void CCS::sphToCar(void)
{
	cs2_item1=cs1_item1*sin(getRadianFromDegree(cs1_item3))*cos(getRadianFromDegree(cs1_item2));
	cs2_item2=cs1_item1*sin(getRadianFromDegree(cs1_item2))*sin(getRadianFromDegree(cs1_item3));
	cs2_item3=cs1_item1*cos(getRadianFromDegree(cs1_item3));
}
	

///
void CCS::cylToCar(void)
{
	cs2_item1=cs1_item1*cos(getRadianFromDegree(cs1_item2));
	cs2_item2=cs1_item1*sin(getRadianFromDegree(cs1_item2));
	cs2_item3=cs1_item3;
}
		
///
double CCS::getRadianFromDegree(double value)
{
	return value*M_PI/180;
}

///
double CCS::getDegreeFromRadian(double value)
{
	return value*180/M_PI;
}

/// 
string CCS::getConversionType(void)
{
	return conversionType;
}

