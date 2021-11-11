#include "Primitives/VectorUtils.h"

/// <summary>
/// Creates a new random vector.
/// </summary>
Segeom::Primitives::Vector<double> Segeom::TestUtils::randVector() {
  double x2 = Segeom::TestUtils::randDouble(-1000, 1000);
  double y2 = Segeom::TestUtils::randDouble(-1000, 1000);
  double z2 = Segeom::TestUtils::randDouble(-1000, 1000);
  Segeom::Primitives::Vector<double> v(x2, y2, z2);
  return v;
}

Segeom::Primitives::Vector<double> Segeom::TestUtils::randVector(Random* rng) {
  Segeom::Primitives::Vector<double> v(rng->nextDouble(-1000, 1000),
                                       rng->nextDouble(-1000, 1000),
                                       rng->nextDouble(-1000, 1000));
  return v;
}
