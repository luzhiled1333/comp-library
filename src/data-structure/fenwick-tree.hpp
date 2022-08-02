#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

namespace luz {
 
  template< typename T >
  class FenwickTree {
    usize n_;
    std::vector< T > vals_;
 
    T sum(usize idx) const {
      T result(0);
      while (idx > 0) {
        result += vals_[idx];
        idx -= idx & -idx;
      }
      return result;
    }
 
   public:
    FenwickTree() = default;
    explicit FenwickTree(usize n): n_(n), vals_(n + 1, T()) {}
    
    void add(usize idx, const T &v) {
      idx++;
      while (idx <= n_) {
        vals_[idx] += v;
        idx += idx & -idx;
      }
    }
 
    T sum(usize l, usize r) const {
      return sum(r) - sum(l);
    }
 
  };
 
} // namespace luz
