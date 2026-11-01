/*******************************************************************
Filename = q3
Author = Kaya Turgut
Date = 3.10.2020
Description = Third question related to implement partial functions
*******************************************************************/

//includes input/output header to use "cin/cout" funtion
#include<iostream>
//includes cmath library to use "abs/pow" function"
#include<cmath>

//To omit std:: notation for cout/cin/endl
using namespace std;

/*function main begins program execution
  each program must include main function*/
int main(void)
{
	//function input x
	double x;
	//function output y
	double y;

	cout<<"Enter x values:"; //Print the explanation for user
	cin>>x; //Prompt the x values

	//implement partial function conditions with if...else structure
	if (x<-3)// if x is less than -3, then calculate y 
	{
		y = (pow(x,3)+4)/pow(x,2);
		cout<<"The output of the partial function "<<y<<" for the input "<<x<<"."<<endl; //Print the explanation for user
	}
	else if (x>=-2 && x<0) // if x is less than 0 and greater than -2, then calculate y 
	{
		y = abs(pow(x,2)+3*x-10);
		cout<<"The output of the partial function "<<y<<" for the input "<<x<<"."<<endl; //Print the explanation for user
	}		
	else if (x>=0 && x<4)// if x is less than 4 and greater than 0, then calculate y 
	{
		y = pow(x,2)-4*x;
		cout<<"The output of the partial function "<<y<<" for the input "<<x<<"."<<endl; //Print the explanation for user
	}		
	else //if user prompt x values does not defined on the partial function, print this warning
		cout<<"Prompt the x values between defined interval!!"<<endl; //Print the warning for users
		
	
	//indcates successful termination
	return 0;
}
