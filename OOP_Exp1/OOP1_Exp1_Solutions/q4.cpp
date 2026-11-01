/*******************************************************************
Filename = q4
Author = Kaya Turgut
Date = 3.10.2020
Description = Fourth question related to find maximum one of three integers
*******************************************************************/

//includes input/output header to use "cin/cout" funtion
#include<iostream>

//To omit std:: notation for cout/cin/endl
using namespace std;

/*function main begins program execution
  each program must include main function*/
int main(void)
{
	//Define a,b and c variables as int
	int a,b,c;
	
	cout<<"Enter a values:"; //Print the explanation for user
	cin>>a; //Prompt the a values
		
	cout<<"Enter b values:"; //Print the explanation for user
	cin>>b; //Prompt the b values
		
	cout<<"Enter c values:"; //Print the explanation for user
	cin>>c; //Prompt the c values

	//implement the condition statement to find the maximum value
	if (a>=b && a>=c) //if the a is greater than b and c, then it is the maximum.
		cout<<"The maximum of among "<<a<<","<<b<<","<<c<<" is the value "<<a<<endl;
	else if (b>=a && b>=c) //if the b is greater than a and c, then it is the maximum.
		cout<<"The maximum of among "<<a<<","<<b<<","<<c<<" is the value "<<b<<endl;
	else // if the a and b is not maximum, the c is the maximum
		cout<<"The maximum of among "<<a<<","<<b<<","<<c<<" is the value "<<c<<endl;
		
	
	//indcates successful termination
	return 0;
}
