#pragma once
#include "main/primitives/polygon.h"
#include "test/test_utils/segment_utils.h"

namespace segeom {
  namespace test_utils {
    /**
     * @brief Creates a new polygon with random segments.
     */
    segeom::primitives::Polygon<double> make_random_polygon(Random *rng);

    /**
     * @brief Creates a new segment with random coordinates.
     */
    segeom::primitives::Segment<double> make_random_segment(Random *rng);
  } // namespace test_utils
} // namespace segeom