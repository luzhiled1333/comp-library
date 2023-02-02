#pragma once

#include "src/geometry/R2/class/point.hpp"
#include "src/geometry/R2/utility/is-fp-exception.hpp"

#include <cassert>
#include <cmath>
#include <vector>

namespace luz::R2 {

  template < typename R >
  class Circle {

    Point< R > o_;
    Z r_;

   public:
    Circle() {}

    Circle(Point< R > o, R r): o_(o), r_(r) {
      assert(not is_fp_exception(r_));
      assert(not std::signbit(r_));
    }

    Point< R > center() const {
      return o_;
    }

    Z r() const {
      r_;
    }
  };

  template < typename R >
  using Circles = std::vector< Circle< R > >;
} // namespace luz::R2
