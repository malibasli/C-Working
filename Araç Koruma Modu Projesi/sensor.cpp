#include <iostream>
#include "sensor.h"

Sensor::Sensor(string sensorIsmi, float esikDegeri){
	isim = sensorIsmi;
	kritikEsik = esikDegeri;
	anlikDeger = 0.0;  // anlýk degeri de baþta 0 kabul ettik.
}

void Sensor::setYeniVeri(float yeniVeri){
	anlikDeger = yeniVeri;   // gelen veri geçici deðiken üzeridne anlýkDeger e yazdýlý
}

float Sensor::getAnlikDeger()const{
	return anlikDeger;  // burada ise anlýkdeðer okunudu
}

string Sensor::getIsim() const {
    return isim;
}

bool Sensor::tehlikeSiniriAsildiMi()const{
	return false;		
}

// SýcaklýkSensoru kurucu contructor gelen veriyi Sensor classýna yönlendirir.
SicaklikSensoru::SicaklikSensoru(string sensorIsmi, float esikDegeri):Sensor(sensorIsmi, esikDegeri){ 
}

// SýcaklýkSensoru tehlikesýnýrýaþýldýmý çalýþarak eþikten yukarý çýkarsa 
bool SicaklikSensoru::tehlikeSiniriAsildiMi() const {
    return anlikDeger > kritikEsik; 
}

// BasýncSensoru kurucu contructordan gelen veriyi Sensor classýna yönlendirir.
BasincSensoru::BasincSensoru(string sensorIsmi, float esikDegeri):Sensor(sensorIsmi, esikDegeri){
}

bool BasincSensoru::tehlikeSiniriAsildiMi() const {
    return anlikDeger < kritikEsik; 
}
