#include "ConcurrentQueue.h"
#include "Message.h"

class MainNode {
public:
  MainNode(ConcurrentQueue<Message> &buffer);
  void run();

private:
  ConcurrentQueue<Message> &queue;
};

// to do: logging into a file instead of into cout
