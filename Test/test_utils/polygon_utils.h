#pragma once
#include "test/test_utils/segment_utils.h"
#include "main/primitives/polygon.h"

namespace segeom {
  namespace test_utils {
    /**
     * @brief Creates a new polygon with random segments.
     */
    segeom::primitives::Polygon<double> make_random_polygon(Random *rng);
  }
}