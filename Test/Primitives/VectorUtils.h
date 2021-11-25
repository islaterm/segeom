#pragma once

#include "../../GeometricFault/Primitives/Vector.h"
#include "../TestUtils/CommonUtils.h"

namespace Segeom {
namespace TestUtils {
Segeom::Primitives::Vector<double> randVector();
/**
 * @brief Generates a new random vector.
 * @param rng 
 *    A random number generator.
 * @return The created vector.
*/
Segeom::Primitives::Vector<double> randVector(Random *rng);
}  // namespace TestUtils
}  // namespace Segeom