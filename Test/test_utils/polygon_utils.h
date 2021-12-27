#pragma once
#include "main/primitives/polygon.h"
#include "test/test_utils/segment_utils.h"
#include <numbers>

namespace segeom {
  namespace test_utils {
    /**
     * @brief Creates a new polygon with random points.
     */
    segeom::primitives::Polygon<int> *make_random_polygon(Random *rng);

    /**
     * @brief Generates the division of a circumference in random angles.
     *
     * @param steps
     *    the number of angles to generate.
     * @param lo
     *    the lower bound of the random angle.
     * @param hi
     *    the upper bound of the random angle.
     * @param rng
     *    the random number generator.
     * @return std::vector<double>
     *    the list of the random angles.
     */
    std::vector<double> random_angle_steps(int steps, double lo, double hi, Random *rng);
  } // namespace test_utils
} // namespace segeom