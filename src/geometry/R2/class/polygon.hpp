#pragma once

#include "src/geometry/R2/class/point.hpp"

#include <vector>

namespace luz::R2 {

  template < typename R >
  using Polygon = std::vector< Point< R > >;

  template < typename R >
  using Polygons = std::vector< Polygon< R > >;

} // namespace luz::R2
