#include "CommonUtils.h"

double Segeom::TestUtils::randDouble(double lo, double hi) {
  return rand() * (hi - lo) + lo;
}

Segeom::TestUtils::Random::Random() : Random(time(0)) {}

Segeom::TestUtils::Random::Random(long seed) {
  this->seed = seed;
  rng = new std::mt19937_64(seed);
}

Segeom::TestUtils::Random::~Random() { delete rng; }

double Segeom::TestUtils::Random::nextDouble(double lo, double hi) {
  std::uniform_real_distribution<double> dist;
  return dist(*rng) * (hi - lo) + lo;
}

double Segeom::TestUtils::Random::nextNonZeroDouble(double lo, double hi) {
  while (true) {
    double r = nextDouble(lo, hi);
    if (std::abs(r) >= Segeom::TestUtils::DELTA) {
      return r;
    }
  }
}

long Segeom::TestUtils::Random::getSeed() { return seed; }
