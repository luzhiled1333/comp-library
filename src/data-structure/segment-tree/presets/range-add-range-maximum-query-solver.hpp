#pragma once

#include "src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp"
#include "src/data-structure/segment-tree/presets/monoid/combined-structure-add-maximum.hpp"

namespace luz {

  template < typename T >
  using RangeAddRangeMaximumQuerySolver =
      LazySegmentTree< monoid::RangeAddRangeMaximumQueryMonoid< T > >;

} // namespace luz
