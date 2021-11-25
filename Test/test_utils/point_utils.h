#pragma once

#include "common_utils.h"
#include "main/primitives/point.h"

namespace segeom {
  namespace test_utils {
    /**
     * @brief Generates a new random 3D point using a given random number generator.
     */
    segeom::primitives::Point3D<double> rand_point(Random *rng, double lo, double hi);
  } // namespace test_utils
} // namespace segeom