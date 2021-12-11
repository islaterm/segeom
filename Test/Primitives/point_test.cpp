#include "test/test_utils/point_utils.h"
#include "test/testing.h"
#include "gtest/gtest.h"

namespace utils = segeom::test_utils;
using namespace segeom::primitives;

class PointNDTest : public ::testing::Test {
protected:
  void SetUp() override;
  void TearDown() override;

public:
  long seed = 0;
  utils::Random *rng = nullptr;
  double x = 0;
  double y = 0;
  PointND<double> *testPoint = nullptr;
  std::vector<double> testCoordinates;
  PointND<double> *zeroPoint = nullptr;
};

void PointNDTest::SetUp() {
  utils::initRandom(&seed, &rng);
  rng->randDoubleStdVector(-10000, 10000, &this->testCoordinates);
  this->testPoint = new PointND<double>(this->testCoordinates);
  std::vector<double> zeroVec(this->testPoint->size(), 0);
  zeroPoint = new PointND<double>(zeroVec);
}

void PointNDTest::TearDown() { notify_on_failure(this->seed); }

#pragma region EQUALITY
/// <summary>
/// Two points with the same coordinates are equal.
/// </summary>
TEST_F(PointNDTest, Equality) {
  PointND<double> expected(this->testCoordinates);
  EXPECT_EQ(expected, *testPoint);
}

/// <summary>
/// Two points with different dimensions are different
/// </summary>
TEST_F(PointNDTest, DifferentDimensions) {
  std::vector<double> unexpected;
  do {
    this->rng->randDoubleStdVector(-10000, 10000, &unexpected);
  } while (unexpected.size() == this->testCoordinates.size());
  EXPECT_NE(PointND<double>{unexpected}, *testPoint);

  int length = rng->next_int(0, this->testCoordinates.size());
  std::vector<double> sublist = *utils::sublist(this->testCoordinates, 0, length);
  EXPECT_NE(PointND<double>{sublist}, *this->testPoint);
}

/// <summary>
/// Points with different elements but same length are different.
/// </summary>
TEST_F(PointNDTest, Distinct) {
  std::vector<double> displacedVector = utils::translateStdVec(this->testCoordinates, *this->rng);
  PointND<double> unexpected(displacedVector);
  EXPECT_NE(unexpected, *this->testPoint);
}
#pragma endregion

#pragma region ADDITION
TEST_F(PointNDTest, IdentityAdditionTest) { EXPECT_EQ(*zeroPoint + *testPoint, *testPoint); }

TEST_F(PointNDTest, CommutativeAddition) {
  std::vector<double> vec;
  rng->randDoubleStdVector(-10000, 10000, &vec);
  PointND<double> p(vec);
  EXPECT_EQ(*this->testPoint + p, p + *this->testPoint);
}

// This test fails while comparing with a precision of 1e-10, passes with 1e-9
TEST_F(PointNDTest, AssociativeAddition) {
  std::vector<double> v1, v2;
  rng->randDoubleStdVector(-10000, 10000, &v1);
  rng->randDoubleStdVector(-10000, 10000, &v2);
  PointND<double> p1(v1);
  PointND<double> p2(v2);
  EXPECT_EQ((*this->testPoint + p1) + p2, *this->testPoint + (p1 + p2));
}
#pragma endregion

#pragma region SUBTRACTION
TEST_F(PointNDTest, IdentitySubtraction) { EXPECT_EQ(*testPoint, *testPoint - *zeroPoint); }

TEST_F(PointNDTest, AdditiveInverse) {
  std::vector<double> vec;
  rng->randDoubleStdVector(-10000, 10000, &vec);
  PointND<double> p(vec);
  EXPECT_EQ(*zeroPoint, *testPoint - *testPoint);
}
#pragma endregion

#pragma region UTILITY
TEST_F(PointNDTest, Size) { EXPECT_EQ(this->testCoordinates.size(), this->testPoint->size()); }
#pragma endregion

#pragma region MULTIPLICATION
TEST_F(PointNDTest, IdentityMultiplication) { EXPECT_EQ(1.0 * *testPoint, *testPoint); }

TEST_F(PointNDTest, InverseMultiplication) { EXPECT_EQ(-1.0 * *testPoint, *zeroPoint - *testPoint); }

TEST_F(PointNDTest, ZeroMultiplication) { EXPECT_EQ(*testPoint * 0.0, *zeroPoint); }

TEST_F(PointNDTest, CommutativeMultiplication) {
  double c = rng->nextDouble(-10000, 10000);
  EXPECT_EQ(*this->testPoint * c, c * *this->testPoint);
}

TEST_F(PointNDTest, AssociativeMultiplication) {
  double c = rng->nextDouble(-10000, 10000);
  double d = rng->nextDouble(-10000, 10000);
  EXPECT_EQ((*this->testPoint * c) * d, *this->testPoint * (c * d));
}

TEST_F(PointNDTest, DistributiveMultiplication) {
  double c = rng->nextDouble(-10000, 10000);
  double d = rng->nextDouble(-10000, 10000);
  EXPECT_EQ(*this->testPoint * (c + d), (*this->testPoint * c) + (*this->testPoint * d));
}
#pragma endregion

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}