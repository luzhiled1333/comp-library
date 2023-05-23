#pragma once

#include "src/geometry/2d/common/class/vector-2d.hpp"

#include <type_traits>

namespace luz::geometry::z2 {

  template < class Z >
  class Vector2d: public luz::geometry::common::Vector2d< Z > {
    static_assert(std::is_integral< Z >::value);

   public:
    Vector2d() = default;
  };

} // namespace luz::geometry::z2
