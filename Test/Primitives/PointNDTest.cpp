#include "main/Primitives/PointND.h"
#include "test/TestUtils/PointUtils.h"
#include "test/Testing.h"
#include "gtest/gtest.h"

namespace Utils = Segeom::TestUtils;
using namespace Segeom::Primitives;

class PointNDTest : public ::testing::Test {
protected:
  void SetUp() override;
  void TearDown() override;

public:
  long seed = 0;
  Utils::Random *rng = nullptr;
  double x = 0;
  double y = 0;
  PointND<double> *testPoint = nullptr;
  std::vector<double> testCoordinates;
  PointND<double> *zeroPoint = nullptr;
};

void PointNDTest::SetUp() {
  Utils::initRandom(&seed, &rng);
  rng->randDoubleStdVector(-1000000, 1000000, &this->testCoordinates);
  this->testPoint = new PointND<double>(this->testCoordinates);
  std::vector<double> zeroVec(this->testPoint->getSize(), 0);
  zeroPoint = new PointND<double>(zeroVec);
}

void PointNDTest::TearDown() { notifyOnFailure(this->seed); }

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
    this->rng->randDoubleStdVector(-1000000, 1000000, &unexpected);
  } while (unexpected.size() == this->testCoordinates.size());
  EXPECT_NE(PointND<double>{unexpected}, *testPoint);

  int length = rng->nextInt(0, this->testCoordinates.size());
  std::vector<double> sublist = *Utils::sublist(this->testCoordinates, 0, length);
  EXPECT_NE(PointND<double>{sublist}, *this->testPoint);
}

/// <summary>
/// Points with different elements but same length are different.
/// </summary>
TEST_F(PointNDTest, Distinct) {
  std::vector<double> displacedVector = Utils::translateStdVec(this->testCoordinates, *this->rng);
  PointND<double> unexpected(displacedVector);
  EXPECT_NE(unexpected, *this->testPoint);
}
#pragma endregion

#pragma region ADDITION
TEST_F(PointNDTest, IdentityAdditionTest) { EXPECT_EQ(*zeroPoint + *testPoint, *testPoint); }

TEST_F(PointNDTest, CommutativeAddition) {
  std::vector<double> vec;
  rng->randDoubleStdVector(-1000000, 1000000, &vec);
  PointND<double> p(vec);
  EXPECT_EQ(*this->testPoint + p, p + *this->testPoint);
}

// This test fails while comparing with a precision of 1e-10, passes with 1e-9
TEST_F(PointNDTest, AssociativeAddition) {
  std::vector<double> v1, v2;
  rng->randDoubleStdVector(-1000000, 1000000, &v1);
  rng->randDoubleStdVector(-1000000, 1000000, &v2);
  PointND<double> p1(v1);
  PointND<double> p2(v2);
  EXPECT_EQ((*this->testPoint + p1) + p2, *this->testPoint + (p1 + p2));
}
#pragma endregion

#pragma region SUBTRACTION
TEST_F(PointNDTest, IdentitySubtraction) { EXPECT_EQ(*testPoint, *testPoint - *zeroPoint); }

TEST_F(PointNDTest, AdditiveInverse) {
  std::vector<double> vec;
  rng->randDoubleStdVector(-1000000, 1000000, &vec);
  PointND<double> p(vec);
  EXPECT_EQ(*zeroPoint, *testPoint - *testPoint);
}
#pragma endregion

#pragma region UTILITY
TEST_F(PointNDTest, Size) { EXPECT_EQ(this->testCoordinates.size(), this->testPoint->getSize()); }
#pragma endregion

#pragma region MULTIPLICATION
TEST_F(PointNDTest, IdentityMultiplication) { EXPECT_EQ(1 * *testPoint, *testPoint); }

TEST_F(PointNDTest, InverseMultiplication) { EXPECT_EQ(-1 * *testPoint, *zeroPoint - *testPoint); }

TEST_F(PointNDTest, ZeroMultiplication) { EXPECT_EQ(*testPoint * 0, *zeroPoint); }

TEST_F(PointNDTest, CommutativeMultiplication) {
  double c = rng->nextDouble(-1000000, 1000000);
  EXPECT_EQ(*this->testPoint * c, c * *this->testPoint);
}

TEST_F(PointNDTest, AssociativeMultiplication) {
  double c = rng->nextDouble(-1000000, 1000000);
  double d = rng->nextDouble(-1000000, 1000000);
  EXPECT_EQ((*this->testPoint * c) * d, *this->testPoint * (c * d));
}

TEST_F(PointNDTest, DistributiveMultiplication) {
  double c = rng->nextDouble(-1000000, 1000000);
  double d = rng->nextDouble(-1000000, 1000000);
  EXPECT_EQ(*this->testPoint * (c + d), (*this->testPoint * c) + (*this->testPoint * d));
}
#pragma endregion