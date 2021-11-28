#include "segment_utils.h"

using namespace segeom;

primitives::Point2D<double> test_utils::rand_colinear_point(test_utils::Random *rng,
                                                            primitives::Segment<double> segment) {
  double r = rng->nextDouble(0, 1);
  return (1 - r) * *segment.start() + r * *segment.end();
}

primitives::Point2D<double> test_utils::rotate_point(primitives::Point2D<double> *point,
                                                     primitives::Point2D<double> &anchor,
                                                     double angle) {
  double theta = angle * std::numbers::pi / 180;
  double sin_t = std::sin(angle);
  double cos_t = std::cos(angle);
  Point2D<double> tmp = *point - anchor;

  Point2D<double> rotated(tmp.x() * cos_t - tmp.y() * sin_t, tmp.x() * sin_t + tmp.y() * cos_t);
  return rotated + anchor;
}