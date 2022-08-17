#pragma once

#include <vector>

#include "src/geometry/Z2/class/vector.hpp"

namespace luz {

  namespace Z2 {

    template < typename Z >
    using Point = Vector< Z >;

    template < typename Z >
    using Points = std::vector< Point< Z > >;

  } // namespace Z2

} // namespace luz
