#include "../include/CyclicRing.h"

#include <vector>

#include "gtest/gtest.h"

TEST(ringTest, empty) {
  CyclicRing<int> ring(5);
  ASSERT_EQ(true, ring.empty());
}

TEST(ringTest, testname) {
  CyclicRing<int> ring(10);
  for (int i = 1; i <= 11; i++)
    ring.push(i);

  std::vector<int> values{2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  for (int i = 0; i < 10; i++)
    ASSERT_EQ(values[i], ring.get());

  ASSERT_EQ(true, ring.empty());
}
