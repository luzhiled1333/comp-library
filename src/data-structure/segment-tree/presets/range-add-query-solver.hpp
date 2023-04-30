#pragma once

#include "src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp"

#include <algorithm>

namespace luz::monoid {

  template < typename T >
  class RangeAddQueryMonoid {

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return a + b;
    }

    static constexpr T identity() {
      return T();
    }
  };

} // namespace luz::monoid

namespace luz {

  template < typename T >
  using RangeAddQuerySolver =
      DualSegmentTree< monoid::RangeAddQueryMonoid< T > >;

} // namespace luz
