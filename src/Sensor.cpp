#include "Sensor.h"

#include <chrono>
#include <memory>
#include <thread>

using namespace std;

Sensor::Sensor(std::string sensorName, std::string fileName,
               std::shared_ptr<Buffer<Message>> &buffer)
    : name(sensorName), source(fileName), queue(buffer) {}

void Sensor::run() {

  while (source.moreData()) {
    double d = source.produceData();
    Message m{name, d};
    queue.get()->push(move(m));
  }
}
