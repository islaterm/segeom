#pragma once
#include "segment.h"
#include <algorithm>
#include <exception>
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
       * @brief Returns a copy of this polygon with inverted winding order.
       */
      Polygon<T> inverted();

      /**
       * @brief Computes the area of this polygon.
       */
      T area() const;

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

  /**
   * @brief An exception thrown when a geometric operation is not allowed or returned an invalid
   *        result.
   */
  class GeometryException : public std::exception {
  public:
    GeometryException(const std::string &message) : message_(message){};
    virtual const char *what() const throw();

  private:
    std::string message_;
  };
} // namespace segeom

using namespace segeom::primitives;

template <class T>
Polygon<T> Polygon<T>::inverted() {
  std::vector<Point2D<T>> rev = this->vertices_;
  std::reverse(rev.begin(), rev.end());
  return rev;
}

template <class T>
T Polygon<T>::area() const {
  return 0;
}

template <class T>
inline std::vector<Point2D<T>> Polygon<T>::vertices() const {
  return vertices_;
}

template <class T>
inline std::vector<Segment<T>> Polygon<T>::sides() const {
  return sides_;
}
