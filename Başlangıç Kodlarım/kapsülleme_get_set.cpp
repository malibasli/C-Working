#include <iostream>

using namespace std;

class kisi{
	private:		
	string ad;
	int yas;
	double boy;	
	
	//methodlara kýsýtlamalar koymak için get set sistemi kullanýlýr.
	public:
	void setAd(string ad){
		this->ad = ad;
	}
	
	void setYas(int yas){
		if (yas>=0 && yas<100)
			this->yas = yas;
		else
			cout<<"yas girisnde hata var."<<endl;	
		
	}
	
	void setBoy(double boy){
		if(boy>=0 && boy < 3)
			this->boy = boy;
		else
			cout<<"Boy girisinde hata var."<<endl;	
	}
	
	///////////////////////
	
	string getAd(){
		return ad;
	}
	
	int getYas(){
		return yas;
	}
	
	double getBoy(){
		return boy;
	}
};

	
int main(){
	
	// n1;
	//n1.ad = "ahmet";
	//n1.boy = 1.85;
	//n1.yas = 22;
	
	//cout<<n1.ad<<endl;
	//cout<<n1.yas<<endl;
	//cout<<n1.boy<<endl;
	
	kisi n1;
	n1.setAd("ahmet");
	n1.setYas(20);
	n1.setBoy(1.84);
	
	cout<<n1.getAd()<<endl;
	cout<<n1.getYas()<<endl;
	cout<<n1.getBoy()<<endl;
	
	
	
	return 0;
}
