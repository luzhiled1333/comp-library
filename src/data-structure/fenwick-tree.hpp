#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < typename T >
  class FenwickTree {
    usize n;
    std::vector< T > vals;

    T sum(usize k) const {
      T result(0);
      while (k > 0) {
        result += vals[k];
        k -= k & -k;
      }
      return result;
    }

   public:
    FenwickTree() = default;

    explicit FenwickTree(usize n): n(n), vals(n + 1, T()) {}

    explicit FenwickTree(const std::vector< T > &as)
        : n(as.size()),
          vals(as.size() + 1, T()) {
      for (usize i: rep(1, as.size() + 1)) {
        vals[i] = as[i - 1];
      }
      for (usize i: rep(1, as.size() + 1)) {
        usize j = i + (i & -i);
        if (j <= as.size()) {
          vals[j] += vals[i];
        }
      }
    }

    void add(usize k, const T &v) {
      assert(k < n);
      k++;
      while (k <= n) {
        vals[k] += v;
        k += k & -k;
      }
    }

    T sum(usize l, usize r) const {
      assert(l <= r and r <= n);
      return sum(r) - sum(l);
    }
  };

} // namespace luz
