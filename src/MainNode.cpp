#include "MainNode.h"

#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

MainNode::MainNode(ConcurrentQueue<Message> &buffer) : queue(buffer) {
  cout << "Main node created." << endl;
}

void MainNode::run() {

  cout << "Main node running...\n";
  while (true) {
    Message m;
    if (queue.next(m)) {
      cout << "Message received: "
           << "sensor name - " << m.sensorName << ", value - " << m.value
           << endl;
    } else {
      this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
}
