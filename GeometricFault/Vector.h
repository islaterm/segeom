#pragma once
#include <math.h>
#include <iostream>

#include "Point.h"
#include "utils.h"

using namespace Segeom::Utils;

namespace Segeom {
namespace Primitives {
/// <summary>
///   An euclidean vector, that is, an object that has a magnitude and a
///   direction.
/// </summary>
template <class T>
class Vector {
#pragma region OPERATIONS
  /// <summary>
  ///   Performs the addition of two vectors.
  /// </summary>
  friend Vector<T> operator+(Vector<T> lAddend, const Vector<T>& rAddend) {
    lAddend += rAddend;
    return lAddend;
  }
  /// <summary>
  ///   Performs the subtraction of two vectors.
  /// </summary>
  friend Vector<T> operator-(Vector<T> minuend, const Vector<T>& subtrahend) {
    minuend -= subtrahend;
    return minuend;
  }
#pragma endregion

 public:
  /// <summary>
  ///   Creates a new vector that starts at origin and points to <c>(x, y,
  ///   z)</c>.
  /// </summary>
  Vector(T x, T y, T z) : head(x, y, z){};

  /// <summary>
  ///   Returns the <i>unit vector</i> of this one. This is equivalent to return
  ///   the <i>normalized form</i> of the vector.
  /// </summary>
  Vector<double>* normalized();

  /// <summary>
  ///   Returns the <i>magnitude</i> of this vector.
  ///   This is equivalent to calculating the <i>length</> or <i>modulus</i> of
  ///   the vector.
  /// </summary>
  double magnitude() const;

  /// <summary>
  ///   Calculates and returns the <i>dot product</i> (or <i>inner product</i>)
  ///   of this vector with another one.
  /// </summary>
  inline double dot(const Vector<T>& v) const;

  /// <summary>
  ///   Calculates the <i>cross product</i> of this vector with another one.
  /// </summary>
  /// <returns>The calculated product.</returns>
  inline Vector<T>* cross(const Vector<T>& v) const;

  #pragma region COMPOUND ASSIGNMENTS
  /// <summary>
  ///   Addition compound assignment for a vector.
  /// </summary>
  Vector<T>& operator+=(const Vector<T>& addend);

  /// <summary>
  ///   Subtraction compound assignment for a vector.
  /// </summary>
  Vector<T>& operator-=(const Vector<T>& subtrahend);
#pragma endregion

  /// <summary>
  ///   Returns the head of this vector.
  /// </summary>
  inline Point<T> getHead() const;

  inline double getX() const { return head.getX(); };
  inline double getY() const { return head.getY(); };
  inline double getZ() const { return head.getZ(); };

 private:
  /// <summary>
  ///   Squares a number <c>n</c>.
  /// </summary>
  /// <returns>The squared number.</returns>
  double square(double n) const;

  Point<T> head;
};

template <class T>
inline bool operator==(const Vector<T>& left, const Vector<T>& right) {
  return left.getHead() == right.getHead();
}

template <class T>
inline bool operator!=(const Vector<T>& left, const Vector<T>& right) {
  return !(left.getHead() == right.getHead());
}

//template <class T>
//inline std::ostream operator<<(std::ostream &stream, const Vector<T> &v) {
//  return stream << "Vector{x: " << v.getX() << ", y: " << v.getY()
//              << ", z: " << v.getZ() << "}";
//}

template <class T>
inline Vector<double>* Vector<T>::normalized() {
  return new Vector<double>(head.getX() / this->magnitude(),
                            head.getY() / this->magnitude(),
                            head.getZ() / this->magnitude());
}

template <class T>
inline double Vector<T>::magnitude() const {
  return sqrt(square(head.getX()) + square(head.getY()) + square(head.getZ()));
}

template <class T>
inline double Vector<T>::dot(const Vector<T>& v) const {
  return head.getX() * v.getHead().getX() + head.getY() * v.getHead().getY() +
         head.getZ() * v.getHead().getZ();
}

template <class T>
inline Vector<T>* Vector<T>::cross(const Vector<T>& v) const {
  return new Vector<T>(this->getY() * v.getZ() - this->getZ() * v.getY(),
                       this->getZ() * v.getX() - this->getX() * v.getZ(),
                       this->getX() * v.getY() - this->getY() * v.getX());
}

template <class T>
inline Vector<T>& Vector<T>::operator+=(const Vector<T>& addend) {
  this->head += addend.getHead();
  return *this;
}

template <class T>
inline Vector<T>& Vector<T>::operator-=(const Vector<T>& subtrahend) {
  this->head -= subtrahend.getHead();
  return *this;
}

template <class T>
inline Point<T> Vector<T>::getHead() const {
  return this->head;
}
template <class T>
inline double Vector<T>::square(double n) const {
  return pow(n, 2);
}
}  // namespace Primitives
}  // namespace Segeom