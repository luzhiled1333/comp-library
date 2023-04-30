#pragma once

#include "src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp"

#include <algorithm>
#include <limits>

namespace luz::monoid {

  template < typename T >
  class RangeChmaxQueryMonoid {
    static constexpr T identity_{std::numeric_limits< T >::min()};

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return std::max(a, b);
    }

    static constexpr T identity() {
      return identity_;
    }
  };

} // namespace luz::monoid

namespace luz {

  template < typename T >
  using RangeChmaxQuerySolver =
      DualSegmentTree< monoid::RangeChmaxQueryMonoid< T > >;

} // namespace luz
