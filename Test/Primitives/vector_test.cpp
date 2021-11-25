#include "test/testing.h"
#include "test/test_utils/vector_utils.h"

namespace utils = segeom::test_utils;
namespace primitives = segeom::primitives;

class VectorTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  utils::Random* rng = nullptr;
  double x = 0;
  double y = 0;
  double z = 0;
  primitives::Vector<double>* test_vector = nullptr;
  primitives::Vector<double>* zero_vector = nullptr;
};

void VectorTest::SetUp() {
  utils::initRandom(&seed, &rng);
  utils::randomCoordinates(&x, &y, &z, rng);
  this->test_vector = new primitives::Vector<double>(x, y, z);
  this->zero_vector = new primitives::Vector<double>(0, 0, 0);
}

void VectorTest::TearDown() { notify_on_failure(seed); }

TEST_F(VectorTest, Equals) {
  primitives::Vector<double> expected_vector(x, y, z);
  EXPECT_EQ(expected_vector, *test_vector);
}

TEST_F(VectorTest, Distinct) {
  primitives::Vector<double> unexpected(
      x + rng->next_non_zero_double(-1000, 1000),
      y + rng->next_non_zero_double(-1000, 1000),
      z + rng->next_non_zero_double(-1000, 1000));
  EXPECT_NE(unexpected, *test_vector);
}

TEST_F(VectorTest, NormalizationTest) {
  double length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  primitives::Vector<double> norm_vector(x / length, y / length, z / length);
  primitives::Vector<double>* actualVector = test_vector->normalized();
  EXPECT_EQ(norm_vector, *actualVector);
}

TEST_F(VectorTest, MagnitudeTest) {
  double expected_magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  EXPECT_DOUBLE_EQ(expected_magnitude, test_vector->magnitude());
}

TEST_F(VectorTest, DotProductTest) {
  primitives::Vector<double> v = utils::rand_vector(this->rng);
  double expected = x * v.getX() + y * v.getY() + z * v.getZ();
  EXPECT_DOUBLE_EQ(expected, test_vector->dot(v));
}

TEST_F(VectorTest, CrossProductTest) {
  primitives::Vector<double> v = utils::rand_vector(this->rng);
  primitives::Vector<double> expected(
      test_vector->getY() * v.getZ() - test_vector->getZ() * v.getY(),
      test_vector->getZ() * v.getX() - test_vector->getX() * v.getZ(),
      test_vector->getX() * v.getY() - test_vector->getY() * v.getX());
  primitives::Vector<double>* actual = test_vector->cross(v);
  EXPECT_EQ(expected, *actual);
}

#pragma region ADDITION
TEST_F(VectorTest, IdentityAdditionTest) {
  EXPECT_EQ(*test_vector, *test_vector + *zero_vector);
}

TEST_F(VectorTest, CommutativeAddition) {
  primitives::Vector<double> v = utils::rand_vector(this->rng);
  EXPECT_EQ(*test_vector + v, v + *test_vector);
}

// This test fails while comparing with a precision of 1e-10, passes with 1e-9
TEST_F(VectorTest, AssociativeAddition) {
  primitives::Vector<double> v1 = utils::rand_vector(this->rng);
  primitives::Vector<double> v2 = utils::rand_vector(this->rng);
  EXPECT_EQ((*test_vector + v1) + v2, *test_vector + (v1 + v2));
}
#pragma endregion

#pragma region SUBTRACTION
TEST_F(VectorTest, IdentitySubtraction) {
  EXPECT_EQ(*test_vector, *test_vector - *zero_vector);
}

TEST_F(VectorTest, AdditiveInverse) {
  primitives::Vector<double> v = utils::rand_vector(this->rng);
  EXPECT_EQ(*zero_vector, *test_vector - *test_vector);
}
#pragma endregion