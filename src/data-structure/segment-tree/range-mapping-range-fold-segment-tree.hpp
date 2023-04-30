#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/utility/bit/bit-width.hpp"
#include "src/utility/bit/count-trailing-0s.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < class combined_structure >
  class RangeMappingRangeFoldSegmentTree {
    using C  = combined_structure;
    using V  = typename C::value_structure;
    using VT = typename V::value_type;
    using O  = typename C::operator_structure;
    using OT = typename O::value_type;

    class node_type {
     public:
      VT value;
      OT lazy;

      node_type(const VT value_, const OT lazy_)
          : value(value_),
            lazy(lazy_) {}

      VT get() {
        return C::operation(value, lazy);
      }
    };

    std::vector< node_type > tree;

    void evaluate_lazy(OT &x, const OT &y) {
      x = O::operation(x, y);
    }

    void recalc(usize index) {
      tree[index].value = V::operation(tree[index << 1 | 0].get(),
                                       tree[index << 1 | 1].get());
    }

    void recalc_bound(usize index) {
      if (index == 0) return;

      const usize l = countr_zero(index) + 1;
      const usize r = bit_width(index);
      for (usize i: rep(l, r)) {
        recalc(index >> i);
      }
    }

    void propagate(const usize index) {
      evaluate_lazy(tree[index << 1 | 0].lazy, tree[index].lazy);
      evaluate_lazy(tree[index << 1 | 1].lazy, tree[index].lazy);
      tree[index].lazy = O::identity();
    }

    void propagate_bound(const usize index) {
      if (index == 0) return;

      const usize l = countr_zero(index) + 1;
      const usize r = bit_width(index);
      for (usize i: rrep(l, r)) {
        propagate(index >> i);
      }
    }

   public:
    using value_type = VT;

    RangeMappingRangeFoldSegmentTree() = default;
    explicit RangeMappingRangeFoldSegmentTree(const usize n)
        : tree(n * 2, node_type(V::identity(), O::identity())) {}
    explicit RangeMappingRangeFoldSegmentTree(
        const std::vector< VT > &vs)
        : RangeMappingRangeFoldSegmentTree(vs.size()) {
      build(vs);
    }

    void build(const std::vector< VT > &vs) {
      usize n = vs.size();
      assert(2 * n == tree.size());
      for (usize i: rep(0, n)) {
        tree[i + n] = node_type(vs[i], O::identity());
      }
      for (usize index: rrep(1, n)) {
        recalc(index);
      }
    }

    usize size() const {
      return tree.size() / 2;
    }

    void set(usize index, const VT x) {
      assert(index < size());
      index += size();

      const usize l = 1;
      const usize r = bit_width(index);
      for (usize i: rrep(l, r)) {
        propagate(index >> i);
      }

      tree[index] = node_type(x, O::identity());

      for (usize i: rep(l, r)) {
        recalc(index >> i);
      }
    }

    void apply(usize index, const OT &x) {
      return apply(index, index + 1, x);
    }

    void apply(usize first, usize last, const OT &x) {
      assert(first <= last);
      assert(last <= size());

      first += size();
      last += size();

      propagate_bound(first);
      propagate_bound(last);

      const usize c_first = first;
      const usize c_last  = last;

      while (first != last) {
        if (first & 1) {
          evaluate_lazy(tree[first].lazy, x);
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          evaluate_lazy(tree[last].lazy, x);
        }
        last >>= 1;
      }

      recalc_bound(c_first);
      recalc_bound(c_last);
    }

    VT fold(usize index) {
      return fold(index, index + 1);
    }

    VT fold(usize first, usize last) {
      assert(first <= last);
      assert(last <= size());

      first += size();
      last += size();

      propagate_bound(first);
      recalc_bound(first);
      propagate_bound(last);
      recalc_bound(last);

      VT fold_l = V::identity();
      VT fold_r = V::identity();

      while (first != last) {
        if (first & 1) {
          fold_l = V::operation(fold_l, tree[first].get());
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          fold_r = V::operation(tree[last].get(), fold_r);
        }
        last >>= 1;
      }

      return V::operation(fold_l, fold_r);
    }

    VT fold_all() {
      return (size() ? tree[1] : V::identity());
    }
  };

  template < class combined_structure >
  using LazySegmentTree =
      RangeMappingRangeFoldSegmentTree< combined_structure >;

} // namespace luz
