#include "polygon_utils.h"

using namespace segeom;

primitives::Polygon<int> *test_utils::make_random_polygon(Random *rng) {
  int num_points = rng->next_int(3, 100);
  std::vector<Point2D<int>> points;
  for (int i = 0; i < num_points; i++) {
    points.push_back(*test_utils::rand_point_2d(rng));
  }
  return new Polygon<int>(points);
}
