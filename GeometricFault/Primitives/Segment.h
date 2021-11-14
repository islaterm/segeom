#pragma once
#include "Point.h"

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
 public:
  /// <summary>
  /// Creates a new segment that goes from <c>start</c> to <c>end</c>.
  /// </summary>
  Segment(Point<T>* start, Point<T>* end) : startPoint(start), endPoint(end) {}
  ~Segment();

 private:
  Point<T>* startPoint;
  Point<T>* endPoint;
};
template <class T>
inline Segment<T>::~Segment() {
  delete startPoint;
  delete endPoint;
}
}  // namespace Primitives
}  // namespace Segeom
