#pragma once

#include "src/data-structure/segment-tree/presets/monoid/combined-structure-update-maximum.hpp"
#include "src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp"

namespace luz {

  template < typename T, T ID >
  using RangeUpdateRangeMaximumQuerySolver =
      LazySegmentTree< monoid::RangeUpdateRangeMaximumQueryMonoid< T, ID > >;

} // namespace luz
