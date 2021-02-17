#ifndef _BUFFER_H_
#define _BUFFER_H_

template <typename Data> class Buffer {
protected:
  unsigned int bufferSize;

public:
  Buffer(unsigned int size) : bufferSize(size) {}
  ~Buffer() {}
  virtual void push(const Data &data) = 0;
  virtual void get(Data &data) = 0;
};

#endif