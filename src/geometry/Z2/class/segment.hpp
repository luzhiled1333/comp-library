#pragma once

#include "src/geometry/Z2/class/point.hpp"

#include <cassert>
#include <vector>

namespace luz::Z2 {

  template < typename Z >
  class Segment {
    Point< Z > p0_, p1_;

   public:
    Segment() = default;

    Segment(Point< Z > p0, Point< Z > p1): p0_(p0), p1_(p1) {
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
  using Segments = std::vector< Segment< Z > >;

} // namespace luz::Z2
