#pragma once

#include "src/geometry/Z2/class/vector.hpp"

#include <vector>

namespace luz {

  namespace Z2 {

    template < typename Z >
    using Point = Vector< Z >;

    template < typename Z >
    using Points = std::vector< Point< Z > >;

  } // namespace Z2

} // namespace luz
