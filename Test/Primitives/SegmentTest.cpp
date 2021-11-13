#include "../Testing.h"
#include "../TestUtils/SegmentUtils.h"

namespace Utils = Segeom::TestUtils;

class SegmentTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  Utils::Random* rng = nullptr;
  Segeom::Primitives::Point<double>* testPoint1 = nullptr;
  Segeom::Primitives::Point<double>* testPoint2 = nullptr;
  Segeom::Primitives::Segment<double>* testSegment = nullptr;
};

void SegmentTest::SetUp() {
  Utils::initRandom(&seed, &rng);/*
  this->x = rng->nextDouble(-5000000, 5000000);
  this->y = rng->nextDouble(-5000000, 5000000);
  this->z = rng->nextDouble(-5000000, 5000000);
  this->testVector = new Primitives::Vector<double>(x, y, z);
  this->zeroVector = new Primitives::Vector<double>(0, 0, 0);*/
}

void SegmentTest::TearDown() { notifyOnFailure(seed); }
