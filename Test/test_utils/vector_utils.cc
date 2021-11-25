#include "vector_utils.h"

using namespace segeom::primitives;

Vector<double> segeom::test_utils::rand_vector(Random *rng, double lo, double hi) {
  return {rng->nextDouble(lo, hi), rng->nextDouble(lo, hi), rng->nextDouble(lo, hi)};
}