#pragma once
#include <iostream>

#include "Point.h"
#include "../mathUtils.h"

namespace segeom {
namespace primitives {
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
  Segment(Point3D<T>* start, Point3D<T>* end) : startPoint(start), endPoint(end) {}
  ~Segment();

  /// <summary>
  /// Returns the length of this segment.
  /// </summary>
  inline double length() const;

  /// <summary>
  /// Returns the starting point of the segment.
  /// </summary>
  inline Point3D<T>* getStart() const;

  /// <summary>
  /// Returns the end point of the segment.
  /// </summary>
  inline Point3D<T>* getEnd() const;

 private:
  Point3D<T>* startPoint;
  Point3D<T>* endPoint;
};

template <class T>
inline Segment<T>::~Segment() {
  delete startPoint;
  delete endPoint;
}

template <class T>
inline double Segment<T>::length() const {
   return segeom::Utils::norm3D(endPoint->x() - startPoint->x(),
                                       endPoint->y() - startPoint->y(),
                                       endPoint->z() - startPoint->z());
}

template <class T>
inline Point3D<T>* Segment<T>::getStart() const {
  return startPoint;
}

template <class T>
inline Point3D<T>* Segment<T>::getEnd() const {
  return endPoint;
}
}  // namespace primitives
}  // namespace segeom
