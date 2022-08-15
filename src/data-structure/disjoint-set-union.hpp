#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace luz {

  class DisjointSetUnion {
    usize n_;

    // vals_[v] :=
    //   if v is root node: -1 * component size
    //   otherwise: parent node
    std::vector< isize > vals_;

    void bound_check(usize v) const {
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
      return n_;
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
      bound_check(u);
      bound_check(v);

      isize x = impl_leader(u);
      isize y = impl_leader(v);
      if (x == y) return x;
      if (-vals_[x] < -vals_[y]) std::swap(x, y);
      vals_[x] += vals_[y];
      vals_[y] = x;
      return x;
    }

    usize group_size(usize v) {
      bound_check(v);
      return -vals_[impl_leader(v)];
    }

    std::vector< std::vector< usize > > groups() {
      std::vector< std::vector< usize > > result(n_);

      std::vector< usize > leaders(n_), g_sizes(n_);
      for (usize v: rep(0, n_)) {
        leaders[v] = impl_leader(v);
        g_sizes[leaders[v]]++;
      }
      for (usize v: rep(0, n_)) {
        result[v].reserve(g_sizes[v]);
      }
      for (usize v: rep(0, n_)) {
        result[leaders[v]].emplace_back(v);
      }

      auto empty_check = [](const std::vector< usize > &vs) {
        return vs.empty();
      };
      result.erase(
          std::remove_if(result.begin(), result.end(), empty_check),
          result.end());

      return result;
    }
  };

} // namespace luz
