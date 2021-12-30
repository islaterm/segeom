#include "test/test_utils/polygon_utils.h"
#include "test/testing.h"
#include <string>

using namespace segeom;

class PolygonTest : public ::testing::Test {
protected:
  void SetUp() override;
  void TearDown() override;

public:
  long seed = 0;
  test_utils::Random *rng = nullptr;
  primitives::Polygon<int> *test_polygon = nullptr;
};

void PolygonTest::SetUp() {
  test_utils::initRandom(&seed, &rng);
  test_polygon = test_utils::make_random_polygon(rng);
}

void PolygonTest::TearDown() { notify_on_failure(this->seed); }

/**
 * @brief All polygons should have the same number of segments as vertices.
 */
TEST_F(PolygonTest, NumberOfCornersMatchNumberOfSides) {
  EXPECT_EQ(test_polygon->vertices().size(), test_polygon->sides().size());
}

TEST_F(PolygonTest, CopyConstructor) {
  Polygon<int> expected(*test_polygon);
  EXPECT_EQ(*test_polygon, expected); // TODO: Define ==
}

/**
 * @brief An inverted copy of a polygon is the same polygon with contrary winding order.
 */
TEST_F(PolygonTest, InvertedPolygon) {
  auto vertices = test_polygon->vertices();
  auto inverted = test_polygon->inverted();
  size_t size = vertices.size();
  for (int i = size - 1; i >= 0; i--) {
    EXPECT_EQ(vertices[i], inverted.vertices()[size - (i + 1)]);
  }
}

/**
 * @brief The area of two polygons with the same vertices and sides, but different winding order
 *        should be equal in magnitude but contrary on sign.
 */
TEST_F(PolygonTest, InvertedOrientationArea) {
  primitives::Polygon<int> inverted = test_polygon->inverted();
  auto expected_area = inverted.area();
  auto actual_area = test_polygon->area();
  EXPECT_EQ(expected_area, actual_area);
}

TEST_F(PolygonTest, RegularPolygonArea) {
  int num_vertices = rng->next_int(3, 4);
  int radius = rng->next_int(1, 2);
  primitives::Polygon<double> *regular_polygon =
      test_utils::make_regular_polygon(num_vertices, radius);
  auto expected_area = 0.5 * num_vertices * std::pow(num_vertices, 2) *
                       std::sin(2 * std::numbers::pi / num_vertices);
  EXPECT_DOUBLE_EQ(expected_area, regular_polygon->area());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}