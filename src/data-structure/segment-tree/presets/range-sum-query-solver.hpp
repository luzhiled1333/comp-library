#pragma once

#include "src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp"
#include "src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp"

namespace luz {

  template < typename T >
  using RangeSumQuerySolver =
      SegmentTree< monoid::RangeSumQueryMonoid< T > >;

} // namespace luz
