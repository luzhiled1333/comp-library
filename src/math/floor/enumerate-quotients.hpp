#pragma once

#include "src/cpp-template/header/int-alias.hpp"

#include <algorithm>
#include <cassert>
#include <tuple>
#include <vector>

namespace luz {

  std::vector< std::tuple< u64, u64, u64 > > enumerate_quotients(
      u64 n) {
    assert(n >= 1);
    std::vector< std::tuple< u64, u64, u64 > > quotients;
    u64 upper = n;
    for (u64 quo = 1; upper * upper > n; quo++) {
      u64 lower = n / (quo + 1);
      quotients.emplace_back(quo, lower + 1, upper + 1);
      upper = lower;
    }
    while (upper > 0) {
      quotients.emplace_back(n / upper, upper, upper + 1);
      upper--;
    }
    return quotients;
  }

} // namespace luz
