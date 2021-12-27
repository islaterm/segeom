#include "polygon_utils.h"

using namespace segeom;

primitives::Polygon<int> *test_utils::make_random_polygon(Random *rng) {
  int num_points = rng->next_int(3, 100);
  auto irregularity = rng->next_double(0, 2 * std::numbers::pi) / num_points;
  // Radius of the circumference used as base to generate the polygon.
  auto base_radius = rng->next_double(0, 100000);
  auto lo = (2 * std::numbers::pi / num_points) - irregularity;
  auto hi = (2 * std::numbers::pi / num_points) + irregularity;
  std::vector<int> angles;

  std::vector<Point2D<int>> points;
  auto angle = rng->next_double(0, 2 * std::numbers::pi);
  auto center = test_utils::rand_point_2d(rng);
  for (size_t i = 0; i < num_points; i++) {
    auto r_i = rng->next_double_gauss(base_radius, irregularity);
    auto x = static_cast<int>(center->x() + r_i * std::cos(angle));
    auto y = static_cast<int>(center->y() + r_i * std::sin(angle));
    points.push_back(Point2D<int>(x, y));
  }
  return new Polygon<int>(points);
}

std::vector<double> test_utils::random_angle_steps(int steps, double lo, double hi, Random *rng) {
  std::vector<double> angles;
  double cums = 0;
  // Generates the random step between each point along the circumference.
  for (int i = 0; i < steps; i++) {
    auto angle = rng->next_double(lo, hi);
    angles.push_back(angle);
    cums += angle;
  }
  // Normalizes the angles so point 0 is the same as point n + 1
  cums /= 2 * std::numbers::pi;
  for (size_t i = 0; i < angles.size(); i++) {
    angles[i] /= cums;
  }
  return angles;
}