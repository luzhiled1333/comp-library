#pragma once

#include "src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp"
#include "src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp"

namespace luz::monoid {

  template < typename T, T ID >
  class RangeUpdateRangeMaximumQueryMonoid {
    using V  = RangeMaximumQueryMonoid< T >;
    using VT = typename V::value_type;
    using O  = RangeUpdateQueryMonoid< T, ID >;
    using OT = typename O::value_type;

   public:
    using value_structure    = V;
    using operator_structure = O;

    static constexpr T operation(VT a, OT b) {
      return b == ID ? a : b;
    }
  };

} // namespace luz::monoid
