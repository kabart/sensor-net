#include "ConcurrentQueue.h"
#include "Message.h"

class MainNode {
public:
  MainNode(std::shared_ptr<Buffer<Message>> &buffer);
  void run();

private:
  std::shared_ptr<Buffer<Message>> &queue;
};

// to do: logging into a file instead of into cout
