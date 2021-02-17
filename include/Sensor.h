#include <memory>
#include <string>

#include "ConcurrentQueue.h"
#include "DataSource.h"
#include "Message.h"

class Sensor {
public:
  Sensor(std::string sensorName, std::string fileName,
         std::shared_ptr<Buffer<Message>> &buffer);
  void run();

private:
  std::string name;
  DataSource source;
  std::shared_ptr<Buffer<Message>> &queue;
};

// todo: add logging into a file
