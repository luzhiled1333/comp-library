#pragma once

#include "src/geometry/R2/class/vector.hpp"

#include <vector>

namespace luz::R2 {

  template < typename R >
  using Point = Vector< R >;

  template < typename R >
  using Points = std::vector< Point< R > >;

} // namespace luz::R2
