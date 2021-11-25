#pragma once

#include "../../GeometricFault/Primitives/Vector.h"
#include "../TestUtils/CommonUtils.h"

namespace segeom {
namespace TestUtils {
segeom::primitives::Vector<double> randVector();
/**
 * @brief Generates a new random vector.
 * @param rng 
 *    A random number generator.
 * @return The created vector.
*/
segeom::primitives::Vector<double> randVector(Random *rng);
}  // namespace TestUtils
}  // namespace Segeom