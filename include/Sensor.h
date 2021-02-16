#include <string>

#include "ConcurrentQueue.h"
#include "DataSource.h"
#include "Message.h"

class Sensor {
public:
  Sensor(std::string sensorName, std::string fileName,
         ConcurrentQueue<Message> &buffer);
  void run();

private:
  std::string name;
  DataSource source;
  ConcurrentQueue<Message> &queue;
};

// todo: add logging into a file
