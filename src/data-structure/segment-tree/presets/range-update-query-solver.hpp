#pragma once

#include "src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp"

#include <algorithm>

namespace luz::monoid {

  template < typename T, T ID >
  class RangeUpdateQueryMonoid {

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return b == ID ? a : b;
    }

    static constexpr T identity() {
      return ID;
    }
  };

} // namespace luz::monoid

namespace luz {

  template < typename T, T ID >
  using RangeUpdateQuerySolver =
      DualSegmentTree< monoid::RangeUpdateQueryMonoid< T, ID > >;

} // namespace luz
