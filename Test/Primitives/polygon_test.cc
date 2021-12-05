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
  primitives::Polygon<double> *testPolygon = nullptr;
};

void PolygonTest::SetUp() {
  test_utils::initRandom(&seed, &rng);
  test_utils::make_random_polygon(rng);
}

void PolygonTest::TearDown() { notify_on_failure(this->seed); }

/**
 * @brief All polygons should have the same number of segments as vertices.
 */
TEST_F(PolygonTest, NumberOfCornersMatchNumberOfSides) {
  EXPECT_EQ(testPolygon->vertices()->length(), testPolygon->sides()->length);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}