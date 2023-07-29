#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < typename T >
  class FenwickTree {
    usize n_;
    std::vector< T > vals_;

    T sum(usize k) const {
      T result(0);
      while (k > 0) {
        result += vals_[k];
        k -= k & -k;
      }
      return result;
    }

   public:
    FenwickTree() = default;

    explicit FenwickTree(usize n): n_(n), vals_(n + 1, T()) {}

    explicit FenwickTree(const std::vector< T > &as)
        : n_(as.size()),
          vals_(as.size() + 1, T()) {
      for (usize i: rep(1, as.size() + 1)) {
        vals_[i] = as[i - 1];
      }
      for (usize i: rep(1, as.size() + 1)) {
        usize j = i + (i & -i);
        if (j <= as.size()) {
          vals_[j] += vals_[i];
        }
      }
    }

    void add(usize k, const T &v) {
      assert(k < n_);
      k++;
      while (k <= n_) {
        vals_[k] += v;
        k += k & -k;
      }
    }

    T sum(usize l, usize r) const {
      assert(l <= r and r <= n_);
      return sum(r) - sum(l);
    }
  };

} // namespace luz
