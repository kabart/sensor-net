#ifndef _CONCURRENTQUEUE_H_
#define _CONCURRENTQUEUE_H_

#include <mutex>
#include <queue>

template <typename Data> class ConcurrentQueue {
private:
  std::queue<Data> queue;
  unsigned int bufferSize;
  mutable std::mutex mutex;

public:
  ConcurrentQueue(unsigned int size) : bufferSize(size) {}

  void push(const Data &data) {
    std::scoped_lock lock(mutex);
    queue.push(data);
    if (queue.size() > bufferSize) {
      queue.pop();
    }
  }

  bool next(Data &data) {
    std::scoped_lock lock(mutex);
    if (queue.empty()) {
      return false;
    } else {
      data = queue.front();
      queue.pop();
      return true;
    }
  }
};

#endif