#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

namespace luz {

  std::vector< u32 > enumerate_totient(u32 n) {
    std::vector< u32 > totient(n);
    for (u32 i: rep(0, n)) {
      totient[i] = i;
    }
    for (u32 i: rep(2, n)) {
      if (totient[i] == i) {
        for (u32 j = i; j < n; j += i) {
          totient[j] = totient[j] / i * (i - 1);
        }
      }
    }
    return totient;
  }

} // namespace luz
