#ifndef _CONCURRENTQUEUE_H_
#define _CONCURRENTQUEUE_H_

#include <condition_variable>
#include <mutex>
#include <queue>

template <typename Data> class ConcurrentQueue {
private:
  std::queue<Data> queue;
  unsigned int bufferSize;
  mutable std::mutex mutex;
  std::condition_variable condVariable;

public:
  ConcurrentQueue(unsigned int size) : bufferSize(size) {}

  void push(const Data &data) {
    std::unique_lock lock(mutex);
    queue.push(data);
    lock.unlock();
    condVariable.notify_one();
    if (queue.size() > bufferSize) {
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