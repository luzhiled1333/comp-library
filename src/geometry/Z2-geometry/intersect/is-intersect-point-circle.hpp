#pragma once

#include "src/geometry/Z2-geometry/struct/point.hpp"
#include "src/geometry/Z2-geometry/struct/circle.hpp"
#include "src/geometry/Z2-geometry/operation/square-norm.hpp"

namespace luz {

namespace Z2 {

  template< typename Z >
  bool is_intersect_pc(const Point< Z > &p, const Circle< Z > &c) {
    Z sq_norm = square_norm(c.centor() - p);
    return sq_norm == p.r() * p.r();
  }

} // namespace Z2

} // namespace luz
