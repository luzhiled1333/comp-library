#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/utility/bit/bit-width.hpp"
#include "src/utility/bit/count-trailing-0s.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < class operator_structure >
  class RangeMappingPointFoldSegmentTree {
    using O  = operator_structure;
    using OT = typename O::value_type;

    std::vector< OT > tree;

    void evaluate_lazy(OT &x, const OT &y) {
      x = O::operation(x, y);
    }

    void propagate(const usize index) {
      evaluate_lazy(tree[index << 1 | 0], tree[index]);
      evaluate_lazy(tree[index << 1 | 1], tree[index]);
      tree[index] = O::identity();
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
    using value_type = OT;

    RangeMappingPointFoldSegmentTree() = default;

    explicit RangeMappingPointFoldSegmentTree(const usize n)
        : tree(n * 2, O::identity()) {}

    explicit RangeMappingPointFoldSegmentTree(const usize n, OT v)
        : RangeMappingPointFoldSegmentTree(n) {
      build(std::vector< OT >(n, v));
    }

    explicit RangeMappingPointFoldSegmentTree(
        const std::vector< OT > &vs)
        : RangeMappingPointFoldSegmentTree(vs.size()) {
      build(vs);
    }

    void build(const std::vector< OT > &vs) {
      for (usize i: rep(0, vs.size())) {
        tree[i + size()] = vs[i];
      }
    }

    usize size() const {
      return tree.size() / 2;
    }

    void set(usize index, const OT x) {
      assert(index < size());
      index += size();

      const usize l = 1;
      const usize r = bit_width(index);
      for (usize i: rrep(l, r)) {
        propagate(index >> i);
      }

      tree[index] = x;
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

      while (first != last) {
        if (first & 1) {
          evaluate_lazy(tree[first], x);
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          evaluate_lazy(tree[last], x);
        }
        last >>= 1;
      }
    }

    OT fold(usize index) {
      assert(index < size());

      index += size();

      OT result = tree[index];
      while (index != 1) {
        index >>= 1;
        evaluate_lazy(result, tree[index]);
      }
      return result;
    }
  };

  template < class operator_structure >
  using DualSegmentTree =
      RangeMappingPointFoldSegmentTree< operator_structure >;

} // namespace luz
