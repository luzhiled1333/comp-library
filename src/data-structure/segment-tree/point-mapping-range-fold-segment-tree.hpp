#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < class value_structure >
  class PointMappingRangeFoldSegmentTree {
    using V  = value_structure;
    using VT = typename V::value_type;

    std::vector< VT > tree;

    void evaluate(usize index) {
      tree[index] =
          V::operation(tree[index << 1 | 0], tree[index << 1 | 1]);
    }

   public:
    using value_type = VT;

    PointMappingRangeFoldSegmentTree() = default;
    explicit PointMappingRangeFoldSegmentTree(const usize n)
        : tree(n * 2, V::identity()) {}
    explicit PointMappingRangeFoldSegmentTree(
        const std::vector< VT > &vs)
        : PointMappingRangeFoldSegmentTree(vs.size()) {
      build(vs);
    }

    void build(const std::vector< VT > &vs) {
      usize n = vs.size();
      assert(2 * n == tree.size());
      std::copy(vs.begin(), vs.end(), tree.begin() + n);
      for (usize index: rrep(1, n)) {
        evaluate(index);
      }
    }

    usize size() const {
      return tree.size() / 2;
    }

    void set(usize index, const VT x) {
      assert(index < size());
      index += size();
      tree[index] = x;

      while (index != 1) {
        index >>= 1;
        evaluate(index);
      }
    }

    VT fold(usize index) const {
      assert(index < size());

      return tree[index + size()];
    }

    VT fold(usize first, usize last) const {
      assert(first <= last);
      assert(last <= size());

      first += size();
      last += size();

      VT fold_l = V::identity();
      VT fold_r = V::identity();

      while (first != last) {
        if (first & 1) {
          fold_l = V::operation(fold_l, tree[first]);
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          fold_r = V::operation(tree[last], fold_r);
        }
        last >>= 1;
      }

      return V::operation(fold_l, fold_r);
    }

    VT fold_all() const {
      return (size() ? tree[1] : V::identity());
    }
  };

  template < class value_structure >
  using SegmentTree =
      PointMappingRangeFoldSegmentTree< value_structure >;

} // namespace luz
