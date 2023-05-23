#pragma once

#include "src/geometry/Z2/class/point.hpp"

namespace luz::Z2 {

  template < typename Z >
  Points< Z > multiply_for_all_points(Z k, Points< Z > pts) {
    for (auto &pt: pts) pt = Point< Z >(pt.x() * k, pt.y() * k);
    return pts;
  }

} // namespace luz::Z2
