#pragma once

#include "src/geometry/R2/class/point.hpp"

#include <cassert>
#include <vector>

namespace luz::R2 {

  template < typename R >
  class Segment {
    Point< R > p0_, p1_;

   public:
    Segment() = default;

    Segment(Point< R > p0, Point< R > p1): p0_(p0), p1_(p1) {}

    Point< R > p0() const {
      return p0_;
    }

    Point< R > p1() const {
      return p1_;
    }
  };

  template < typename R >
  using Segments = std::vector< Segment< R > >;

} // namespace luz::R2
