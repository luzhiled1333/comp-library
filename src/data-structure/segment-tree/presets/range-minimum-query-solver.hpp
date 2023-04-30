#pragma once

#include "src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp"
#include "src/data-structure/segment-tree/presets/monoid/value-structure-minimum.hpp"

namespace luz {

  template < typename T >
  using RangeMinimumQuerySolver =
      SegmentTree< monoid::RangeMinimumQueryMonoid< T > >;

} // namespace luz
