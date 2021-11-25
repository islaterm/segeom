#include "point_utils.h"

using namespace segeom::primitives;

Point3D<double> segeom::test_utils::rand_point(Random *rng, double lo = -1000, double hi = 1000) {
  return {rng->nextDouble(lo, hi), rng->nextDouble(lo, hi), rng->nextDouble(lo, hi)};
}
