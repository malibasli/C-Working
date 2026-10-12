#include <iostream>
#include <cmath>

using namespace std;

int f_function(int x);

int main(){
	
	int number=0;
	int copy_number=0;
	int counter=0;
	int a=0;
	int result = 0;
	
	cout<<"Sayi: ";
	cin>>number;
	copy_number = number;
	
	for(int i=0; copy_number!=0 ; i++){
		copy_number = copy_number/10;
		counter++;
	}
	
	cout<<"Basamak sayisi: "<<counter<<endl;
	
	for(int i=0; i<counter;i++){
		a = number%10;
		number = number/10;
		if(i%2==0){
			result = result + a;
		}else{
			result = result + f_function(a);
		}
	}
	
	
	cout<<"Sonuc f(d): "<<result<<endl;

	if (result%10==0){
		cout<<"Number is valid. "<<endl;
	}else{
		cout<<"Number is not valid. "<<endl;
	}
	
	return 0;
}

int f_function(int x){

	int result=0;
	
	x =x*2;

	for(int i=0; x!=0 ; i++){
		result = result + x%10;
		x = x/10;
	}
	
	return result;	
}
