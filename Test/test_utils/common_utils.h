#pragma once

#include <stdlib.h>

#include <ctime>
#include <random>
#include <vector>

namespace segeom {
  namespace test_utils {
    /// <summary>
    /// Acceptable difference for floating point comparison.
    /// </summary>
    const double DELTA = 1e-32;
    class Random {
    public:
      Random();
      Random(long seed);
      ~Random();

      /**
       * @brief Returns a random double precision number between `lo` and `hi`.
       */
      double next_double(double lo, double hi);

      /**
       * @brief Returns a double precision number between `lo` and `hi` with gaussian distribution
       */
      double next_double_gauss(double avg, double std_dev);

      /// <summary>
      /// Returns a random integer between `lo` and `hi` (inclusive).
      /// </summary>
      int next_int(int lo, int hi);

      /**
       * @brief Returns a random non-zero double precision number between lo and hi.
       */
      double next_non_zero_double(double lo, double hi);

      /// <summary>
      /// Generates a std::vector with random double values between lo and hi.
      /// </summary>
      void randDoubleStdVector(double lo, double hi, std::vector<double> *out);

      long getSeed();

    private:
      long seed;
      std::mt19937_64 *rng;
    };
    double randDouble(double lo, double hi);

    /// <summary>
    /// Initializes a random number generator and it's seed.
    /// </summary>
    void initRandom(long *seed, Random **rng);

    /// <summary>
    /// Assign a random value to a triplet of coordinates (x, y, z) with a given
    /// random number generator.
    /// </summary>
    void randomCoordinates(double *x, double *y, double *z, Random *rng);

    /// <summary>
    /// Translates a vector a random (non-zero) displacement.
    /// </summary>
    std::vector<double> translateStdVec(std::vector<double> &vector, Random &rng);

    /// <summary>
    /// Returns a subset of the elements of a std::vector from start to end.
    /// </summary>
    template <class T>
    std::vector<T> *sublist(std::vector<T> const &vector, int start, int end) {
      auto first = vector.begin() + start;
      auto last = vector.begin() + end + 1;
      return new std::vector<T>(start, end);
    }
  } // namespace test_utils
} // namespace segeom