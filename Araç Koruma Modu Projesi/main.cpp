#include <iostream>
#include "sensor.h"
#include "telemetriyoneticisi.h"

using namespace std;

int main() {
	
	TelemetriYoneticisi actrosECU;
	
	SicaklikSensoru sanzimanSicaklik("Sanziman Yag Sicakligi", 115.0);
    BasincSensoru turboBasinci("Turbo Basinci", 2.5);
    
    actrosECU.setSensor(&sanzimanSicaklik);
    actrosECU.setSensor(&turboBasinci);
    
    cout << "--- DURUM 1: HER SEY NORMAL ---" << endl;
    sanzimanSicaklik.setYeniVeri(90.5); // 115'ten küçük -> OK
    turboBasinci.setYeniVeri(2.5);      // 2.0'dan büyük -> OK
    actrosECU.sistemDurumuTara();
    
    cout << "\n--- DURUM 2: BASINC KACAGI ---" << endl;
    sanzimanSicaklik.setYeniVeri(95.0); // 115'ten küçük -> OK
    turboBasinci.setYeniVeri(1.2);      // 2.0'ýn altýna düþtü -> ARIZA VERECEK!
    actrosECU.sistemDurumuTara();
		
	return 0;
}
