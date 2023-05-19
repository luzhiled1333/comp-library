#pragma once

#include "src/data-structure/segment-tree/presets/monoid/combined-structure-add-sum.hpp"
#include "src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp"

namespace luz {

  template < typename T >
  using RangeAddRangeSumQuerySolver =
      LazySegmentTree< monoid::RangeAddRangeSumQueryMonoid< T > >;

} // namespace luz
