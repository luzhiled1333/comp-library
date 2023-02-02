#pragma once

#include "src/geometry/R2/class/vector.hpp"

#include <vector>

namespace luz::R2 {

  template < typename Z >
  using Point = Vector< Z >;

  template < typename Z >
  using Points = std::vector< Point< Z > >;

} // namespace luz::R2
