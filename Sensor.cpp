#include "Sensor.h"

#include <chrono>
#include <thread>

using namespace std;

Sensor::Sensor(std::string sensorName, std::string fileName,
               ConcurrentQueue<Message> &buffer)
    : name(sensorName), queue(buffer) {
  read.open(fileName, ios::in);
  if (read.is_open()) {
    string description;
    getline(
        read,
        description); // unused in this moment, can be used later in sensor logs
  }
}

Sensor::~Sensor() { read.close(); }

void Sensor::run() {

  while (true) {
    Message m;
    if (emit(m)) {
      queue.push(move(m));
      this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
}

bool Sensor::emit(Message &message) {
  string value;
  if (getline(read, value)) {
    double data = stod(value);
    message.sensorName = name;
    message.value = data;
    return true;
  } else
    return false;
}
