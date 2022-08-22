#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template< class T >
  class addC {
    T identity_{};
    T val_;

   public:
    using value_type = T;

    addC(): val_(identity_) {}
    addC(T val): val_(val) {}

    addC operator+(addC r) { return addC(val_ + r.val_); }

    T val() { return val_; }
  };

  template< class M >
  class SegmentTreeC {
    using T = typename M::value_type;

    std::vector< M > tree;

   public:
    SegmentTreeC() = default;
    explicit SegmentTreeC(const usize n): tree(n * 2) {}

    usize size() const {
      return tree.size() / 2;
    }

    void update(usize index, const T x) {
      assert(index < size());
      index += size();
      tree[index] = M(x);

      while (index != 1) {
        index >>= 1;
        tree[index] = tree[index << 1 | 0] + tree[index << 1 | 1];
      }
    }

    M fold(usize first, usize last) const {
      assert(first <= last);
      assert(last <= size());

      first += size();
      last += size();

      M fold_l, fold_r;
      while (first != last) {
        if (first & 1) {
          fold_l = fold_l + tree[first];
          first += 1;
        }
        first >>= 1;

        if (last & 1) {
          last -= 1;
          fold_r = tree[last] + fold_r;
        }
        last >>= 1;
      }

      return fold_l + fold_r;
    }

  };

  SegmentTreeC< addC<i32> > segment_tree_c(10);

}

