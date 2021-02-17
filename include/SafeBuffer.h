#ifndef _SAFEBUFFER_H_
#define _SAFEBUFFER_H_

#include "Buffer.h"
#include "Container.h"

#include <condition_variable>
#include <memory>
#include <mutex>

template <typename Data> class SafeBuffer : public Buffer<Data> {
private:
  std::unique_ptr<Container<Data>> container;
  mutable std::mutex mutex;
  std::condition_variable condVariable;

public:
  SafeBuffer(std::unique_ptr<Container<Data>> containerPtr)
      : container(std::move(containerPtr)) {}

  void push(const Data &data) override {
    std::unique_lock lock(mutex);
    container.get()->push(data);
    lock.unlock();
    condVariable.notify_one();
  }

  void get(Data &data) override {
    std::unique_lock lock(mutex);
    while (container.get()->empty()) {
      condVariable.wait(lock);
    }
    data = container.get()->get();
  }
};

#endif