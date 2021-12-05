#include "polygon_utils.h"

using namespace segeom;

primitives::Polygon<double> test_utils::make_random_polygon(Random *rng) {
  int num_segments = rng->nextInt(3, 100);
  std::vector<Segment<double>> segments;
  // caso inicial
  // create n segments where a = v_{i-1} and a = v_{i} are its limits.
  primitives::Point2D<double> *start = rand_point_2d(rng);
  for (int i = 0; i <= num_segments; i++) {
    primitives::Segment<double> segment(start, rand_point_2d(rng));
    segments.push_back(make_random_segment(rng));
    start = segment.start();
  }
  // handdle last segment
  // Build a polygon with the n segments.
}

primitives::Segment<double> test_utils::make_random_segment(Random *rng) {
  // create random pair of points
  // create new segment
}