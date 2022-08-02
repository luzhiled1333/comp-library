#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace luz {

  class DisjointSetUnion {
    usize n_;

    // vals_[v] :=
    // if v is root node: -1 * component size
    // otherwise: parent node
    std::vector< isize > vals_;

    void bound_check(usize v) {
      assert(v < n_);
    }

    usize impl_leader(usize v) {
      if (vals_[v] < 0) return v;
      return vals_[v] = leader(vals_[v]);
    }

   public:
    DisjointSetUnion() = default;
    explicit DisjointSetUnion(usize n): n_(n), vals_(n, -1) {}

    usize size() const {
      return vals_.size();
    }

    usize leader(usize v) {
      bound_check(v);
      return impl_leader(v);
    }

    bool same(usize u, usize v) {
      bound_check(u), bound_check(v);
      return impl_leader(u) == impl_leader(v);
    }

    usize merge(usize u, usize v) {
      bound_check(u); bound_check(v);

      isize x = impl_leader(u);
      isize y = impl_leader(v);
      if (x == y) return x;
      if (-vals_[x] < -vals_[y]) std::swap(x, y);
      vals_[x] += vals_[y];
      vals_[y] = x;
      return x;
    }

    usize group_size(usize v) const {
      bound_check(v);
      return -vals_[impl_leader(v)];
    }

  };

} // namespace luz
