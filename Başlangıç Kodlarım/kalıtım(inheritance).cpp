#include <iostream>

using namespace std;

class kisi{
	public:		
	string ad;
	string soyad;
	int yas;	
};

class ogrenci : public kisi { // öðreci classý kiþi clas
	public:
	string bolum;
	
};
class egitmen : public kisi {
	public:
	int maas;
	
};

	 
int main(){
	
	ogrenci o1;
	o1.ad  = "ahmet";
	o1.soyad = "su";
	o1.yas = 22;
	o1.bolum = "bilgisayar";
	
	egitmen e1;
	e1.ad = "mustafa";
	e1.soyad = "yilmaz";
	e1.yas = 31;
	e1.maas = 5000;
	
	cout <<o1.ad<<endl;
	cout <<o1.soyad<<endl;
	cout <<o1.yas<<endl;
	cout <<o1.bolum<<endl<<endl;
	
	cout <<e1.ad<<endl;
	cout <<e1.soyad<<endl;
	cout <<e1.yas<<endl;
	cout <<e1.maas<<endl;

		
	return 0;
}
