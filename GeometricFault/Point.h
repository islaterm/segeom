#pragma once
#include <math.h>

#include "utils.h"

namespace utils = Segeom::Utils;

namespace Segeom {
namespace Primitives {
template <class T>
class Point {
#pragma region OPERATIONS
  /// <summary>
  ///   Performs the addition of two points.
  /// </summary>
  friend Point<T> operator+(Point<T> lAddend, const Point<T>& rAddend) {
    lAddend += rAddend;
    return lAddend;
  }

  /// <summary>
  ///   Performs the subtraction of two points.
  /// </summary>
  friend Point<T> operator-(Point<T> minuend, const Point<T>& subtrahend) {
    minuend -= subtrahend;
    return minuend;
  }

  /// <summary>
  ///   Performs the multiplication of two points.
  /// </summary>
  friend Point<T> operator*(Point<T> multiplier, const T& multiplicand) {
    multiplier *= multiplicand;
    return multiplier;
  }
#pragma endregion

 public:
  /// <summary>
  ///   Creates a new 2D point from two given coordinates.
  /// </summary>
  Point(T x, T y) : _x(x), _y(y), _z(0) {}

  /// <summary>
  ///   Creates a new 3D point from three given coordinates.
  /// </summary>
  Point(T x, T y, T z) : _x(x), _y(y), _z(z) {}

#pragma region COMPOUND ASSIGNMENTS
  /// <summary>
  ///   Addition compound assignment for a point.
  /// </summary>
  Point<T>& operator+=(const Point<T>& addend);

  /// <summary>
  ///   Subtraction compound assignment for a point.
  /// </summary>
  Point<T>& operator-=(const Point<T>& addend);

  /// <summary>
  ///   Multiplication compound assignment for a point.
  /// </summary>
  Point<T>& operator*=(const T& factor);
#pragma endregion

#pragma region ACCESSORS
  /// <summary>
  ///   Returns the x coordinate of this point.
  /// </summary>
  T getX() const;

  /// <summary>
  ///   Returns the y coordinate of this point.
  /// </summary>
  T getY() const;

  /// <summary>
  ///   Returns the z coordinate of this point.
  /// </summary>
  T getZ() const;
#pragma endregion

 private:
  T _x;
  T _y;
  T _z;
};

#pragma region ACCESSORS
template <class T>
inline T Point<T>::getX() const {
  return this->_x;
}

template <class T>
inline T Point<T>::getY() const {
  return this->_y;
}

template <class T>
inline T Point<T>::getZ() const {
  return this->_z;
}
#pragma endregion

template <class T>
inline bool operator==(const Point<T>& left, const Point<T>& right) {
  return abs(left.getX() - right.getX()) < utils::DELTA &&
         abs(left.getY() - right.getY()) < utils::DELTA &&
         abs(left.getZ() - right.getZ()) < utils::DELTA;
}

template <class T>
inline bool operator!=(const Point<T>& left, const Point<T>& right) {
  return !(left == right);
}

#pragma region COMPOUND ASSIGNMENTS
template <class T>
Point<T>& Point<T>::operator+=(const Point<T>& addend) {
  this->_x += addend._x;
  this->_y += addend._y;
  this->_z += addend._z;
  return *this;
}

template <class T>
inline Point<T>& Point<T>::operator-=(const Point<T>& subtrahend) {
  this->_x -= subtrahend._x;
  this->_y -= subtrahend._y;
  this->_z -= subtrahend._z;
  return *this;
}

template <class T>
inline Point<T>& Point<T>::operator*=(const T& factor) {
  this->_x *= factor;
  this->_y *= factor;
  this->_z *= factor;
  return *this;
}
#pragma endregion
}  // namespace Primitives
}  // namespace Segeom