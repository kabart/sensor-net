#include "MainKnot.h"

#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

MainKnot::MainKnot(unsigned int size) : bufforSize(size) {
   cout << "Main knot created - buffor size: " << bufforSize << endl;
}

void MainKnot::run(double& read1, double& read2) {
	
	cout << "Main knot running...\n";
	while(1) {
		this_thread::sleep_for(std::chrono::seconds(1));
		//to do: check if a sensor started reading already (now it is a default value until a sensor actually reads)
		Message m{read1, read2};
		write(m);
	}
}

void MainKnot::write(Message m) {
	buffor.push(m);
	cout << "Message received: " << "temperature - " << m.value1 << " speed - " << m.value2 << endl;
	if (buffor.size() > bufforSize) {
		remove();
	}
}

Message MainKnot::read() {
	return buffor.front();
}

void MainKnot::remove() {
	buffor.pop();
	cout << "Buffor size exceeded - message removed.\n";
}


