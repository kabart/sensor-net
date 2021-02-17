#ifndef _CONTAINER_H_
#define _CONTAINER_H_

template <typename Data> class Container {
protected:
  unsigned int maxSize;

public:
  Container(unsigned int size) : maxSize(size) {}
  ~Container() {}
  virtual bool empty() = 0;
  virtual void push(const Data &data) = 0;
  virtual Data &get() = 0;
};

#endif