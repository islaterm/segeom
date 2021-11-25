#include "Testing.h"

void notify_on_failure(long seed) {
  if (::testing::Test::HasFailure()) {
    std::cout << "Test failed with seed = " << seed << std::endl;
  }
}
