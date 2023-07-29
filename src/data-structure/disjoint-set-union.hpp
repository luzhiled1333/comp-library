#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace luz {

  class DisjointSetUnion {
    usize n;

    // vals[v] :=
    //   if v is root node: -1 * component size
    //   otherwise: parent node
    std::vector< isize > vals;

    void bound_check(usize v) const {
      assert(v < n);
    }

    usize impl_leader(usize v) {
      if (vals[v] < 0) return v;
      return vals[v] = leader(vals[v]);
    }

   public:
    DisjointSetUnion() = default;
    explicit DisjointSetUnion(usize n): n(n), vals(n, -1) {}

    usize size() const {
      return n;
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
      if (-vals[x] < -vals[y]) std::swap(x, y);
      vals[x] += vals[y];
      vals[y] = x;
      return x;
    }

    usize group_size(usize v) {
      bound_check(v);
      return -vals[impl_leader(v)];
    }

    std::vector< std::vector< usize > > groups() {
      std::vector< std::vector< usize > > result(n);

      std::vector< usize > leaders(n), g_sizes(n);
      for (usize v: rep(0, n)) {
        leaders[v] = impl_leader(v);
        g_sizes[leaders[v]]++;
      }
      for (usize v: rep(0, n)) {
        result[v].reserve(g_sizes[v]);
      }
      for (usize v: rep(0, n)) {
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
