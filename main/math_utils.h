#pragma once

#include <math.h>

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
  } // namespace Utils
} // namespace segeom