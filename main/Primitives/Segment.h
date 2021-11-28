#pragma once
#include <iostream>
#include <limits>

#include "main/math_utils.h"
#include "point.h"

namespace segeom {
  namespace primitives {
    /**
     * @brief A segment is defined as a line that connects two Points
     * @details Every segment has a length and, for any point, it can tell if it's to itsright or
     *          left (counter-clockwise).
     */
    template <class T>
    class Segment;

    template <class T>
    inline bool operator==(const Segment<T> &left, const Segment<T> &right);

    template <class T>
    inline bool operator!=(const Segment<T> &left, const Segment<T> &right);

    /**
     * @brief Returns an output stream representing a segment.
     */
    template <class T>
    std::ostream &operator<<(std::ostream &os, const Segment<T> &segment);

    template <class T>
    class Segment {
    public:
      /**
       * @brief Creates a new segment that goes from `start` to `end`.
       */
      Segment(Point2D<T> *start, Point2D<T> *end) : start_(start), end_(end) {}
      ~Segment();

      inline int direction_to(Point2D<T> point) const {
        return 0;
      }

      /**
       * @brief Returns the length of this segment.
       */
      inline double length() const;

      /**
       * @brief Computes the slope of this segment.
       */
      inline double slope() const;

      /**
       * @brief Returns the starting point of the segment.
       */
      inline Point2D<T> *start() const;

      /**
       * @brief Returns the end point of the segment.
       */
      inline Point2D<T> *end() const;

    private:
      Point2D<T> *start_;
      Point2D<T> *end_;

      friend inline bool operator==<>(const Segment<T> &left, const Segment<T> &right);

      friend inline bool operator!=<>(const Segment<T> &left, const Segment<T> &right);

      friend std::ostream &operator<<<>(std::ostream &os, const Segment<T> &segment);
    };
  } // namespace primitives
} // namespace segeom

using namespace segeom::primitives;

template <class T>
inline bool segeom::primitives::operator==(const Segment<T> &left, const Segment<T> &right) {
  return left.start_ == right.start_ && left.end_ == right.end_;
}

template <class T>
inline bool segeom::primitives::operator!=(const Segment<T> &left, const Segment<T> &right) {
  return !(left == right);
}

template <class T>
std::ostream &segeom::primitives::operator<<(std::ostream &os, const Segment<T> &segment) {
  os << "Segment{start: " << segment.start() << ", end: " << segment.end() << "}";
  return os;
}

template <class T>
inline Segment<T>::~Segment() {
  delete start_;
  delete end_;
}

template <class T>
inline double Segment<T>::length() const {
  return sqrt(segeom::utils::square<T>(end_->x() - start_->x()) +
              segeom::utils::square<T>(end_->y() - start_->y()));
}

template <class T>
inline double Segment<T>::slope() const {
  if (this->start_->y() == this->end_->y()) {
    return std::numeric_limits<double>::infinity();
  }
  return (this->end_->y() - this->start_->y()) / (this->end_->x() - this->start_->x());
}

template <class T>
inline Point2D<T> *Segment<T>::start() const {
  return start_;
}

template <class T>
inline Point2D<T> *Segment<T>::end() const {
  return end_;
}