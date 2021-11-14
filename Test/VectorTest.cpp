#include "Testing.h"
#include "Primitives/VectorUtils.h"

namespace Utils = Segeom::TestUtils;
namespace Primitives = Segeom::Primitives;

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
  Primitives::Vector<double>* testVector = nullptr;
  Primitives::Vector<double>* zeroVector = nullptr;
};

void VectorTest::SetUp() {
  Utils::initRandom(&seed, &rng);
  Utils::randomCoordinates(&x, &y, &z, rng);
  this->testVector = new Primitives::Vector<double>(x, y, z);
  this->zeroVector = new Primitives::Vector<double>(0, 0, 0);
}

void VectorTest::TearDown() { notifyOnFailure(seed); }

TEST_F(VectorTest, Equals) {
  Primitives::Vector<double> expectedVector(x, y, z);
  EXPECT_EQ(expectedVector, *testVector);
}

TEST_F(VectorTest, Distinct) {
  Primitives::Vector<double> unexpected(
      x + rng->nextNonZeroDouble(-1000, 1000),
      y + rng->nextNonZeroDouble(-1000, 1000),
      z + rng->nextNonZeroDouble(-1000, 1000));
  EXPECT_NE(unexpected, *testVector);
}

TEST_F(VectorTest, NormalizationTest) {
  double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  Primitives::Vector<double> normVector(x / length, y / length, z / length);
  Primitives::Vector<double>* actualVector = testVector->normalized();
  EXPECT_EQ(normVector, *actualVector);
}

TEST_F(VectorTest, MagnitudeTest) {
  double expectedMagnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  EXPECT_DOUBLE_EQ(expectedMagnitude, testVector->magnitude(), utils::DELTA);
}

TEST_F(VectorTest, DotProductTest) {
  Primitives::Vector<double> v = Utils::randVector();
  double expected = x * v.getX() + y * v.getY() + z * v.getZ();
  EXPECT_DOUBLE_EQ(expected, testVector->dot(v), utils::DELTA);
}

TEST_F(VectorTest, CrossProductTest) {
  Primitives::Vector<double> v = Utils::randVector();
  Primitives::Vector<double> expected(
      testVector->getY() * v.getZ() - testVector->getZ() * v.getY(),
      testVector->getZ() * v.getX() - testVector->getX() * v.getZ(),
      testVector->getX() * v.getY() - testVector->getY() * v.getX());
  Primitives::Vector<double>* actual = testVector->cross(v);
  EXPECT_EQ(expected, *actual);
}

#pragma region ADDITION
TEST_F(VectorTest, IdentityAdditionTest) {
  EXPECT_EQ(*testVector, *testVector + *zeroVector);
}

TEST_F(VectorTest, CommutativeAddition) {
  Primitives::Vector<double> v = Utils::randVector();
  EXPECT_EQ(*testVector + v, v + *testVector);
}

// This test fails while comparing with a precision of 1e-10, passes with 1e-9
TEST_F(VectorTest, AssociativeAddition) {
  Primitives::Vector<double> v1 = Utils::randVector(rng);
  Primitives::Vector<double> v2 = Utils::randVector(rng);
  EXPECT_EQ((*testVector + v1) + v2, *testVector + (v1 + v2));
}
#pragma endregion

#pragma region SUBTRACTION
TEST_F(VectorTest, IdentitySubtraction) {
  EXPECT_EQ(*testVector, *testVector - *zeroVector);
}

TEST_F(VectorTest, AdditiveInverse) {
  Primitives::Vector<double> v = Utils::randVector();
  EXPECT_EQ(*zeroVector, *testVector - *testVector);
}
#pragma endregion