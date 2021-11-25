#include "main/Primitives/PointND.h"
#include <vector>

namespace Segeom {
  namespace Primitives {
    /**
     * @brief This class represents a 3-dimensional point.
     *
     * @tparam T
     *    A numerical data-type. Behaviour for non-arithmetic types is undefined.
     */
    template <class T>
    class Point3D : public PointND<T> {
    private:
      /* data */
    public:
    /**
     * @brief Construct a new 3-dimensional point.
     */
      Point3D(T x, T y, T z) : PointND{std::vector{x, y, z}} {};
      ~Point3D();
    };
  } // namespace Primitives
} // namespace Segeom
