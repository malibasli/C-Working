#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	//PART 1
	 
	//cout<<"Object Oriented Programming course will be funny."<<endl;
	//cout<<"Object Oriented Programming course will be funny."<<endl;
	//cout<<"will be funny."<<endl;
	
	
	
	//PART 2
	
	//double time = 0;  // hesaplanacak olan
	//double velocity = 0;
	//double initial_position = 0;  // 
	//double final_position = 0;
	//double distance = 0;
	
	// KULLANICIDAN FINAL POSITION VE VELOCÝTY ALINACAK.
	
	
	//cout	<<"Final position: ";
	//cin 	>>final_position;
	//cout	<<"Velocity: ";
	//cin 	>>velocity;
	
	//distance = final_position-initial_position;
	//time = (distance)/velocity;
	
	//cout <<"Distance : "<<distance<<endl;
	//cout <<"Time : "<<time<<endl;
	
	
	//PART 3
	
	double x;
	double result;
	
	cout	<<"Enter a value for x: ";
	cin 	>>x;
	
	if(x<-3){
		result=(pow(x,3)+4)/pow(x,2);
		cout<<"X is first interval."<<endl;
		cout<<"Result: "<<result<<endl;
	}
	else if(-2 <= x && x < 0){
		result=abs(pow(x,2) + 3*x - 10);
		cout<<"X is second interval."<<endl;
		cout<<"Result: "<<result<<endl;
	}
	else if(0 <= x && x < 4){
		result=pow(x,2)-(x*4);
		cout<<"X is third interval."<<endl;
		cout<<"Result: "<<result<<endl;
	}
	else{
		cout<<"Verilen x degeri aralikta tanimli degil."<<endl;
	}
	
	
	
		
	return 0;
}
