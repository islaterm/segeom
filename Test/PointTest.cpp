#include "pch.h"
#include "../GeometricFault/Point.h"

using namespace Segeom::Primitives;

class PointTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  int seed = 0;
  double x = 0;
  double y = 0;
  Point<double>* testPoint = nullptr;
};

void PointTest::SetUp() {
  srand((unsigned int)time(NULL));
  this->seed = rand() % 1000000 - 500000 + 1;
  srand(seed);
  this->x = randDouble(-5000000, 5000000);
  this->y = randDouble(-5000000, 5000000);
  this->testPoint = new Point<double>(x, y);
}

void PointTest::TearDown() {
  delete testPoint;
  if (::testing::Test::HasFailure()) {
    std::cout << "Test failed with seed = " << seed << std::endl;
  }
}

TEST_F(PointTest, ConstructorTest) {
  Point<double> expectedPoint(x, y);
  EXPECT_EQ(expectedPoint, *testPoint);
}

TEST_F(PointTest, AdditionTest) {
  Point<double> other(randDouble(-5000000, 5000000), randDouble(-5000000, 5000000));
  Point<double> expectedPoint(testPoint->getX() + other.getX(),
                           testPoint->getY() + other.getY());
  Point<double> actualPoint = *testPoint + other;
  EXPECT_EQ(expectedPoint, actualPoint);
}

TEST_F(PointTest, SubtractionTest) {
  Point<double> other(randDouble(-5000000, 5000000), randDouble(-5000000, 5000000));
  Point<double> expectedPoint(testPoint->getX() - other.getX(),
                           testPoint->getY() - other.getY());
  Point<double> actualPoint = *testPoint - other;
  EXPECT_EQ(expectedPoint, actualPoint);
}

TEST_F(PointTest, MultiplicationTest) {
  Point<double> other(randDouble(-5000000, 5000000), randDouble(-5000000, 5000000));
  int scalar = randDouble(-1000, 1000);
  Point<double> expectedPoint(testPoint->getX() * scalar,
                           testPoint->getY() * scalar);
  Point<double> actualPoint = *testPoint * scalar;
  EXPECT_EQ(expectedPoint, actualPoint);
}

TEST_F(PointTest, AssignmentTest) {
  Point<double> other(randDouble(-5000000, 5000000), randDouble(-5000000, 5000000));
  *testPoint = other;

  EXPECT_EQ(*testPoint, other);
}