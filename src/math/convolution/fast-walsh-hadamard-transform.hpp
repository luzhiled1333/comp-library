#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < typename T, typename F >
  void fast_walsh_hadamard_transform(std::vector< T > &f, F op) {
    const usize n = f.size();
    assert((n & (n - 1)) == 0);
    usize i = 1;
    while (i < n) {
      usize j = 0;
      while (j < n) {
        for (usize k: rep(0, i)) {
          op(f[j + k], f[j + k + i]);
        }
        j += i << 1;
      }
      i <<= 1;
    }
  }

} // namespace luz
