#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Container.h"

#include <queue>

template <typename Data> class Queue : public Container<Data> {
private:
  std::queue<Data> queue;

public:
  using Container<Data>::Container;

  bool empty() override { return queue.empty(); }

  void push(const Data &data) override {
    queue.push(data);
    if (queue.size() > this->maxSize) {
      queue.pop();
    }
  }

  Data &get() override {
    Data &data = queue.front();
    queue.pop();
    return data;
  }
};

#endif