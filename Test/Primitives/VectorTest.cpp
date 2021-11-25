#include "Testing.h"
#include "Primitives/VectorUtils.h"

namespace Utils = segeom::TestUtils;
namespace primitives = segeom::primitives;

class VectorTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  Utils::Random* rng = nullptr;
  double x = 0;
  double y = 0;
  double z = 0;
  primitives::Vector<double>* testVector = nullptr;
  primitives::Vector<double>* zeroVector = nullptr;
};

void VectorTest::SetUp() {
  Utils::initRandom(&seed, &rng);
  Utils::randomCoordinates(&x, &y, &z, rng);
  this->testVector = new primitives::Vector<double>(x, y, z);
  this->zeroVector = new primitives::Vector<double>(0, 0, 0);
}

void VectorTest::TearDown() { notifyOnFailure(seed); }

TEST_F(VectorTest, Equals) {
  primitives::Vector<double> expectedVector(x, y, z);
  EXPECT_EQ(expectedVector, *testVector);
}

TEST_F(VectorTest, Distinct) {
  primitives::Vector<double> unexpected(
      x + rng->nextNonZeroDouble(-1000, 1000),
      y + rng->nextNonZeroDouble(-1000, 1000),
      z + rng->nextNonZeroDouble(-1000, 1000));
  EXPECT_NE(unexpected, *testVector);
}

TEST_F(VectorTest, NormalizationTest) {
  double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  primitives::Vector<double> normVector(x / length, y / length, z / length);
  primitives::Vector<double>* actualVector = testVector->normalized();
  EXPECT_EQ(normVector, *actualVector);
}

TEST_F(VectorTest, MagnitudeTest) {
  double expectedMagnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  EXPECT_DOUBLE_EQ(expectedMagnitude, testVector->magnitude());
}

TEST_F(VectorTest, DotProductTest) {
  primitives::Vector<double> v = Utils::randVector();
  double expected = x * v.getX() + y * v.getY() + z * v.getZ();
  EXPECT_DOUBLE_EQ(expected, testVector->dot(v));
}

TEST_F(VectorTest, CrossProductTest) {
  primitives::Vector<double> v = Utils::randVector();
  primitives::Vector<double> expected(
      testVector->getY() * v.getZ() - testVector->getZ() * v.getY(),
      testVector->getZ() * v.getX() - testVector->getX() * v.getZ(),
      testVector->getX() * v.getY() - testVector->getY() * v.getX());
  primitives::Vector<double>* actual = testVector->cross(v);
  EXPECT_EQ(expected, *actual);
}

#pragma region ADDITION
TEST_F(VectorTest, IdentityAdditionTest) {
  EXPECT_EQ(*testVector, *testVector + *zeroVector);
}

TEST_F(VectorTest, CommutativeAddition) {
  primitives::Vector<double> v = Utils::randVector();
  EXPECT_EQ(*testVector + v, v + *testVector);
}

// This test fails while comparing with a precision of 1e-10, passes with 1e-9
TEST_F(VectorTest, AssociativeAddition) {
  primitives::Vector<double> v1 = Utils::randVector(rng);
  primitives::Vector<double> v2 = Utils::randVector(rng);
  EXPECT_EQ((*testVector + v1) + v2, *testVector + (v1 + v2));
}
#pragma endregion

#pragma region SUBTRACTION
TEST_F(VectorTest, IdentitySubtraction) {
  EXPECT_EQ(*testVector, *testVector - *zeroVector);
}

TEST_F(VectorTest, AdditiveInverse) {
  primitives::Vector<double> v = Utils::randVector();
  EXPECT_EQ(*zeroVector, *testVector - *testVector);
}
#pragma endregion