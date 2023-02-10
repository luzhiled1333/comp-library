#pragma once

#include "src/utility/bit/popcount.hpp"

#include <cassert>

namespace luz {

  usize countl_zero(u64 x) {
    assert(__cplusplus <= 201703L);

    if (x == 0) {
      return 64;
    }

#ifdef __GNUC__
    return __builtin_clzll(x);
#endif

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return 64 - popcount(x);
  }

} // namespace luz
