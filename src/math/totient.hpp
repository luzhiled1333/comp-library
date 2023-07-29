#pragma once

#include <cassert>
#include <limits>

namespace luz {

  template < typename T >
  T totient(T n) {
    static_assert(std::numeric_limits< T >::is_integer,
                  "T must be integer");
    assert(n >= 0);
    T t = n, p = 2;
    while (p * p <= n) {
      if (n % p == 0) {
        t -= t / p;
        while (n % p == 0) {
          n /= p;
        }
      }
      p++;
    }
    if (n > 1) {
      t -= t / n;
    }
    return t;
  }

} // namespace luz
