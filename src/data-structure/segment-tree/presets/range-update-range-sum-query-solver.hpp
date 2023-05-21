#pragma once

#include "src/data-structure/segment-tree/presets/monoid/combined-structure-update-sum.hpp"
#include "src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp"

namespace luz {

  template < typename T, T ID >
  using RangeUpdateRangeSumQuerySolver = LazySegmentTree<
      monoid::RangeUpdateRangeSumQueryMonoid< T, ID > >;

} // namespace luz
