#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/utility/bit/popcount.hpp"

#include <cassert>

namespace luz {

  usize bit_width(u64 x) {
    assert(__cplusplus <= 201703L);

    if (x == 0) {
      return 0;
    }

#ifdef __GNUC__
    return 64 - __builtin_clzll(x);
#endif

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return popcount(x);
  }

} // namespace luz
