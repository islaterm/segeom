#include "Testing.h"

void notifyOnFailure(long seed) {
  if (::testing::Test::HasFailure()) {
    std::cout << "Test failed with seed = " << seed << std::endl;
  }
}
