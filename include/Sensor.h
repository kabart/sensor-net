#include <fstream>
#include <string>

#include "ConcurrentQueue.h"
#include "Message.h"

class Sensor {
public:
  Sensor(std::string sensorName, std::string fileName,
         ConcurrentQueue<Message> &buffer);
  ~Sensor();
  void run();
  bool emit(Message &message);

private:
  std::string name;
  std::fstream read;
  ConcurrentQueue<Message> &queue;
};

// todo: add logging into a file
