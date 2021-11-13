#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../GeometricFault/Primitives/Point.h"
#include "TestUtils/CommonUtils.h"
#include "gtest/gtest.h"

namespace Utils = Segeom::TestUtils;
using namespace Segeom::Primitives;

class PointTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  double x = 0;
  double y = 0;
  Point<double>* testPoint = nullptr;
};

void PointTest::SetUp() {
  srand((unsigned int)time(NULL));
  this->seed = rand() % 1000000 - 500000 + 1;
  srand(seed);
  this->x = Utils::randDouble(-5000000, 5000000);
  this->y = Utils::randDouble(-5000000, 5000000);
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
  Point<double> other(Utils::randDouble(-5000000, 5000000),
                      Utils::randDouble(-5000000, 5000000));
  Point<double> expectedPoint(testPoint->getX() + other.getX(),
                              testPoint->getY() + other.getY());
  Point<double> actualPoint = *testPoint + other;
  EXPECT_EQ(expectedPoint, actualPoint);
}

TEST_F(PointTest, SubtractionTest) {
  Point<double> other(Utils::randDouble(-5000000, 5000000),
                      Utils::randDouble(-5000000, 5000000));
  Point<double> expectedPoint(testPoint->getX() - other.getX(),
                              testPoint->getY() - other.getY());
  Point<double> actualPoint = *testPoint - other;
  EXPECT_EQ(expectedPoint, actualPoint);
}

TEST_F(PointTest, MultiplicationTest) {
  Point<double> other(Utils::randDouble(-5000000, 5000000),
                      Utils::randDouble(-5000000, 5000000));
  int scalar = Utils::randDouble(-1000, 1000);
  Point<double> expectedPoint(testPoint->getX() * scalar,
                              testPoint->getY() * scalar);
  Point<double> actualPoint = *testPoint * scalar;
  EXPECT_EQ(expectedPoint, actualPoint);
}

TEST_F(PointTest, AssignmentTest) {
  Point<double> other(Utils::randDouble(-5000000, 5000000),
                      Utils::randDouble(-5000000, 5000000));
  *testPoint = other;

  EXPECT_EQ(*testPoint, other);
}