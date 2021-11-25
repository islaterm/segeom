#include "common_utils.h"

using namespace segeom::test_utils;

double segeom::test_utils::randDouble(double lo, double hi) {
  return rand() * (hi - lo) + lo;
}

void segeom::test_utils::initRandom(long* seed, Random** rng) {
  std::random_device r;
  std::default_random_engine engine(r());
  std::uniform_int_distribution<int> intDist(-500000, 500000);
  *seed = intDist(engine);
  *rng = new Random(*seed);
}

void segeom::test_utils::randomCoordinates(double* x, double* y, double* z,
                                          Random* rng) {
  *x = rng->nextDouble(-5000000, 5000000);
  *y = rng->nextDouble(-5000000, 5000000);
  *z = rng->nextDouble(-5000000, 5000000);
}

std::vector<double> segeom::test_utils::translateStdVec(
    std::vector<double>& vector, Random& rng) {
  std::vector<double> translated;
  bool isTranslated = false;
  for (size_t i = 0; i < vector.size(); i++) {
    double displacement;
    if (i == vector.size() - 1 && !isTranslated) {
      displacement = rng.next_non_zero_double(-1000000, 1000000);
    } else {
      displacement = rng.nextDouble(-1000000, 1000000);
      isTranslated = displacement != 0;
    }
    translated.push_back(vector[i] + displacement);
  }
  return translated;
}

Random::Random() : Random((long)time(0)) {}

Random::Random(long seed) {
  this->seed = seed;
  rng = new std::mt19937_64(seed);
}

Random::~Random() { delete rng; }

double Random::nextDouble(double lo, double hi) {
  std::uniform_real_distribution<double> dist(lo, hi);
  return dist(*rng);
}

int Random::nextInt(int lo, int hi) {
  std::uniform_int_distribution<int> dist(lo, hi);
  return dist(*rng);
}

double Random::next_non_zero_double(double lo, double hi) {
  while (true) {
    double r = nextDouble(lo, hi);
    if (std::abs(r) >= DELTA) {
      return r;
    }
  }
}

void Random::randDoubleStdVector(double lo, double hi, std::vector<double>* out) {
  int length = this->nextInt(0, 5);
  std::vector<double> vector;
  for (int i = 0; i < length; i++) {
    vector.push_back(this->nextDouble(lo, hi));
  }
  *out = vector;
}

long Random::getSeed() { return seed; }
