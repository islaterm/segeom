#include "vector_utils.h"

using namespace segeom::primitives;

Vector<double> segeom::test_utils::rand_vector(Random *rng, double lo, double hi) {
  return {rng->next_double(lo, hi), rng->next_double(lo, hi), rng->next_double(lo, hi)};
}