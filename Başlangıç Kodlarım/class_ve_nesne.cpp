#include <iostream>

using namespace std;

class Araba{
	
	public:
	
	string marka;
	int model;
	string rengi;
	
	// arabaýn fonksiyonu yani eylemine METHOD deniyor
	void gazla(){
		cout<<"Gaza basildi."<<endl;
		
	}
	void dur(){
		cout<<"Arac durduruldu"<<endl;
		
	}
	
};

	
int main(){
	
	Araba nesne1;
	Araba nesne2;
	Araba nesne3;			//bu bir nesne
	
	// class bir tane ama nesne istediðimiz kadar.
	
	nesne1.marka = "toyota";
	nesne1.model = 1999;
	nesne1.rengi = "kirmizi";
	
	cout<<nesne1.marka<<endl;
	cout<<nesne1.model<<endl;
	cout<<nesne1.rengi<<endl;
	
	nesne1.gazla();
	nesne1.dur();
	
	
	
	
	return 0;
}
