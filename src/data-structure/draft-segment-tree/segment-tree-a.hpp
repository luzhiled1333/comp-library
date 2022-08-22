#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <functional>
#include <vector>

namespace luz {

  template < class T >
  class SegmentTreeA {
    std::vector< T > tree;
    std::function< T(T, T) > operation_;
    T identity_;

   public:
    SegmentTreeA() = default;
    explicit SegmentTreeA(const usize n, T identity,
                          std::function< T(T, T) > operation)
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

  i32 addA(i32 a, i32 b) {
    return a + b;
  }
  std::function< i32(i32, i32) > f = addA;
  SegmentTreeA segment_tree_a(10, 0, f);

} // namespace luz
