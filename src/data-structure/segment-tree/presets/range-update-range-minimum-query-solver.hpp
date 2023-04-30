#pragma once

#include "src/data-structure/segment-tree/presets/monoid/combined-structure-update-minimum.hpp"
#include "src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp"

namespace luz {

  template < typename T, T ID >
  using RangeUpdateRangeMinimumQuerySolver =
      LazySegmentTree< monoid::RangeUpdateRangeMinimumQueryMonoid< T, ID > >;

} // namespace luz
