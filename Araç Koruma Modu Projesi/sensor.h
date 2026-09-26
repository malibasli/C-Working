#ifndef SENSOR_H  
#define SENSOR_H 

#include <string>

using namespace std;

class Sensor{
	protected:			// deðiþtirilmeeycek þekilde ayarladýk
		string isim;
		float anlikDeger;
		float kritikEsik;
		
	public:
		Sensor(string sensorIsmi, float esikDegeri); // kurucu constructor dýþarýdan sensör bilgilerini aldýk
		void setYeniVeri(float yeniVeri);  // anlýk veri private olduðu için get set mothoud
		float getAnlikDeger()const; // get set mothoduyla dýþardan gelen veriyi içerideki hafýzaya aldýk
		virtual bool tehlikeSiniriAsildiMi()const; // virtual alt sýnýflarýn bunu ezip kendi kurallarýný yazmasýna olanak verecek.
		string getIsim() const;
};

class SicaklikSensoru:public Sensor{
	public:
		SicaklikSensoru(string sensorIsmi, float esikDegeri);
		bool tehlikeSiniriAsildiMi() const override; // sýcaklýk sensoru benim tehlike anlayýþým farklý deyip ezip geçiyor ana sýnýdýf
};

class BasincSensoru:public Sensor{
	public:
		BasincSensoru(string sensorIsmi, float esikDegeri);
		bool tehlikeSiniriAsildiMi() const override; // sýcaklýk sensoru benim tehlike anlayýþým farklý deyip ezip geçiyor ana sýnýdýf
};

#endif            
