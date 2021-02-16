#include "DataSource.h"

#include <chrono>
#include <thread>

DataSource::DataSource(std::string fileName) {
  read.open(fileName, std::ios::in);
  std::string description;
  getline(
      read,
      description); // unused in this moment, can be used later in sensor logs
}

DataSource::~DataSource() { read.close(); }

bool DataSource::moreData() { return !read.eof(); }

double DataSource::produceData() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::string value;
  getline(read, value);
  return stod(value);
}
