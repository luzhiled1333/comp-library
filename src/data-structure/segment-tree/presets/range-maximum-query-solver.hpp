#pragma once

#include "src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp"
#include "src/data-structure/segment-tree/presets/monoid/value-structure-maximum.hpp"

namespace luz {

  template < typename T >
  using RangeMaximumQuerySolver =
      SegmentTree< monoid::RangeMaximumQueryMonoid< T > >;

} // namespace luz
