#include "polygon_utils.h"

using namespace segeom;

primitives::Polygon<double> test_utils::make_random_polygon(Random *rng) {
  int num_segments = rng->nextInt(3, 100);
  // create n segments where a = v_{i-1} and a = v_{i} are its limits.
  // Build a polygon with the n segments.
}