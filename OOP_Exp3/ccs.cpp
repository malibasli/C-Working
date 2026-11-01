#include "ccs.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

const double PI = 3.141592653589793;
using namespace std;

CCS::CCS(double i1,double i2, double i3, double i4, double i5, double i6, int x){
	
	setCs1_item1(i1);
	setCs1_item2(i2);
	setCs1_item3(i3);
	setCs2_item1(i4);
	setCs2_item2(i5);
	setCs2_item3(i6);
	setChoice(x);
	conversionType = "";
	
}

void CCS::setCs1_item1(double a){cs1_item1 = a;}
void CCS::setCs1_item2(double a){cs1_item2 = a;}
void CCS::setCs1_item3(double a){cs1_item3 = a;}
void CCS::setCs2_item1(double a){cs2_item1 = a;}
void CCS::setCs2_item2(double a){cs2_item2 = a;}
void CCS::setCs2_item3(double a){cs2_item3 = a;}
void CCS::setChoice(int a){choice = a;}

double CCS::getCs1_item1() { return cs1_item1; }
double CCS::getCs1_item2() { return cs1_item2; }
double CCS::getCs1_item3() { return cs1_item3; }
double CCS::getCs2_item1() { return cs2_item1; }
double CCS::getCs2_item2() { return cs2_item2; }
double CCS::getCs2_item3() { return cs2_item3; }
int CCS::getChoice() { return choice; }

void CCS::printMenu(){
	
	int tempChoice = 0;
			
	while(1){
		
		cout<<"********************************************************"<<endl;
		cout<<"1. Cartesian to Spherical"<<endl;
		cout<<"2. Cartesian to Cylindrical"<<endl;
		cout<<"3. Spherical to Cartesian"<<endl;
		cout<<"4. Cylindrical to Cartesian"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>tempChoice;
		if(0<tempChoice && tempChoice<6){
			setChoice(tempChoice);
			break;
		}
		else{
			cout<<"Please a valid selection"<<endl<<endl;
		}
	
	}
}

///////////////////////////////////////////////////////////////////

void CCS::setCoordinates(){
	
	double q=0.0,w=0.0,e=0.0;
	
	if (getChoice()==1 || getChoice()==2){
		cout<<"Enter x, y, z coordinates: "<<endl;
		cin>>q>>w>>e;
	}
	else if(getChoice()==4){
		cout<<"Enter rho, phi, z coordinates: "<<endl;
		cin>>q>>w>>e;
	}
	else if(getChoice()==3){
		cout<<"Enter r, theta, phi coordinates: "<<endl;
		cin>>q>>w>>e;
	}
	else{
		cout<<"Exit......"<<endl;
	}
	
	setCs1_item1(q);
	setCs1_item2(w);
	setCs1_item3(e);				
}
///////////////////////////////////////////////////////////////////

void CCS::printCoordinates(){
	
	if(getChoice() == 1){
		carToSph();
		
		cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")";
    	cout << "====="<< getConversionType() <<" ========> ";
    	cout << "PCON(" << getCs2_item1() << "," << getCs2_item2() << "," << getCs2_item3() << ")" << endl;
		
	}else if(getChoice() == 2) {
    	carToCyl(); 
    
   
    	cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")";
    	cout << "====="<< getConversionType() <<" ========> ";
    	cout << "PCON(" << getCs2_item1() << "," << getCs2_item2() << "," << getCs2_item3() << ")" << endl;
	}else if(getChoice() == 3) {
    	sphToCar();
    
   
    	cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")";
    	cout << "====="<< getConversionType() <<" ========> ";
    	cout << "PCON(" << getCs2_item1() << "," << getCs2_item2() << "," << getCs2_item3() << ")" << endl;
	}else if(getChoice() == 4) {
    	cylToCar();
    
   
    	cout << "P(" << getCs1_item1() << "," << getCs1_item2() << "," << getCs1_item3() << ")";
    	cout << "====="<< getConversionType() <<" ========> ";
    	cout << "PCON(" << getCs2_item1() << "," << getCs2_item2() << "," << getCs2_item3() << ")" << endl;
	}else{
		cout<<"Exit..."<<endl;
	}	
}

///////////////////////////////////////////////////////////////////

void CCS::carToSph(){
	double a,b,c;
	
	a = sqrt(pow(cs1_item1, 2) + pow(cs1_item2, 2) + pow(cs1_item3, 2));
	b = atan2(cs1_item2,cs1_item1);
	b = getDegreeFromRadian(b);
	c = atan2(sqrt(pow(cs1_item1,2) + pow(cs1_item2,2)), cs1_item3);
	c = getDegreeFromRadian(c);
	setCs2_item1(a);
	setCs2_item2(b);
	setCs2_item3(c);
	
	conversionType = "Cartesian to Spherical";
}

///////////////////////////////////////////////////////////////////

void CCS::carToCyl(){
	double a,b,c;
	
	a = sqrt(pow(cs1_item1, 2) + pow(cs1_item2, 2));
	b = atan2(cs1_item2,cs1_item1);
	b = getDegreeFromRadian(b);
	c=cs1_item3;
	
	setCs2_item1(a);
	setCs2_item2(b);
	setCs2_item3(c);
	
	conversionType = "Cartesian to Cylindrical";
}

///////////////////////////////////////////////////////////////////

void CCS::sphToCar(){
	double a,b,c,d,e;
	
	a = getRadianFromDegree(cs1_item2);
	b = getRadianFromDegree(cs1_item3);
	
	c = cs1_item1*sin(b)*cos(a);
	d = cs1_item1*sin(b)*sin(a);
	e = cs1_item1*cos(b);
	
	setCs2_item1(c);
	setCs2_item2(d);
	setCs2_item3(e);
	
	conversionType = "Spherical to Cartesian";
}

///////////////////////////////////////////////////////////////////

void CCS::cylToCar(){
	double a,b,c,d;
	
	a = getRadianFromDegree(cs1_item2);
	b = cs1_item1*cos(a);
	c = cs1_item1*sin(a);
	d = cs1_item3;
	
	setCs2_item1(b);
	setCs2_item2(c);
	setCs2_item3(d);
	
	conversionType = "Cylindrical to Cartesian";
}

///////////////////////////////////////////////////////////////////

double CCS::getRadianFromDegree(double a){
	double b;
	b = (a*PI)/180;
	return b;	
}

///////////////////////////////////////////////////////////////////

double CCS::getDegreeFromRadian(double a){
	double b;
	b = (a*180)/PI;
	return b;
}

///////////////////////////////////////////////////////////////////

string CCS::getConversionType(){
	return conversionType;
}
