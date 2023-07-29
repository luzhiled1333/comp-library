#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <cassert>

namespace luz {

  usize popcount(u64 x) {
    assert(__cplusplus <= 201703L);

#ifdef __GNUC__
    return __builtin_popcountll(x);
#endif

    x -= (x >> 1) & 0x5555555555555555;
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;
    return x * 0x0101010101010101 >> 56 & 0x7f;
  }

} // namespace luz
