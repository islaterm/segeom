#pragma once

#include "main/Primitives/point.h"
#include "CommonUtils.h"

namespace segeom {
namespace TestUtils {
/// <summary>
/// Generates a new random point using a given random number generator.
/// </summary>
segeom::primitives::Point3D<double> randPoint(Random *rng);
}  // namespace TestUtils
}  // namespace Segeom