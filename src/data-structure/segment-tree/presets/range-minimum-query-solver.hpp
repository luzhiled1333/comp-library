#pragma once

#include "src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp"

#include <algorithm>
#include <limits>

namespace luz::monoid {

  template < typename T >
  class RangeMinimumQueryMonoid {

    static constexpr T identity_{std::numeric_limits< T >::max()};

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return std::min(a, b);
    }

    static constexpr T identity() {
      return identity_;
    }
  };

} // namespace luz::monoid

namespace luz {

  template < typename T >
  using RangeMinimumQuerySolver =
      SegmentTree< monoid::RangeMinimumQueryMonoid< T > >;

} // namespace luz
