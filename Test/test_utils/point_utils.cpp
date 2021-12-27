#include "point_utils.h"

using namespace segeom::primitives;

Point3D<double> segeom::test_utils::rand_point_3d(Random *rng, double lo = -1000,
                                                  double hi = 1000) {
  return {rng->next_double(lo, hi), rng->next_double(lo, hi), rng->next_double(lo, hi)};
}

Point2D<int> *segeom::test_utils::rand_point_2d(Random *rng, int lo, int hi) {
  return new Point2D<int>(rng->next_int(lo, hi), rng->next_int(lo, hi));
}