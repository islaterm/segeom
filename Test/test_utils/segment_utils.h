#pragma once
#include "main/primitives/segment.h"
#include "point_utils.h"
#include <numbers>

namespace segeom {
  namespace test_utils {
    using namespace segeom::primitives;

    Point2D<double> rand_colinear_point(Random *rng, Segment<double> segment);

    /**
     * @brief Rotates a point according to an anchor
     */
    Point2D<double> rotate_point(Point2D<double> *point, Point2D<double> &anchor, double angle);
  } // namespace test_utils
} // namespace segeom
