#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template< class T >
  class addD {
    T identity_{};

   public:
    using value_type = T;

    T operation(T a, T b) { return a + b; }
    T identity() { return identity_; }
  };

  template< class M >
  class SegmentTreeD {
    using T = typename M::value_type;

    M monoid;
    std::vector< T > tree;

   public:
    SegmentTreeD() = default;
    explicit SegmentTreeD(const usize n): tree(n * 2, monoid.identity()) {}

    usize size() const {
      return tree.size() / 2;
    }

    void update(usize index, const T x) {
      assert(index < size());
      index += size();
      tree[index] = x;

      while (index != 1) {
        index >>= 1;
        tree[index] = monoid.operation(tree[index << 1 | 0],
                                       tree[index << 1 | 1]);
      }
    }

    T fold(usize first, usize last) const {
      assert(first <= last);
      assert(last <= size());

      first += size();
      last += size();

      T fold_l = monoid.identity();
      T fold_r = monoid.identity();

      while (first != last) {
        if (first & 1) {
          fold_l = monoid.operation(fold_l, tree[first]);
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          fold_r = monoid.operation(tree[last], fold_r);
        }
        last >>= 1;
      }

      return monoid.operation(fold_l, fold_r);
    }

  };

  SegmentTreeD< addD<i32> > segment_tree_d(10);

}

