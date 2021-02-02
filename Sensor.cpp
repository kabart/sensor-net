#include "Sensor.h"

#include <chrono>
#include <thread>
using namespace std;

Sensor::Sensor(string sensorName, string fileName, double& result) : name(sensorName), data(result) {
   	read.open(fileName,ios::in);
   	if (read.is_open()){
      string description;
      getline(read, description); //unused in this moment, can be used later in sensor logs
    }
}

Sensor::~Sensor() { 
	read.close();
}

void Sensor::run() {    
	if (read.is_open()){
		string value;
		while(getline(read, value)){
			data = stod(value);
			this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}

   

