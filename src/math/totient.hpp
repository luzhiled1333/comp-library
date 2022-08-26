#pragma once

#include "src/cpp-template/header/type-alias.hpp"

namespace luz {

  u64 totient(u64 n) {
    u64 t = n, p = 2;
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
