#pragma once

#include "src/geometry/Z2/class/vector.hpp"

namespace luz::Z2 {

  template < typename Z >
  Z cross_product(const Vector< Z > &a, const Vector< Z > &b) {
    return a.x() * b.y() - a.y() * b.x();
  }

} // namespace luz::Z2
