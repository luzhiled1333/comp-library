#pragma once

#include "src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp"
#include "src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp"

namespace luz {

  template < typename T >
  using RangeAddQuerySolver =
      DualSegmentTree< monoid::RangeAddQueryMonoid< T > >;

} // namespace luz
