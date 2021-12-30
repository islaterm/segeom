#pragma once
#include "main/exceptions.h"
#include "segment.h"
#include <algorithm>
#include <vector>

namespace segeom {
  namespace primitives {
    /**
     * @brief Representation of a polygon.
     *        A polygon is defined by the segments that conform its sides.
     *
     * @tparam T
     *    A numerical data type. Behaviour for non-numerical types is undefined.
     */
    template <class T>
    class Polygon {
    private:
      std::vector<Point2D<T>> vertices_;
      std::vector<Segment<T>> sides_;

    public:
      /**
       * @brief Creates a new polygon from a set of points.
       */
      Polygon(std::vector<Point2D<T>> vertices) : vertices_(vertices) {
        std::size_t i;
        for (i = 0; i < vertices.size(); i++) {
          Segment<T> segment(&vertices[i], &vertices[i + 1]);
          sides_.push_back(segment);
        }
        Segment<T> closing_segment(&vertices[vertices.size() - 1], &vertices[0]);
      };

      /**
       * @brief Copy constructor.
       */
      Polygon(const Polygon<T> &polygon) : vertices_(polygon.vertices_){};

      /**
       * @brief Returns a copy of this polygon with inverted winding order.
       */
      Polygon<T> inverted();

      /**
       * @brief Computes the area of this polygon.
       */
      double area() const;

      /**
       * @brief Returns a vector containing the vertices of the polygon.
       */
      inline std::vector<Point2D<T>> vertices() const;

      /**
       * @brief Returns a vector containing the sides of the polygon.
       */
      inline std::vector<Segment<T>> sides() const;
    };
  } // namespace primitives
} // namespace segeom

using namespace segeom::primitives;

template <class T>
Polygon<T> Polygon<T>::inverted() {
  std::vector<Point2D<T>> rev = this->vertices_;
  std::reverse(rev.begin(), rev.end());
  return rev;
}

template <class T>
double Polygon<T>::area() const {
  double result = 0;
  for (size_t i = 0; i < vertices_.size() - 1; i++) {
    result += vertices_[i].x() * vertices_[i].x() - vertices_[i + 1].y() * vertices_[i + 1].x();
  }

  if (result == 0) {
    throw segeom::GeometryException("Can't calculate area of malformed polygon");
  }
  return result * 0.5;
}

template <class T>
inline std::vector<Point2D<T>> Polygon<T>::vertices() const {
  return vertices_;
}

template <class T>
inline std::vector<Segment<T>> Polygon<T>::sides() const {
  return sides_;
}
