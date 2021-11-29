#include "main/primitives/vector.h"
#include "test/test_utils/segment_utils.h"
#include "test/testing.h"

#pragma clang diagnostic push
namespace utils = segeom::test_utils;
using namespace segeom::primitives;

class SegmentTest : public ::testing::Test {
protected:
  void SetUp() override;

  void TearDown() override;

public:
  long seed = 0;
  utils::Random *rng = nullptr;
  Point2D<double> *test_point_1 = nullptr;
  Point2D<double> *test_point_2 = nullptr;
  Segment<double> *test_segment = nullptr;

  /**
   * @brief Moves a segment.
   *
   * @param originalSegment The segment to be translated.
   * @return The translated segment.
   */
  Point2D<double> *translatePoint(Point2D<double> *originalSegment);
};

void SegmentTest::SetUp() {
  utils::initRandom(&seed, &rng);
  test_point_1 = utils::rand_point_2d(rng);
  test_point_2 = utils::rand_point_2d(rng);
  test_segment = new Segment<double>(test_point_1, test_point_2);
}

void SegmentTest::TearDown() { notify_on_failure(seed); }

Point2D<double> *SegmentTest::translatePoint(Point2D<double> *originalPoint) {
  double x = test_point_1->x();
  double y = test_point_1->y();

  double dx = rng->next_non_zero_double(-1000, 1000);
  double dy = rng->next_non_zero_double(-1000, 1000);
  double dz = rng->next_non_zero_double(-1000, 1000);
  return new Point2D<double>(x + dx, y + dy);
}

#pragma region EQUALITY
/// <summary>
/// Two segments are equal if the start and end points are equal.
/// </summary>
TEST_F(SegmentTest, Equality) {
  Segment<double> *expected = new Segment<double>(test_point_1, test_point_2);
  EXPECT_EQ(*expected, *test_segment);
}

/// <summary>
/// Two segments are different if the start and end points are different.
/// </summary>
TEST_F(SegmentTest, DifferentPoints) {
  Segment<decltype(1.0)> *unexpected =
      new Segment<double>(translatePoint(test_point_1), test_point_2);
  EXPECT_NE(*unexpected, *test_segment);

  unexpected = new Segment<double>(test_point_1, translatePoint(test_point_2));
  EXPECT_NE(*unexpected, *test_segment);

  unexpected = new Segment<double>(translatePoint(test_point_1), translatePoint(test_point_2));
  EXPECT_NE(*unexpected, *test_segment);
}

/// <summary>
/// Two segments with different orientation are different.
/// </summary>
TEST_F(SegmentTest, DifferentOrientation) {
  Segment<double> *unexpected = new Segment<double>(test_point_2, test_point_1);
  EXPECT_NE(*unexpected, *test_segment);
}
#pragma endregion

#pragma region LENGTH
/// <summary>
/// The length of a segment should be equal to the magnitude of the vector
/// obtained by translating the segment to (0, 0).
/// </summary>
TEST_F(SegmentTest, Length) {
  Point2D<double> *testPoint1 = utils::rand_point_2d(rng);
  Point2D<double> *testPoint2 = utils::rand_point_2d(rng);
  Segment<double> *testSegment = new Segment<double>(testPoint1, testPoint2);
  Vector<double> *v =
      new Vector<double>(testPoint2->x() - testPoint1->x(), testPoint2->y() - testPoint1->y(), 0);
  EXPECT_EQ(v->magnitude(), testSegment->length());
}
#pragma endregion

#pragma region SLOPE
TEST_F(SegmentTest, Slope) {
  Point2D<double> *newPoint = translatePoint(test_point_1);
  Segment<double> *newSegment = new Segment<double>(test_point_1, newPoint);
  double expected = (newPoint->y() - test_point_1->y()) / (newPoint->x() - test_point_1->x());
  EXPECT_DOUBLE_EQ(expected, newSegment->slope());
}

TEST_F(SegmentTest, ZeroSlope) {
  Point2D<double> new_point(test_point_1->x() + rng->next_non_zero_double(-1000, 1000),
                            test_point_1->y());
  Segment<double> new_segment(test_point_1, &new_point);
  EXPECT_DOUBLE_EQ(0, new_segment.slope());
}

TEST_F(SegmentTest, InfSlope) {
  Point2D<double> new_point(test_point_1->x(),
                            test_point_1->y() + rng->next_non_zero_double(-1000, 1000));
  Segment<double> new_segment(test_point_1, &new_point);
  EXPECT_TRUE(std::isinf(new_segment.slope()));
}
#pragma endregion

#pragma region POINT DIRECTION
// TEST_F(SegmentTest, PointOnSegment) {
//   EXPECT_EQ(Segment<double>::Direction::kOnTop,
//             test_segment->direction_to(utils::rand_colinear_point(rng, *this->test_segment)));
// }

// TEST_F(SegmentTest, PointToTheRight) {
//   Point2D<double> aux = utils::rand_colinear_point(rng, *this->test_segment);
//   Point2D<double> new_point =
//       utils::rotate_point(&aux, *this->test_point_1, rng->nextDouble(10, 160));
//   EXPECT_EQ(Segment<double>::Direction::kRight, test_segment->direction_to(new_point));
// }

// TEST_F(SegmentTest, PointToTheLeft) {
//   Point2D<double> aux = utils::rand_colinear_point(rng, *this->test_segment);
//   Point2D<double> new_point =
//       utils::rotate_point(&aux, *this->test_point_1, rng->nextDouble(-160, -10));
//   EXPECT_EQ(Segment<double>::Direction::kLeft, test_segment->direction_to(new_point));
// }
#pragma endregion

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#pragma clang diagnostic pop