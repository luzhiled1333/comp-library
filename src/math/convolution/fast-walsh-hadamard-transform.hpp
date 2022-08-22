#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz::impl {

  template< typename T, typename F >
  void impl_fwht(std::vector< T > &f, F op) {
    const usize n = f.size();
    assert((n & (n - 1)) == 0);
    usize i = 1;
    while (i < n) {
      usize j = 0;
      while (j < n) {
        for (usize k: rep(0, i)) {
          op(f[j + k], f[j + k + i]);
        }
        i <<= 1;
      }
    }
  }

} // namespace luz::impl

namespace luz {

  template < typename T, typename F >
  void fast_walsh_hadamard_transform(std::vector< T > &f, F op) {
    impl::impl_fwht(f, op);
  }

} // namespace luz
