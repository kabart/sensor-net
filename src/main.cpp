#include "Buffer.h"
#include "Container.h"
#include "CyclicRing.h"
#include "MainNode.h"
#include "Message.h"
#include "SafeBuffer.h"
#include "Sensor.h"

#include <iostream>
#include <memory>
#include <thread>

using namespace std;

int main(int argc, char *argv[]) {

  cout << "SIMULATION OF SENSOR NET\n";

  int bufferSize = 5;
  if (argc > 1 && atoi(argv[1]) > 0) {
    bufferSize = atoi(argv[1]);
  }

  cout << "Buffer size: " << bufferSize << endl;
  unique_ptr<Container<Message>> queue =
      make_unique<CyclicRing<Message>>(bufferSize);
  shared_ptr<Buffer<Message>> buffer =
      make_shared<SafeBuffer<Message>>(move(queue));

  // to do: create a vector of N sensors
  unique_ptr<Sensor> sensor1 =
      make_unique<Sensor>("Heat sensor", "data/temperature", buffer);
  thread thread1(&Sensor::run, move(sensor1));

  unique_ptr<Sensor> sensor2 =
      make_unique<Sensor>("Speed sensor", "data/speed", buffer);
  thread thread2(&Sensor::run, move(sensor2));

  unique_ptr<MainNode> mainNode = make_unique<MainNode>(buffer);
  thread mainThread(&MainNode::run, move(mainNode));

  thread1.join();
  thread2.join();
  mainThread.join();

  return 0;
}
