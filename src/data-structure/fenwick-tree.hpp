#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <vector>
#include <cassert>

namespace luz {
 
  template< typename T >
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
    
    void add(usize k, const T &v) {
      assert(0 <= k and k < n_);
      k++;
      while (k <= n_) {
        vals_[k] += v;
        k += k & -k;
      }
    }
 
    T sum(usize l, usize r) const {
      assert(0 <= l and l <= r and r <= n);
      return sum(r) - sum(l);
    }
 
  };
 
} // namespace luz
