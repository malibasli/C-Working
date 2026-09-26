#include <iostream>
#include "telemetriyoneticisi.h"

using namespace std;

TelemetriYoneticisi::TelemetriYoneticisi(){
	limpModeAktifMi = false;
}
	
void TelemetriYoneticisi::setSensor(Sensor* yeniSensor){
	sensorHatti.push_back(yeniSensor); // vector içine yeniSensörü pushladýk.
}

void TelemetriYoneticisi::sistemDurumuTara(){
	for(int i = 0; i < sensorHatti.size(); i++){
		
		if(sensorHatti[i]->tehlikeSiniriAsildiMi()==true){
			limpModeAktifMi = true;
			cout<<"Kritik Ariza"<<" ";
			cout<<sensorHatti[i]->getIsim()<<":"<<" "<<sensorHatti[i]->getAnlikDeger()<<endl;
		}
		else{
			cout<<sensorHatti[i]->getIsim()<<" "<<"is normal."<<endl;
		}
	}
	
}
