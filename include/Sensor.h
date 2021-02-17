#include "Buffer.h"
#include "DataSource.h"
#include "Message.h"

#include <memory>
#include <string>

class Sensor {
public:
  Sensor(std::string sensorName, std::string fileName,
         std::shared_ptr<Buffer<Message>> &buffer);
  void run();

private:
  std::string name;
  DataSource source;
  std::shared_ptr<Buffer<Message>> &container;
};

// todo: add logging into a file
