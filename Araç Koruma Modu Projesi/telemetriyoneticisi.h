#ifndef TELEMETRI_YONETICISI_H
#define TELEMETRI_YONETICISI_H
#include <vector>
#include <string>
#include "sensor.h"

using namespace std;

class TelemetriYoneticisi{
	private:
		vector<Sensor*> sensorHatti; // Sensor classýndan üretilen nesneleri dinamik bir dizi içinde tutmuþ oluruz.
		bool limpModeAktifMi;		// buraya nesnenin adresini vererek 
	
	public:
		TelemetriYoneticisi(); // kurucu Constructor
		void setSensor(Sensor* yeniSensor);
		void sistemDurumuTara();
};

#endif
