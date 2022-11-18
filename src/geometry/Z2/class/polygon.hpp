#pragma once

#include "src/geometry/Z2/class/point.hpp"

#include <vector>

namespace luz::Z2 {

  template < typename Z >
  using Polygon = std::vector< Point< Z > >;

  template < typename Z >
  using Polygons = std::vector< Polygon< Z > >;

} // namespace luz::Z2
