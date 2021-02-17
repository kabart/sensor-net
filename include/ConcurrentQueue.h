#ifndef _CONCURRENTQUEUE_H_
#define _CONCURRENTQUEUE_H_

#include "Buffer.h"

#include <condition_variable>
#include <mutex>
#include <queue>

template <typename Data> class ConcurrentQueue : public Buffer<Data> {
private:
  std::queue<Data> queue;
  mutable std::mutex mutex;
  std::condition_variable condVariable;

public:
  using Buffer<Data>::Buffer;

  void push(const Data &data) {
    std::unique_lock lock(mutex);
    queue.push(data);
    lock.unlock();
    condVariable.notify_one();
    if (queue.size() > this->bufferSize) {
      queue.pop();
    }
  }

  void get(Data &data) {
    std::unique_lock lock(mutex);
    while (queue.empty()) {
      condVariable.wait(lock);
    }
    data = queue.front();
    queue.pop();
  }
};

#endif