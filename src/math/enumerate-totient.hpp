#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

namespace luz {

  template< typename T >
  std::vector< T > enumerate_totient(T n) {
    static_assert(std::numeric_limits< T >::is_integer,
                  "T must be integer");
    assert(n >= 0);
    std::vector< T > totient(n);
    for (u32 i: rep(0, n)) {
      totient[i] = i;
    }
    for (u32 i: rep(2, n)) {
      if (totient[i] == i) {
        for (u32 j = i; j < n; j += i) {
          totient[j] = totient[j] / i * (i - 1);
        }
      }
    }
    return totient;
  }

} // namespace luz
