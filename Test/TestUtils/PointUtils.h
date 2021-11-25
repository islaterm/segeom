#pragma once

#include "main/Primitives/PointND.h"
#include "main/Primitives/Point.h"
#include "CommonUtils.h"

namespace segeom {
namespace TestUtils {
/// <summary>
/// Generates a new random point using a given random number generator.
/// </summary>
segeom::primitives::Point<double> randPoint(Random *rng);
}  // namespace TestUtils
}  // namespace Segeom