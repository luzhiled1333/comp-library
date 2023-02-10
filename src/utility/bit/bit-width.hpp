#pragma once

#include "src/utility/bit/popcount.hpp"

#include <cassert>

namespace luz {

  usize bit_width(u64 x) {
    assert(__cplusplus <= 201703L);

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return popcount(x);
  }

} // namespace luz
