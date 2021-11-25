#pragma once

#include "main/Primitives/PointND.h"
#include "main/Primitives/Point.h"
#include "CommonUtils.h"

namespace Segeom {
namespace TestUtils {
/// <summary>
/// Generates a new random point using a given random number generator.
/// </summary>
Segeom::Primitives::Point<double> randPoint(Random *rng);
}  // namespace TestUtils
}  // namespace Segeom