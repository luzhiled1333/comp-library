#pragma once

#include "src/geometry/R2/class/vector.hpp"

#include <vector>

namespace luz {
  namespace R2 {

    template < typename Z >
    using Point = Vector< Z >;

    template < typename Z >
    using Points = std::vector< Point< Z > >;

  } // namespace R2
} // namespace luz
