#include "PointUtils.h"

Segeom::Primitives::Point<double> Segeom::TestUtils::randPoint(Random* rng) {
  Segeom::Primitives::Point<double> p(rng->nextDouble(-1000, 1000),
                                       rng->nextDouble(-1000, 1000),
                                       rng->nextDouble(-1000, 1000));
  return p;
}
