#pragma once

#include "src/math/modular-arithmetic/modular-combinatorics.hpp"

namespace luz {

  template < typename modint >
  class SmallModCombination {
    static constexpr u32 mod = modint::get_mod();
    Combinatorics< modint > mc;

   public:
    SmallModCombination(): mc(mod - 1) {}

    modint combination(usize n, usize k) {
      modint result = 1;
      while (n) {
        result *= mc.combination(n % mod, k % mod);
        n /= mod;
        k /= mod;
      }

      return result;
    }
  };

} // namespace luz
