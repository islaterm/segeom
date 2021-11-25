#include "PointUtils.h"

using namespace segeom::primitives;

segeom::primitives::Point<double> segeom::TestUtils::randPoint(Random* rng) {
  segeom::primitives::Point<double> p(rng->nextDouble(-1000, 1000),
                                      rng->nextDouble(-1000, 1000),
                                      rng->nextDouble(-1000, 1000));
  return p;
}
