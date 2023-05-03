#pragma once

#include "src/data-structure/segment-tree/presets/monoid/operator-structure-update.hpp"
#include "src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp"

namespace luz {

  template < typename T, T ID >
  using RangeUpdateQuerySolver =
      DualSegmentTree< monoid::RangeUpdateQueryMonoid< T, ID > >;

} // namespace luz
