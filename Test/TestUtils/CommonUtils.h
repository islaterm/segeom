#pragma once

#include <stdlib.h>

#include <ctime>
#include <random>

namespace Segeom {
namespace TestUtils {
class Random {
 public:
  Random();
  Random(long seed);
  ~Random();

  double nextDouble(double lo, double hi);
  long getSeed();
 private:
  long seed;
  std::mt19937_64 *rng;
};
double randDouble(double lo, double hi);
}  // namespace TestUtils
}  // namespace Segeom