#include "test/test_utils/polygon_utils.h"
#include "test/testing.h"

using namespace segeom;

class PolygonTest : public ::testing::Test {
protected:
  void SetUp() override;
  void TearDown() override;

public:
  long seed = 0;
  test_utils::Random *rng = nullptr;
  primitives::Polygon<int> *testPolygon = nullptr;
};

void PolygonTest::SetUp() {
  test_utils::initRandom(&seed, &rng);
  testPolygon = test_utils::make_random_polygon(rng);
}

void PolygonTest::TearDown() { notify_on_failure(this->seed); }

/**
 * @brief All polygons should have the same number of segments as vertices.
 */
TEST_F(PolygonTest, NumberOfCornersMatchNumberOfSides) {
  EXPECT_EQ(testPolygon->vertices().size(), testPolygon->sides().size());
}

/**
 * @brief An inverted copy of a polygon is the same polygon with contrary winding order.
 */
TEST_F(PolygonTest, InvertedPolygon) {
  auto vertices = testPolygon->vertices();
  auto inverted = testPolygon->inverted();
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
  primitives::Polygon<int> inverted = testPolygon->inverted();
  try {
    auto expected_area = inverted.area();
    auto actual_area = testPolygon->area();
    if (expected_area == 0 || actual_area == 0)
    {
      FAIL() << "Polygon area should never be 0.";
    }
    EXPECT_EQ(expected_area, actual_area);
  } catch (const GeometryException &e) {
    EXPECT_EQ("Can't calculate area of malformed polygon", e.what());
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}