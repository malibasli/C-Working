#include <iostream>

using namespace std;


struct kisi{
	string ad;
	int yas;
};


int main(){
	
	int sayi = 10;
	int dizi[5] = {1,2,3,4,5};
	
	int *ptr1 = &sayi;		// burada & işareti ile adres verilir.
	int *ptr2 = dizi;		// dizinin adres operatörü gerekmez.
	
	//ptr2[2]=100;  pointer ile veri silebiliyoruz bu şekilde üzerinde yazarak.
	
	cout <<dizi[2]<<endl;
	cout << ptr2 <<endl;
	
	
	
	kisi nes1;
	kisi *ptr = &nes1;
	
	//ptr->ad = "Ahmet";
	//ptr->yas = 30;
	
	//cout<<ptr->ad<<endl;
	//cout<<ptr->yas<<endl;
	
	nes1.ad = "Mehmet";		//Her iki şeklde de değiştirilebilir.
	nes1.yas = 30;
	
	cout<<nes1.ad<<endl;
	cout<<nes1.yas<<endl;
	
	
	return 0;
}
