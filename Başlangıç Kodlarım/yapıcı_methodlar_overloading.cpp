#include <iostream>

using namespace std;

class kisi{
	public:		
	string ad;
	string soyad;
	int yas;
	
	// 1. NOT (Varsayilan Kurucu): Herhangi bir parametre gonderilmeden 'kisi nes0;' 
	// seklinde nesne uretildiginde devreye giren otomatik baslangic metodudur.
	kisi(){
		cout<<"yapici method calisti."<<endl;
	}
	
	// 2. NOT (Fonksiyon Asiri Yukleme - Overloading): Ayni isimde birden fazla 
	// kurucu tanimlanmistir. 'kisi nes2("mehmet");' yazildiginda derleyici 
	// tek arguman alan bu metodu dinamik olarak sececek kadar akillidir.
	kisi ( string a){
		ad = a;
		cout<<"tek parametreli yapici method calisti."<<endl;
	}
	
	// 3. NOT (Parametreli Kurucu): 'kisi nes1("ahmet","su",22);' seklinde nesne 
	// uretildigi anda tum degiskenlerin (ad, soyad, yas) ilk deger atamalarini 
	// tek seferde gerceklestirir ve cop verileri (garbage data) onler.
	kisi ( string a, string s, int y){
		
		ad = a;
		soyad = s;
		yas = y;
		cout<<"çok parametreli yapici method calisti."<<endl;
	}
	
	void yazdir(){
		cout<<"ad: "<<ad<<endl;
		cout<<"soyad: "<<soyad<<endl;
		cout<<"yas: "<<yas<<endl;	
	}	
	
};

	
int main(){
	
	kisi nes0;
	nes0.yazdir();
	
	kisi nes2("mehmet");
	nes2.yazdir();
	
	kisi nes1("ahmet","su",22);
	nes1.yazdir();
	
	return 0;
}
