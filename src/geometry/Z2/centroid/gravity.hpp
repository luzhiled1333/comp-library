#pragma once

#include "src/geometry/Z2/class/point.hpp"

#include <numeric>

namespace luz::Z2 {

  template < typename Z >
  Point< Z > ntimes_gravity(const Points< Z > &pts) {
    return std::accumulate(pts.begin(), pts.end(), Point< Z >());
  }

} // namespace luz::Z2
