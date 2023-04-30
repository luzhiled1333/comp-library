#pragma once

#include "src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp"
#include "src/data-structure/segment-tree/presets/monoid/combined-structure-add-minimum.hpp"

namespace luz {

  template < typename T >
  using RangeAddRangeMinimumQuerySolver =
      LazySegmentTree< monoid::RangeAddRangeMinimumQueryMonoid< T > >;

} // namespace luz
