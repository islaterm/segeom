#pragma once

#include <iostream>
#include <vector>

#include "main/mathUtils.h"

namespace segeom {
  namespace primitives {
    /**
     * @brief An n-dimensional point.
     *
     * @tparam T
     *    A numerical data type; behaviour for non -arithmetic types is undefined.
     */
    template <class T>
    class PointND;

    /**
     * @brief Two points are equal if they have the same size and elements.
     */
    template <class T>
    bool operator==(const PointND<T> &left, const PointND<T> &right);

    /**
     * @brief Two points are different if they are not equal; amazing :0
     */
    template <class T>
    bool operator!=(const PointND<T> &left, const PointND<T> &right);

    /**
     * @brief Sends this point to standard output stream.
     */
    template <class T>
    std::ostream &operator<<(std::ostream &os, const PointND<T> &point);

    /**
     * @brief Performs the addition of two points.
     */
    template <class T>
    PointND<T> operator+(PointND<T> lAddend, const PointND<T> &rAddend);

    /**
     * @brief Performs the subtraction of two points.
     */
    template <class T>
    PointND<T> operator-(PointND<T> minuend, const PointND<T> &subtrahend);

    /**
     * @brief Performs the multiplication of a point by a scalar.
     */
    template <class T>
    PointND<T> operator*(PointND<T> multiplier, const T &scalar);

    /**
     * @brief Performs the multiplication of a point by a scalar.
     */
    template <class T>
    PointND<T> operator*(const T &scalar, PointND<T> multiplier);

    template <class T>
    class PointND {
    public:
      /**
       * @brief Creates an empty point.
       */
      PointND() : coordinates_(std::vector<T>{}) {}

      /**
       * @brief Creates an n-dimensional point.
       *
       * @param elems
       *    A vector with the coordinates of this point.
       */
      PointND(std::vector<double> &elems) : coordinates_(elems){};

      /**
       * @brief Get the size of the point.
       *        The size of a point is defined as the number of coordinates components (or
       *        dimensions) of it.
       *        For example, a point with three coordinates (x, y, z) has size 3.
       */
      size_t size() const;

      std::vector<T> coordinates() const;

      /**
       * @brief Addition compound assignment operator.
       */
      PointND<T> &operator+=(const PointND<T> &addend);

      /**
       * @brief Subtraction compound assignment operator.
       */
      PointND<T> &operator-=(const PointND<T> &subtrahend);

      /**
       * @brief Multiplication compound assignment operator.
       */
      PointND<T> &operator*=(const T &scalar);

    protected:
      std::vector<T> coordinates_;

    private:
      friend bool operator==<>(const PointND<T> &left, const PointND<T> &right);

      friend inline bool operator!=<>(const PointND<T> &left, const PointND<T> &right);

      friend std::ostream &operator<<<>(std::ostream &os, const PointND<T> &point);

      friend PointND<T> operator+<>(PointND<T> lAddend, const PointND<T> &rAddend);

      friend PointND<T> operator-<>(PointND<T> minuend, const PointND<T> &subtrahend);

      friend PointND<T> operator*<>(PointND<T> multiplier, const T &scalar);

      friend PointND<T> operator*<>(const T &scalar, PointND<T> multiplier);
    };
  } // namespace primitives
} // namespace segeom

using namespace segeom::primitives;

#pragma region OPERATORS
template <class T>
bool segeom::primitives::operator==(const PointND<T> &left, const PointND<T> &right) {
  auto &lCoord = left.coordinates();
  auto &rCoord = right.coordinates();
  if (lCoord.size() != rCoord.size()) {
    return false;
  }
  for (size_t i = 0; i < lCoord.size(); i++) {
    if (abs(lCoord[i] - rCoord[i]) >= segeom::Utils::DELTA) {
      return false;
    }
  }
  return true;
}

template <class T>
bool segeom::primitives::operator!=(const PointND<T> &left, const PointND<T> &right) {
  return !(left == right);
}

template <class T>
std::ostream &segeom::primitives::operator<<(std::ostream &os, const PointND<T> &point) {
  os << "Point {";
  size_t length = point.coordinates().size();
  for (size_t i = 0; i < length; i++) {
    os << "x" << i << ": " << point.coordinates()[i];
    if (i != length - 1) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

template <class T>
PointND<T> segeom::primitives::operator+(PointND<T> lAddend, const PointND<T> &rAddend) {
  lAddend += rAddend;
  return lAddend;
}

template <class T>
PointND<T> segeom::primitives::operator-(PointND<T> minuend, const PointND<T> &subtrahend) {
  minuend -= subtrahend;
  return minuend;
}

template <class T>
PointND<T> segeom::primitives::operator*(PointND<T> multiplier, const T &scalar) {
  multiplier *= scalar;
  return multiplier;
}

template <class T>
PointND<T> segeom::primitives::operator*(const T &scalar, PointND<T> multiplier) {
  multiplier *= scalar;
  return multiplier;
}
#pragma endregion

#pragma region ACCESSORS
template <class T>
inline size_t PointND<T>::size() const {
  return this->coordinates_.size();
}

template <class T>
inline std::vector<T> PointND<T>::coordinates() const {
  return this->coordinates_;
}
#pragma endregion

#pragma region COMPOUND ASSIGNMENTS
template <class T>
PointND<T> &PointND<T>::operator+=(const PointND<T> &addend) {
  size_t length = this->coordinates_.size();
  for (size_t i = 0; i < length; i++) {
    this->coordinates_[i] += addend.coordinates_[i];
  }
  return *this;
}

template <class T>
PointND<T> &PointND<T>::operator-=(const PointND<T> &addend) {
  size_t length = this->coordinates_.size();
  for (size_t i = 0; i < length; i++) {
    this->coordinates_[i] -= addend.coordinates_[i];
  }
  return *this;
}

template <class T>
PointND<T> &PointND<T>::operator*=(const T &scalar) {
  size_t length = this->coordinates_.size();
  for (size_t i = 0; i < length; i++) {
    this->coordinates_[i] *= scalar;
  }
  return *this;
}
#pragma endregion