#ifndef _CYCLICRING_H_
#define _CYCLICRING_H_

#include "Container.h"

#include <vector>

template <typename Data> class CyclicRing : public Container<Data> {
private:
  std::vector<Data> ring;
  typename std::vector<Data>::iterator head;
  unsigned int size;

public:
  CyclicRing(unsigned int maxSize)
      : Container<Data>(maxSize), ring(maxSize, Data{}), size(0) {
    head = ring.begin();
  }

  bool empty() override { return size == 0; }

  void push(const Data &data) override {

    typename std::vector<Data>::iterator end =
        ring.begin() + ((head - ring.begin() + size) % this->maxSize);

    *end = data;

    if (size < this->maxSize) {
      size++;
    } else {
      head = ring.begin() + ((head - ring.begin() + 1) % this->maxSize);
    }
  }

  Data &get() override {
    Data &data = *head;
    head = ring.begin() + ((head - ring.begin() + 1) % this->maxSize);
    size--;
    return data;
  }
};

#endif