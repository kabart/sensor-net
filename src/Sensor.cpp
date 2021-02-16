#include "Sensor.h"

#include <chrono>
#include <memory>
#include <thread>

using namespace std;

Sensor::Sensor(std::string sensorName, std::string fileName,
               ConcurrentQueue<Message> &buffer)
    : name(sensorName), source(fileName), queue(buffer) {}

void Sensor::run() {

  while (source.moreData()) {
    double d = source.produceData();
    Message m{name, d};
    queue.push(move(m));
  }
}
