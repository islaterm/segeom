#include "../TestUtils/SegmentUtils.h"
#include "../Testing.h"

namespace Utils = Segeom::TestUtils;

class SegmentTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  Utils::Random* rng = nullptr;
  Segeom::Primitives::Point<double>* testPoint1 = nullptr;
  Segeom::Primitives::Point<double>* testPoint2 = nullptr;
  Segeom::Primitives::Segment<double>* testSegment = nullptr;
};

void SegmentTest::SetUp() {
  Utils::initRandom(&seed, &rng);
  testPoint1 = &Utils::randPoint(rng);
  testPoint2 = &Utils::randPoint(rng);
  testSegment = new Segeom::Primitives::Segment<double>(testPoint1, testPoint2);
}

void SegmentTest::TearDown() { notifyOnFailure(seed); }

/// <summary>
/// Two segments are equal if the start and end points are equal.
/// </summary>
TEST_F(SegmentTest, Equality) {
  Segeom::Primitives::Segment<double> expected(testPoint1, testPoint2);
  EXPECT_EQ(expected, *testSegment);
}