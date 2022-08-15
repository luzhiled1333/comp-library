#pragma once

#include "src/geometry/Z2/class/circle.hpp"
#include "src/geometry/Z2/class/point.hpp"
#include "src/geometry/Z2/operation/square-norm.hpp"
#include "src/geometry/Z2/operation/square.hpp"

#include <utility>

namespace luz {

  namespace Z2 {

    template < typename Z >
    bool is_intersect_cc(Circle< Z > c0, Circle< Z > c1) {
      if (c0.r() > c1.r()) std::swap(c0, c1);

      Z sq_dist = square_norm(c0.center() - c1.center());

      if (sq_dist < square(c1.r() - c0.r())) return false;
      if (square(c1.r() + c0.r()) < sq_dist) return false;
      return true;
    }

  } // namespace Z2

} // namespace luz
