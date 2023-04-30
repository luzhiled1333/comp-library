#pragma once

#include "src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp"
#include "src/data-structure/segment-tree/presets/monoid/operator-structure-chmax.hpp"

namespace luz {

  template < typename T >
  using RangeChmaxQuerySolver =
      DualSegmentTree< monoid::RangeChmaxQueryMonoid< T > >;

} // namespace luz
