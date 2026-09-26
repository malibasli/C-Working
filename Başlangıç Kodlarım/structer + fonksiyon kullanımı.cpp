#include <iostream>

using namespace std;


struct kisi{
	string ad;
	int yas;
	
};

void yazdir(kisi nesne){		// buraya nesnenin kopyasý gidiyor.
		cout<<nesne.ad<<endl;
		cout<<nesne.yas<<endl;
	}
	
void yazdir_2(kisi *ptr){		// burada direk nesne üzerinde deðiþiklik yapýlýyor.
		
		cout<<ptr->ad<<endl;
		cout<<ptr->yas<<endl;
	}
	
int main(){
	
	kisi nes1;
	kisi *ptr = &nes1;
	
	nes1.ad = "ahmet";
	nes1.yas = 20;
	
	yazdir(nes1);
	yazdir_2(&nes1);		// buraya *ptr olduðu için adresi gidecek, &nes1
	
	return 0;
}
