#include "Buffer.h"
#include "Message.h"

#include <memory>

class MainNode {
public:
  MainNode(std::shared_ptr<Buffer<Message>> &buffer);
  void run();

private:
  std::shared_ptr<Buffer<Message>> &container;
};

// to do: logging into a file instead of into cout
