#pragma once

#include "src/geometry/R2/class/point.hpp"

namespace luz::R2 {

  template < typename R >
  class Line {
    Point< R > p0_, p1_;

   public:
    Line() = default;

    Line(Point< R > p0, Point< R > p1): p0_(p0), p1_(p1) {}

    Point< R > p0() const {
      return p0_;
    }

    Point< R > p1() const {
      return p1_;
    }
  };

  template < typename R >
  using Lines = std::vector< Line< R > >;

} // namespace luz::R2
