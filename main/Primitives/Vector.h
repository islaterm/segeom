#pragma once

#include <iostream>

#include "point.h"

namespace segeom {
  namespace primitives {
    /**
     * @brief An euclidean vector, that is, an object that has a magnitude and a direction.
     */
    template <class T>
    class Vector;

    /**
     * @brief Performs the addition of two vectors.
     */
    template <class T>
    Vector<T> operator+(Vector<T> l_addend, const Vector<T> &r_addend);

    /**
     * @brief Performs the subtraction of two vectors.
     */
    template <class T>
    Vector<T> operator-(Vector<T> minuend, const Vector<T> &subtrahend);

    /**
     * @brief Returns an output stream that represents a vector.
     */
    template <class T>
    std::ostream &operator<<(std::ostream &os, const Vector<T> &vector);

    template <class T>
    inline bool operator==(const Vector<T> &left, const Vector<T> &right);

    template <class T>
    inline bool operator!=(const Vector<T> &left, const Vector<T> &right);

    template <class T>
    class Vector {
    public:
      /**
       * @brief Creates a new vector that starts at origin and points to @code (x, y, z) @endcode
       */
      Vector(T x, T y, T z) : head_(x, y, z){};

      /**
       * @brief Returns the _unit vector_ of this one. This is equivalent to return the _normalized
       * form_ of the vector.
       */
      Vector<double> *normalized();

      /**
       * @brief Returns the _magnitude_ of this vector.
       *        This is equivalent to calculating the _length_ or _modulus_ of the vector.
       */
      double magnitude();

      /**
       * @brief Calculates and returns the _dot product_ (or _inner product_) of this vector with
       *        another one.
       */
      inline double dot(const Vector<T> &v) const;

      /**
       * @brief Calculates the _cross product_ of this vector with another one.
       */
      inline Vector<T> *cross(const Vector<T> &v) const;

      /**
       * @brief Addition compound assignment for a vector.
       */
      Vector<T> &operator+=(const Vector<T> &addend);

      /**
       * @brief Subtraction compound assignment for a vector.
       */
      Vector<T> &operator-=(const Vector<T> &subtrahend);

      /**
       * @brief Returns the head of this vector.
       */
      inline Point3D<T> head() const;

      inline double x() const { return head_.x(); };
      inline double y() const { return head_.y(); };
      inline double z() const { return head_.z(); };

    private:
      Point3D<T> head_;

      friend Vector<T> operator+<>(Vector<T> l_addend, const Vector<T> &r_addend);

      friend Vector<T> operator-<>(Vector<T> minuend, const Vector<T> &subtrahend);

      friend std::ostream &operator<<<>(std::ostream &os, const Vector<T> &vector);

      friend inline bool operator==<>(const Vector<T> &left, const Vector<T> &right);

      friend inline bool operator!=<>(const Vector<T> &left, const Vector<T> &right);
    };
  } // namespace primitives
} // namespace segeom

using namespace segeom::primitives;

template <class T>
Vector<T> segeom::primitives::operator+(Vector<T> l_addend, const Vector<T> &r_addend) {
  l_addend += r_addend;
  return l_addend;
}

template <class T>
Vector<T> segeom::primitives::operator-(Vector<T> minuend, const Vector<T> &subtrahend) {
  minuend -= subtrahend;
  return minuend;
}

template <class T>
std::ostream &segeom::primitives::operator<<(std::ostream &os, const Vector<T> &vector) {
  os << "Vector{x: " << vector.x() << ", y: " << vector.y() << ", z: " << vector.z() << "}";
  return os;
}

template <class T>
inline bool segeom::primitives::operator==(const Vector<T> &left, const Vector<T> &right) {
  return left.head() == right.head();
}

template <class T>
inline bool segeom::primitives::operator!=(const Vector<T> &left, const Vector<T> &right) {
  return !(left.head() == right.head());
}

template <class T>
inline Vector<double> *Vector<T>::normalized() {
  return new Vector<double>(head_.x() / this->magnitude(), head_.y() / this->magnitude(),
                            head_.z() / this->magnitude());
}

template <class T>
inline double Vector<T>::magnitude() {
  return utils::norm3D<double>(head_.x(), head_.y(), head_.z());
}

template <class T>
inline double Vector<T>::dot(const Vector<T> &v) const {
  return head_.x() * v.head().x() + head_.y() * v.head().y() + head_.z() * v.head().z();
}

template <class T>
inline Vector<T> *Vector<T>::cross(const Vector<T> &v) const {
  return new Vector<T>(this->y() * v.z() - this->z() * v.y(), this->z() * v.x() - this->x() * v.z(),
                       this->x() * v.y() - this->y() * v.x());
}

template <class T>
inline Vector<T> &Vector<T>::operator+=(const Vector<T> &addend) {
  this->head_ += addend.head();
  return *this;
}

template <class T>
inline Vector<T> &Vector<T>::operator-=(const Vector<T> &subtrahend) {
  this->head_ -= subtrahend.head();
  return *this;
}

template <class T>
inline Point3D<T> Vector<T>::head() const {
  return this->head_;
}