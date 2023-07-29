#pragma once

#include "src/cpp-template/header/size-alias.hpp"
#include "src/data-structure/segment-tree/presets/monoid/operator-structure-add.hpp"
#include "src/data-structure/segment-tree/presets/monoid/value-structure-sum.hpp"

namespace luz::monoid {

  template < typename T >
  class RangeAddRangeSumQueryMonoid {

    class node_type {
      using F = node_type;

     public:
      T value;
      usize count;

      node_type(): value(), count() {}
      node_type(T v, usize c): value(v), count(c) {}

      F operator+(const F &b) {
        return F(value + b.value, count + b.count);
      }
    };

    using V  = RangeSumQueryMonoid< node_type >;
    using VT = typename V::value_type;
    using O  = RangeAddQueryMonoid< T >;
    using OT = typename O::value_type;

   public:
    using value_structure    = V;
    using operator_structure = O;

    static constexpr VT operation(VT a, OT b) {
      return VT(a.value + b * a.count, a.count);
    }
  };

} // namespace luz::monoid
