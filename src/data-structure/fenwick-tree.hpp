#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

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
      k++;
      while (k <= n_) {
        vals_[k] += v;
        k += k & -k;
      }
    }
 
    T sum(usize l, usize r) const {
      return sum(r) - sum(l);
    }
 
  };
 
} // namespace luz
