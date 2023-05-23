#pragma once

#include "src/geometry/2d/common/class/vector-2d.hpp"

#include <type_traits>

namespace luz::geometry::r2 {

  template< class R >
  class Vector2d: public luz::geometry::common::Vector2d< R > {
    static_assert(std::is_floating_point<R>::value);

   public:
    Vector2d() = default;

    bool operator==(const Vector2d &rhs) const {
      // TODO
      return false;
    }
  };

} // namespace geometry::r2
