#pragma once

#include "src/geometry/Z2/class/point.hpp"

namespace luz::Z2 {

  template< typename Z >
  class Circle {

    Point< Z > center_;
    Z r_;

   public:
    Circle() {}
    Circle(Point< Z > center, Z r): center_(center), r_(r) {}

    Point< Z > center() const {
      return center_;
    }

    Z r() const {
      return r_;
    }
  };

  template< typename Z >
  using Circles = std::vector< Circle< Z > >;

} // namespace luz::Z2
