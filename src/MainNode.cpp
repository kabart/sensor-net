#include "MainNode.h"

#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

MainNode::MainNode(std::shared_ptr<Buffer<Message>> &buffer) : queue(buffer) {
  cout << "Main node created." << endl;
}

void MainNode::run() {

  cout << "Main node running...\n";
  while (true) {
    Message m;
    queue.get()->get(m);
    cout << "Message received: "
         << "sensor name - " << m.sensorName << ", value - " << m.value << endl;
  }
}
