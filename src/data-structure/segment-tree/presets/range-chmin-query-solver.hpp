#pragma once

#include "src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp"
#include "src/data-structure/segment-tree/presets/monoid/operator-structure-chmin.hpp"

namespace luz {

  template < typename T >
  using RangeChminQuerySolver =
      DualSegmentTree< monoid::RangeChminQueryMonoid< T > >;

} // namespace luz
