#include "MainKnot.h"
#include "Sensor.h"

#include <iostream>
#include <memory>
#include <thread>

using namespace std;

int main(int argc, char *argv[]) {

	cout << "simulation of sensor net\n" << endl;
	 
    int bufforSize = 5;
    if (argc > 0 && atoi(argv[1])>0) {
		
		bufforSize = atoi(argv[1]);
	}	 

	//to do: create a vector of N sensors
	double data1{0};
	unique_ptr<Sensor> sensor1 = make_unique<Sensor>("Heat sensor", "temperature", data1);
	thread thread1(&Sensor::run, move(sensor1));
	
	double data2{0};
	unique_ptr<Sensor> sensor2 = make_unique<Sensor>("Speed sensor", "speed", data2);
	thread thread2(&Sensor::run, move(sensor2));
	
	unique_ptr<MainKnot> mainKnot = make_unique<MainKnot>(bufforSize);
	thread mainThread(&MainKnot::run, move(mainKnot), ref(data1), ref(data2));
    
    thread1.join();
    thread2.join();
    mainThread.join();
    
    return 0;
}
