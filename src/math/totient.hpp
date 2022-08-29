#pragma once

#include "src/cpp-template/header/type-alias.hpp"

namespace luz {

  template < typename T >
  T totient(T n) {
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
