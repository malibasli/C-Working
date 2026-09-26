#include <iostream>

using namespace std;
//NOT!!!: POINTERLAR ÝLE ÇALIÞMAK BELLEKTE DAHA AZ YER KAPLAR.
// BU SEBEPLE DAHA PERFORMANLI PROJELER OLUÞTURULABLÝR.

class kisi{
	public:		
	string ad;
	string soyad;
	int maas;
	
};
void yazdir(kisi nesne){ 				// burada nesnenin kopyasý oluþtu
		cout <<nesne.ad<<endl;			// iki tane ahmet oldu
		cout <<nesne.soyad<<endl;
		cout <<nesne.maas<<endl<<endl;
	}
	
void yazdirPtr(kisi *nesne){			//pointer ile fonk kullanma yazdýrma
		cout <<nesne->ad<<endl;			// burda tek nesne var çünkü direk adresi geldi
		cout <<nesne->soyad<<endl;		//yeni bir nesne oluþturulmadý.
		cout <<nesne->maas<<endl<<endl;
	}	

	 
int main(){
	
	
	kisi o1;
	o1.ad  = "ahmet";
	o1.soyad = "su";
	o1.maas = 22;
	o1.maas = 500000;
	yazdir(o1);
	
	
	kisi *ptrNesne = new kisi();  	// nesne tanýmlamayla ayný iþi yapar 
									// bellekte yeni bir yer ayýrýr
								
	ptrNesne->ad  ="Mehmet";
	ptrNesne->soyad = "toprak";
	ptrNesne->maas = 60000;
	
	yazdir(*ptrNesne);
	
	//cout <<ptrNesne->ad<<endl;
	//cout <<ptrNesne->soyad<<endl;
	//cout <<ptrNesne->maas<<endl<<endl;

		
	return 0;
}
