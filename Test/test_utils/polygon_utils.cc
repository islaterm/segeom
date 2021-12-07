#include "polygon_utils.h"

using namespace segeom;

primitives::Polygon<double> test_utils::make_random_polygon(Random *rng) {
  int num_points = rng->nextInt(3, 100);
  std::vector<Point2D<double> &> points;
  for (int i = 0; i < num_points; i++) {
    points.push_back(*test_utils::rand_point_2d(rng));
  }
  return {points};
}
