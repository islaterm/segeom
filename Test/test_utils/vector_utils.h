#pragma once

#include "main/primitives/vector.h"
#include "test/test_utils/point_utils.h"

namespace segeom {
  namespace test_utils {
    /**
     * @brief Generates a new random vector.
     * @param rng
     *    A random number generator.
     * @return The created vector.
     */
    segeom::primitives::Vector<double> rand_vector(Random *rng, double lo = -1000000, double hi = 1000000);
  } // namespace test_utils
} // namespace segeom