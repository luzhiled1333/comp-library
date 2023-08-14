#pragma once

#include "src/cpp-template/header/int-alias.hpp"

#include <vector>

namespace luz {

  std::vector< u32 > prime_factor(u32 n) {
    assert(1 <= n and n <= 65535 * 65535);
    std::vector< u32 > ps;

    for (u32 p = 2; p * p <= n and n != 1; p++) {
      while (n % p == 0) {
        ps.emplace_back(p);
        n /= p;
      }
    }

    if (n != 1) {
      ps.emplace_back(n);
    }

    return ps;
  }

} // namespace luz
