#pragma once

#include "src/cpp-template/header/int-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  std::vector< u64 > prime_factor(u64 n) {
    assert(n != 0);

    std::vector< u64 > ps;

    for (u64 p = 2; p * p <= n; p++) {
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
