#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double a,b,c;
	
	cout	<<"Enter three numbers: ";
	cin		>>a;
	cin		>>b;
	cin		>>c;
	
	if(a>b && a>c){
		cout<<"Max of three number is :"<<a<<endl;
	}
	else if(b>a && b>c){
		cout<<"Max of three number is :"<<b<<endl;
	}
	else{
		cout<<"Max of three number is :"<<c<<endl;
	}

	return 0;
}
