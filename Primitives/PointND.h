#pragma once

#include <iostream>
#include <vector>

#include "../mathUtils.h"

namespace Segeom {
namespace Primitives {
template <class T>
class PointND {
#pragma region OPERATIONS
  /// <summary>
  /// Two points are equal if they have the same size and elements.
  /// </summary>
  friend inline bool operator==(const PointND<T>& left,
                                const PointND<T>& right) {
    auto& lCoord = left.getCoordinates();
    auto& rCoord = right.getCoordinates();
    if (lCoord.size() != rCoord.size()) {
      return false;
    }
    for (size_t i = 0; i < lCoord.size(); i++) {
      if (abs(lCoord[i] - rCoord[i]) >= Segeom::Utils::DELTA) {
        return false;
      }
    }
    return true;
  }

  friend inline bool operator!=(const PointND<T>& left,
                                const PointND<T>& right) {
    return !(left == right);
  }

  friend std::ostream& operator<<(std::ostream& os, const PointND<T>& point) {
    os << "Point {";
    size_t length = point.getCoordinates().size();
    for (size_t i = 0; i < length; i++) {
      os << "x" << i << ": " << point.getCoordinates()[i];
      if (i != length - 1) {
        os << ", ";
      }
    }
    os << "}";
    return os;
  }

  /// <summary>
  ///   Performs the addition of two points.
  /// </summary>
  friend PointND<T> operator+(PointND<T> lAddend, const PointND<T>& rAddend) {
    lAddend += rAddend;
    return lAddend;
  }
#pragma endregion

 public:
  PointND() : coordinates(std::vector<T>{}) {}
  PointND(std::vector<double>& elems) : coordinates(elems){};

  /// <summary>
  /// Returns the size of this point (i.e. the number of coordinates).
  /// </summary>
  size_t getSize() const;

  std::vector<T> getCoordinates() const;

 private:
  std::vector<T> coordinates;
};
template <class T>
inline size_t PointND<T>::getSize() const {
  return this->coordinates.size();
}

template <class T>
inline std::vector<T> PointND<T>::getCoordinates() const {
  return this->coordinates;
}
}  // namespace Primitives
}  // namespace Segeom
