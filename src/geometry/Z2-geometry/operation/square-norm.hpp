#pragma once

#include "src/geometry/Z2-geometry/operation/square.hpp"
#include "src/geometry/Z2-geometry/struct/vector.hpp"

namespace luz {

namespace Z2 {

  template< typename Z >
  Z square_norm(const Vector< Z > &v) {
    return square(v.x()) + square(v.y());
  }

} // namespace Z2

} // namespace luz
