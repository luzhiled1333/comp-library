#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < class T, class F >
  class SegmentTreeB {
    std::vector< T > tree;
    F operation_;
    T identity_;

   public:
    SegmentTreeB() = default;
    explicit SegmentTreeB(const usize n, T identity, F operation)
        : tree(n * 2, identity),
          identity_(identity),
          operation_(operation) {}

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
            operation_(tree[index << 1 | 0], tree[index << 1 | 1]);
      }
    }

    T fold(usize first, usize last) const {
      assert(first <= last);
      assert(last <= size());

      first += size();
      last += size();

      T fold_l = identity_;
      T fold_r = identity_;
      while (first != last) {
        if (first & 1) {
          fold_l = operation_(fold_l, tree[first]);
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          fold_r = operation_(tree[last], fold_r);
        }
        last >>= 1;
      }

      return operation_(fold_l, fold_r);
    }
  };

  SegmentTreeB segment_tree_b(10, 0,
                              [](i32 a, i32 b) { return a + b; });

} // namespace luz
