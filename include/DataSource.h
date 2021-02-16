#include <fstream>

class DataSource {
  std::fstream read;

public:
  DataSource(std::string fileName);
  ~DataSource();
  bool moreData();
  double produceData();
};