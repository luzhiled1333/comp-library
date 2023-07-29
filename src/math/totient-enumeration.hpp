#pragma once

#include "src/cpp-template/header/rep.hpp"

#include <cassert>
#include <limits>
#include <vector>

namespace luz {

  template < typename T >
  std::vector< T > totient_enumeration(T n) {
    static_assert(std::numeric_limits< T >::is_integer,
                  "T must be integer");
    assert(n >= 0);

    n += 1;
    std::vector< T > totients(n);
    for (T i: rep(0, n)) {
      totients[i] = i;
    }
    for (T i: rep(2, n)) {
      if (totients[i] != i) continue;
      for (T j = i; j < n; j += i) {
        totients[j] = totients[j] / i * (i - 1);
      }
    }
    return totients;
  }

} // namespace luz
