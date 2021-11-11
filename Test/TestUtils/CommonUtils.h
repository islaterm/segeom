#pragma once

#include <stdlib.h>

#include <ctime>
#include <random>

namespace Segeom {
namespace TestUtils {
/// <summary>
/// Acceptable difference for floating point comparison.
/// </summary>
const double DELTA = 1e-32;
class Random {
 public:
  Random();
  Random(long seed);
  ~Random();

  /// <summary>
  /// Returns a random double precision number between <c>lo</c> and <c>hi</c>.
  /// </summary>
  double nextDouble(double lo, double hi);
  /// <summary>
  /// Returns a random non-zero double precision number between <c>lo</c> and
  /// <c>hi</c>.
  /// </summary>
  double nextNonZeroDouble(double lo, double hi);
  long getSeed();

 private:
  long seed;
  std::mt19937_64 *rng;
};
double randDouble(double lo, double hi);
}  // namespace TestUtils
}  // namespace Segeom