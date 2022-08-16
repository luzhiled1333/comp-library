#pragma once

#include "src/geometry/Z2/class/point.hpp"

namespace luz {

  namespace Z2 {

    template < typename Z >
    class Circle {

      Point< Z > o_;
      Z r_;

     public:
      Circle(): o_(0, 0), r_(0) {}

      Circle(Point< Z > o, Z r): o_(o), r_(r) {
        assert(r >= 0);
      }

      Point< Z > center() const {
        return o_;
      }

      Z r() const {
        return r_;
      }
    };

    template < typename Z >
    using Circles = std::vector< Circle< Z > >;

  } // namespace Z2

} // namespace luz
