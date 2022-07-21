#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"

#include <cassert>
#include <vector>

namespace luz {
 
  template< typename T >
  void impl_fwht(std::vector< T > &f, bool is_inverse_transform) {
    const usize n = f.size();
    assert((n & (n - 1)) == 0);
    usize i = 1;
    while (i < n) {
      usize j = 0;
      while (j < n) {
        for (usize k: rep(0, i)) {
          T s = f[j + k], t = f[j + k + i];
          f[j + k    ] = s + t;
          f[j + k + i] = s - t;
        }
 
        j += (i << 1);
      }
 
      i = i << 1;
    }
 
    if (not is_inverse_transform) return;
 
    T n_inv = T(1) / T(n);
    for (auto &x: f) x *= n_inv;
  }
 
  template< typename T >
  void fast_walsh_hadamard_transform(std::vector< T > &f) {
    impl_fwht(f, false);
  }
 
  template< typename T >
  void fast_walsh_hadamard_inverse_transform(std::vector< T > &f) {
    impl_fwht(f, true);
  }
 
} // namespace luz
