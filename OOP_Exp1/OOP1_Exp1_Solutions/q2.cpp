/*******************************************************************
Filename = q2
Author = Kaya Turgut
Date = 3.10.2020
Description = Second question related to calculate elapsed time (second) by 
              using given velocity(meter/second) and distance(meter)
*******************************************************************/

//includes input/output header to use "cin/cout"
#include<iostream>

//To omit std:: notation for cout/cin/endl
using namespace std;

/*function main begins program execution
  each program must include main function*/
int main(void)
{
	//initial robot position
	double init_pos = 0;
	//final robot position
	double final_pos;
	//robot velocity
	double lin_vel;
	//Travelled distance which is calculated
	double dist;
	//Elapsed time which is calculated
	double elapsed_time;
	
	cout<<"Enter the final position:"; //Print the explanation for user
	cin>>final_pos; //Prompt the final position
	cout<<"Enter the velocity:"; //Print the explanation for user
	cin>>lin_vel; //Prompt the linear velocity
	
	dist = final_pos - init_pos; // Calculate the travelled distance
	elapsed_time = dist/lin_vel; // Calculate the elapsed time
	

	cout<<"Travelled distance:"<<dist<<" meter"<<endl; //Print travelled distance 
	cout<<"Elapsed time:"<<elapsed_time<<" second"<<endl; //Print the elapsed time
	
	
	//indcates successful termination
	return 0;
}
