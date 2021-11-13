#pragma once

#include "../../GeometricFault/Primitives/Point.h"
#include "CommonUtils.h"

namespace Segeom {
namespace TestUtils {
/// <summary>
/// Generates a new random point using a given random number generato'r.
/// </summary>
Segeom::Primitives::Point<double> randPoint(Random *rng);
}  // namespace TestUtils
}  // namespace Segeom