#include "SegmentTest.h"

#include "../../GeometricFault/Primitives/Vector.h"
#include "../TestUtils/SegmentUtils.h"
#include "../Testing.h"

namespace Utils = segeom::TestUtils;
using namespace segeom::primitives;

class SegmentTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  Utils::Random* rng = nullptr;
  Point3D<double>* testPoint1 = nullptr;
  Point3D<double>* testPoint2 = nullptr;
  Segment<double>* testSegment = nullptr;

  /// <summary>
  /// Moves a segment
  /// </summary>
  /// <param name="originalSegment">The segment to be translated.</param>
  /// <returns>The translated segment.</returns>
  Point3D<double>* translatePoint(Point<double>* originalSegment);
};

void SegmentTest::SetUp() {
  Utils::initRandom(&seed, &rng);
  testPoint1 = &Utils::randPoint(rng);
  testPoint2 = &Utils::randPoint(rng);
  testSegment = new Segment<double>(testPoint1, testPoint2);
}

void SegmentTest::TearDown() { notify_on_failure(seed); }

Point3D<double>* SegmentTest::translatePoint(Point3D<double>* originalPoint) {
  double x = testPoint1->x();
  double y = testPoint1->y();
  double z = testPoint1->z();

  double dx = rng->nextNonZeroDouble(-1000000, 1000000);
  double dy = rng->nextNonZeroDouble(-1000000, 1000000);
  double dz = rng->nextNonZeroDouble(-1000000, 1000000);
  return new Point3D<double>(x + dx, y + dy, z + dz);
}

#pragma region EQUALITY
/// <summary>
/// Two segments are equal if the start and end points are equal.
/// </summary>
TEST_F(SegmentTest, Equality) {
  Segment<double>* expected = new Segment<double>(testPoint1, testPoint2);
  EXPECT_EQ(*expected, *testSegment);
}

/// <summary>
/// Two segments are different if the start and end points are different.
/// </summary>
TEST_F(SegmentTest, DifferentPoints) {
  Segment<double>* unexpected =
      new Segment<double>(translatePoint(testPoint1), testPoint2);
  EXPECT_NE(*unexpected, *testSegment);

  unexpected = new Segment<double>(testPoint1, translatePoint(testPoint2));
  EXPECT_NE(*unexpected, *testSegment);

  unexpected = new Segment<double>(translatePoint(testPoint1),
                                   translatePoint(testPoint2));
  EXPECT_NE(*unexpected, *testSegment);
}

/// <summary>
/// Two segments with different orientation are different.
/// </summary>
TEST_F(SegmentTest, DifferentOrientation) {
  Segment<double>* unexpected = new Segment<double>(testPoint2, testPoint1);
  EXPECT_NE(*unexpected, *testSegment);
}
#pragma endregion

#pragma region LENGTH
/// <summary>
/// The length of a segment should be equal to the magnitude of the vector
/// obtained by translating the segment to (0, 0).
/// </summary>
TEST_F(SegmentTest, Length) {
  Point3D<double>* testPoint1 = &Utils::randPoint(rng);
  Point3D<double>* testPoint2 = &Utils::randPoint(rng);
  Segment<double>* testSegment = new Segment<double>(testPoint1, testPoint2);
  Vector<double>* v =
      new Vector<double>(testPoint2->x() - testPoint1->x(),
                         testPoint2->y() - testPoint1->y(),
                         testPoint2->z() - testPoint1->z());
  EXPECT_EQ(v->magnitude(), testSegment->length());
}
#pragma endregion

#pragma region SLOPE
TEST_F(SegmentTest, Slope) {
  Point3D<double>* newPoint = translatePoint(testPoint1);
  Segment<double>* newSegment = new Segment<double>(testPoint1, newPoint);
  double expected = (newPoint->y() - testPoint1->y()) /
                    (newPoint->x() - testPoint1->x());
  //EXPECT_DOUBLE_EQ(expected, newSegment->slope());
}

TEST_F(SegmentTest, ZeroSlope) {
  //Point<double> newPoint(testPoint1->getX() + rng->nextNonZeroDouble(), testPoint1->getY() )
}
#pragma endregion