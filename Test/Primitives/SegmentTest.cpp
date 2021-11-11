#include "gtest/gtest.h"
#include "../TestUtils/CommonUtils.h"

namespace Utils = Segeom::TestUtils;
class VectorTest : public ::testing::Test {
 protected:
  void SetUp() override;
  void TearDown() override;

 public:
  long seed = 0;
  Utils::Random* rng = nullptr;
};

void VectorTest::SetUp() {
  Utils::initRandom(&seed, &rng);
  this->x = rng->nextDouble(-5000000, 5000000);
  this->y = rng->nextDouble(-5000000, 5000000);
  this->z = rng->nextDouble(-5000000, 5000000);
  this->testVector = new Primitives::Vector<double>(x, y, z);
  this->zeroVector = new Primitives::Vector<double>(0, 0, 0);
}