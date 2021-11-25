#pragma once
#include <iostream>

#include "Point.h"
#include "../mathUtils.h"

namespace Segeom {
namespace Primitives {
/// <summary>
/// A segment is defined as a line that connects two <see cref="Point"/>s.
///
/// Every segment has a length and, for any point, it can tell if it's to its
/// right or left (counter-clockwise).
/// </summary>
/// <typeparam name="T">
/// A numerical data type, behaviour for non numerical data types is undefined.
/// </typeparam>
template <class T>
class Segment {
  template <class T>
  friend inline bool operator==(const Segment<T>& left,
                                const Segment<T>& right) {
    return left.startPoint == right.startPoint &&
           left.endPoint == right.endPoint;
  }

  template <class T>
  friend inline bool operator!=(const Segment<T>& left,
                                const Segment<T>& right) {
    return !(left == right);
  }

  /// <summary>
  /// Returns an output stream representing a segment.
  /// </summary>
  friend std::ostream& operator<<(std::ostream& os, const Segment<T>& segment) {
    os << "Segment{start: " << segment.getStart()
       << ", end: " << segment.getEnd() << "}";
    return os;
  }

 public:
  /// <summary>
  /// Creates a new segment that goes from <c>start</c> to <c>end</c>.
  /// </summary>
  Segment(Point<T>* start, Point<T>* end) : startPoint(start), endPoint(end) {}
  ~Segment();

  /// <summary>
  /// Returns the length of this segment.
  /// </summary>
  inline double length() const;

  /// <summary>
  /// Returns the starting point of the segment.
  /// </summary>
  inline Point<T>* getStart() const;

  /// <summary>
  /// Returns the end point of the segment.
  /// </summary>
  inline Point<T>* getEnd() const;

 private:
  Point<T>* startPoint;
  Point<T>* endPoint;
};

template <class T>
inline Segment<T>::~Segment() {
  delete startPoint;
  delete endPoint;
}

template <class T>
inline double Segment<T>::length() const {
   return Segeom::Utils::norm3D(endPoint->getX() - startPoint->getX(),
                                       endPoint->getY() - startPoint->getY(),
                                       endPoint->getZ() - startPoint->getZ());
}

template <class T>
inline Point<T>* Segment<T>::getStart() const {
  return startPoint;
}

template <class T>
inline Point<T>* Segment<T>::getEnd() const {
  return endPoint;
}
}  // namespace Primitives
}  // namespace Segeom
