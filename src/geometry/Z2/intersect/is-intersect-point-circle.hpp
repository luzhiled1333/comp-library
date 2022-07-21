#pragma once

#include "src/geometry/Z2/struct/point.hpp"
#include "src/geometry/Z2/struct/circle.hpp"
#include "src/geometry/Z2/operation/square-norm.hpp"

namespace luz {

namespace Z2 {

  template< typename Z >
  bool is_intersect_pc(Point< Z > p, Circle< Z > c) {
    Z sq_norm = square_norm(c.center() - p);
    return sq_norm == square(c.r());
  }

} // namespace Z2

} // namespace luz
