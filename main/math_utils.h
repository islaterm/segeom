#pragma once

#include <limits>
#include <math.h>
#include <algorithm>

namespace segeom {
  namespace utils {
    const double DELTA = 1e-6;

    /// <summary>
    /// Squares a number.
    /// </summary>
    /// <typeparam name="T">A numerical type.</typeparam>
    template <class T>
    double square(double n) {
      return n * n;
    }

    /// <summary>
    /// Calculates the norm of a 3D element.
    /// </summary>
    /// <typeparam name="T">A numerical type.</typeparam>
    template <class T>
    double norm3D(T x, T y, T z) {
      return sqrt(square<T>(x) + square<T>(y) + square<T>(z));
    }

    /**
     * @brief Determines if 2 numbers are equal.
     */
    template <class T>
    bool equals(T x, T y) {
      double epsilon = std::numeric_limits<double>::epsilon();
      double local_delta =
          abs(x) > 1 && abs(y) > 1 ? 100 * std::min(abs(epsilon * x), abs(epsilon * y)) : epsilon;
      return abs(x - y) < local_delta;
    }
  } // namespace utils
} // namespace segeom