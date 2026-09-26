#include <iostream>

using namespace std;

//Nesnenin Kendisini Ýþaret Eder: Bellekte o an üzerinde iþlem yapýlan fiziksel nesnenin kendi bellek adresini tutan gizli bir iþaretçidir.
//Ýsim Çakýþmalarýný (Name Shadowing) Çözer: Sýnýfýn kalýcý deðiþken isimleri ile kurucu metoda dýþarýdan gelen parametre isimleri ayný olduðunda, derleyicinin bu ikisini birbirine karýþtýrmadan ayýrt etmesini saðlar.
//Sýnýf Üyelerine Kesin Eriþim Saðlar: this-> kullanýmý, eþitliðin sol tarafýndaki verinin geçici bir parametre deðil, doðrudan nesnenin kendi kalýcý veri üyesi (data member) olduðunu derleyiciye ve kodu okuyana kesin olarak bildirir.

class kisi{
	public:		
	string ad;
	string soyad;
	int maas;
	
	kisi(string ad, string soyad, int maas){ // yapýcý method oluþturduk.
		this->ad = ad;
		this->soyad = soyad;
		this->maas = maas;
	}
	
	void yazdir(){ 				
		cout <<this->ad<<endl;			
		cout <<this->soyad<<endl;
		cout <<this->maas<<endl<<endl;
	}	
};


	 
int main(){
	
	kisi nesne("Mustafa", "Yilmaz", 34000);
	nesne.yazdir();


		
	return 0;
}
