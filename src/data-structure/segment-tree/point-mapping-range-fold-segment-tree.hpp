#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < class M >
  class PointMappingRangeFoldSegmentTree {
    using T = typename M::value_type;

    std::vector< T > tree;

   public:
    using value_type = T;

    PointMappingRangeFoldSegmentTree() = default;
    explicit PointMappingRangeFoldSegmentTree(const usize n)
        : tree(n * 2, M::identity()) {}

    usize size() const {
      return tree.size() / 2;
    }

    void update(usize index, const T x) {
      assert(index < size());
      index += size();
      tree[index] = x;

      while (index != 1) {
        index >>= 1;
        tree[index] =
            M::operation(tree[index << 1 | 0], tree[index << 1 | 1]);
      }
    }

    T fold(usize first, usize last) const {
      assert(first <= last);
      assert(last <= size());

      first += size();
      last += size();

      T fold_l = M::identity();
      T fold_r = M::identity();

      while (first != last) {
        if (first & 1) {
          fold_l = M::operation(fold_l, tree[first]);
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          fold_r = M::operation(tree[last], fold_r);
        }
        last >>= 1;
      }

      return M::operation(fold_l, fold_r);
    }
  };

} // namespace luz
