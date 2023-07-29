#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/utility/bit/popcount.hpp"

#include <cassert>

namespace luz {

  usize countr_zero(u64 x) {
    assert(__cplusplus <= 201703L);

    if (x == 0) {
      return 64;
    }

#ifdef __GNUC__
    return __builtin_ctzll(x);
#endif

    return popcount((x & -x) - 1);
  }

} // namespace luz
