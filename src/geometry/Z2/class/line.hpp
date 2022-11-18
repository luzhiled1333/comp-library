#include "src/geometry/Z2/class/point.hpp"

#include <cassert>
#include <vector>

namespace luz::Z2 {

  template < typename Z >
  class Line {
    Point< Z > p0_, p1_;

   public:
    Line() = default;

    Line(Point< Z > p0, Point< Z > p1): p0_(p0), p1_(p1) {
      assert(p0 != p1);
    }

    Point< Z > p0() const {
      return p0_;
    }

    Point< Z > p1() const {
      return p1_;
    }
  };

  template < typename Z >
  using Lines = std::vector< Line< Z > >;

} // namespace luz::Z2
