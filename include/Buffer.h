#ifndef _BUFFER_H_
#define _BUFFER_H_

template <typename Data> class Buffer {

public:
  Buffer() {}
  ~Buffer() {}
  virtual void push(const Data &data) = 0;
  virtual void get(Data &data) = 0;
};

#endif