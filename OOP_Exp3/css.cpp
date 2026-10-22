
#include "ccs.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

CCS::CSS(double i1,double i2, double i3, double i4, double i5, double i6, int x){
	
	setCs1_item1(i1);
	setCs1_item2(i2);
	setCs1_item3(i3);
	setCs2_item1(i4);
	setCs2_item2(i5);
	setCs2_item3(i6);
	setChoice(x);
	conversionType = "";
	
}

void CCS::setCs1_item1(double a){
	cs1_item1 = a;
}
void CCS::setCs1_item2(double a){
	cs1_item2 = a;
}
void CCS::setCs1_item3(double a){
	cs1_item3 = a;
}
void CCS::setCs2_item1(double a){
	cs2_item1 = a;
}
void CCS::setCs2_item2(double a){
	cs2_item2 = a;
}
void CCS::setCs2_item3(double a){
	cs2_item3 = a;
}
void CCS::setChoice(int a){
	choice = a;
}

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
