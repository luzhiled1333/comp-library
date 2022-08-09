#pragma once

#include "src/geometry/Z2/class/point.hpp"

namespace luz {

namespace Z2 {

  template< typename Z >
  class Circle {

    Point< Z > center_;
    Z r_;

   public:
    Circle(): center_(0, 0), r_(0) {}

    Circle(Point< Z > center, Z r): center_(center), r_(r) {
      assert(r >= 0);
    }

    Point< Z > center() const {
      return center_;
    }

    Z r() const {
      return r_;
    }
  };

  template< typename Z >
  using Circles = std::vector< Circle< Z > >;

} // namespace Z2

} // namespace luz
