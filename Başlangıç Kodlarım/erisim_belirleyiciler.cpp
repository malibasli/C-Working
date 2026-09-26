#include <iostream>

using namespace std;

struct kisi{	
	public: 		//varsayılan public structerlarda
	string ad;
	int yas;
	double boy;
};

class kisi2{
	public:		// varsayılan private classlarda
	string ad;
	int yas;
	double boy;	
};

	
int main(){
	
	kisi nesne1;
	nesne1.ad = "ahmet";
	nesne1.yas = 20;
	nesne1.boy  =1.99;
	
	cout<<"Yapiya ait bilgiler :"<<endl;
	cout<<nesne1.ad<<endl<<nesne1.yas<<endl<<nesne1.boy<<endl;
	
	kisi2 nesne2;
	nesne2.ad = "ayse";
	nesne2.yas = 21;
	nesne2.boy = 1.52;
	
	cout<<"Sinifa ait bilgiler :"<<endl;
	cout<<nesne2.ad<<endl<<nesne2.yas<<endl<<nesne2.boy<<endl;
	
	
	
	return 0;
}
