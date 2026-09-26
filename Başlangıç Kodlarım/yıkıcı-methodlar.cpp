#include <iostream>

using namespace std;

class kisi{
	private:		
	string ad;
	string soyad;
	int maas;	
	
	public:
	kisi(string ad, string soyad, int maas){
		cout<<"yapici method calisti"<<endl;
		this->ad = ad;
		this->soyad = soyad;
		this->maas = maas;
	}
	~kisi(){  									// yýkýcý method için gerekli satýr.
		cout<<"Yikici method calisti."<<endl;
	}
	
	public:
	void setAd(string ad){
		this->ad = ad;
	}
	
	void setMaas(int maas){
		this->maas = maas;	
	}
	
	void setSoyad(string soyad){
		this->soyad = soyad;	
	}
	
	///////////////////////
	
	string getAd(){
		return ad;
	}
	
	string getSoyad(){
		return soyad;
	}
	
	int getMaas(){
		return maas;
	}
};

	
int main(){
	
	kisi *ptr = new kisi("Saliha", "sahin",4000); // yýkýcý method için ptr kullanmak þart.
	
	delete ptr;
	
	
	return 0;
}
