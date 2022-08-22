#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>
#include <functional>

namespace luz {

  template< class T >
  class SegmentTreeA {
    std::vector< T > tree;
    std::function< T(T, T) > operation_;
    T identity_;

   public:
    SegmentTreeA() = default;
    explicit SegmentTreeA(const usize n, T identity, std::function< T(T, T) > operation):
      tree(n * 2, identity), identity_(identity), operation_(operation) {}

    usize size() const {
      return tree.size() / 2;
    }

    void update(usize index, const T x) {
      assert(index < size());
      index += size();
      tree[index] = x;

      while (index != 1) {
        index >>= 1;
        tree[index] = operation_(tree[index << 1 | 0], tree[index << 1 | 1]);
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

  i32 addA(i32 a, i32 b) { return a + b; }
  std::function< i32(i32, i32) > f = addA;
  SegmentTreeA segment_tree_a(10, 0, f);

}

namespace luz {

  template< class T, class F >
  class SegmentTreeB {
    std::vector< T > tree;
    F operation_;
    T identity_;

   public:
    SegmentTreeB() = default;
    explicit SegmentTreeB(const usize n, T identity, F operation):
      tree(n * 2, identity), identity_(identity), operation_(operation) {}

    usize size() const {
      return tree.size() / 2;
    }

    void update(usize index, const T x) {
      assert(index < size());
      index += size();
      tree[index] = x;

      while (index != 1) {
        index >>= 1;
        tree[index] = operation_(tree[index << 1 | 0], tree[index << 1 | 1]);
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

  SegmentTreeB segment_tree_b(10, 0, [](i32 a, i32 b) { return a + b; });

}

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

namespace luz {

  template< typename T >
  class addE {
    static constexpr T identity_{};

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) { return a + b; }
    static constexpr T identity() { return identity_; };
  };

  template< class M >
  class SegmentTreeE {
    using T = typename M::value_type;

    std::vector< T > tree;

   public:
    using value_type = T;

    SegmentTreeE() = default;
    explicit SegmentTreeE(const usize n): tree(n * 2, M::identity()) {}
    
    usize size() const {
      return tree.size() / 2;
    }

    void update(usize index, const T x) {
      assert(index < size());
      index += size();
      tree[index] = x;

      while (index != 1) {
        index >>= 1;
        tree[index] = M::operation(tree[index << 1 | 0],
                                   tree[index << 1 | 1]);
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

  SegmentTreeE< addE<i32> > segment_tree_e(10);
}

