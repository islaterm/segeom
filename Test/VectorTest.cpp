#include "VectorTest.h"

#include <math.h>

namespace Utils = Segeom::TestUtils;
namespace Primitives = Segeom::Primitives;

class VectorTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  int seed = 0;
  Utils::Random* rng;
  int x = 0;
  int y = 0;
  int z = 0;
  Primitives::Vector<double>* testVector = nullptr;
  Primitives::Vector<double>* zeroVector = nullptr;

 private:
  void initRandom();
};

void VectorTest::SetUp() {
  initRandom();
  Utils::Random* rng = new Utils::Random(seed);
  this->x = rng->nextDouble(-5000000, 5000000);
  this->y = rng->nextDouble(-5000000, 5000000);
  this->z = rng->nextDouble(-5000000, 5000000);
  this->testVector = new Primitives::Vector<double>(x, y, z);
  this->zeroVector = new Primitives::Vector<double>(0, 0, 0);
}

void VectorTest::TearDown() {
  //delete testVector;
  if (::testing::Test::HasFailure()) {
    std::cout << "Test failed with seed = " << seed << std::endl;
  }
}

void VectorTest::initRandom() {
  std::random_device r;
  std::default_random_engine engine(r());
  std::uniform_int_distribution<int> intDist(-500000, 500000);
  seed = intDist(engine);
}

TEST_F(VectorTest, ConstructorTest) {
  Primitives::Vector<double> expectedVector(x, y, z);
  EXPECT_EQ(expectedVector, *testVector);
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

TEST_F(VectorTest, IdentityAdditionTest) {
  EXPECT_EQ(*testVector, *testVector + *zeroVector);
}

TEST_F(VectorTest, CommutativeAddition) {
  Primitives::Vector<double> v = Utils::randVector();
  EXPECT_EQ(*testVector + v, v + *testVector);
}

TEST_F(VectorTest, AssociativeAddition) {
  Primitives::Vector<double> v1 = Utils::randVector();
  Primitives::Vector<double> v2 = Utils::randVector();
  EXPECT_EQ((*testVector + v1) + v2, *testVector + (v1 + v2));
}

TEST_F(VectorTest, BasicAddition) {
  Primitives::Vector<double> v1(1, 2, 3);
  Primitives::Vector<double> v2(11, 420, 69);
  Primitives::Vector<double> actual = v1 + v2;
  EXPECT_EQ(12, actual.getX());
  EXPECT_EQ(422, actual.getY());
  EXPECT_EQ(72, actual.getZ());
}