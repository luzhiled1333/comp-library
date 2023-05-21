#pragma once

#include "src/math/modular-arithmetic/modular-combinatorics.hpp"

namespace luz {

  template < typename modint >
  class SmallModCombination {
    static constexpr u32 mod = modint::get_mod();
    Combinatorics< modint > mc;

   public:
    SmallModCombination(): mc(mod - 1) {}

    modint combination(isize n, isize r) {
      if (r < 0 or n < r) return 0;

      modint result(1);
      while (n) {
        result *= mc.combination(n % mod, r % mod);
        n /= mod;
        r /= mod;
      }

      return result;
    }

    modint C(isize n, isize r) {
      return combination(n, r);
    }
  };

} // namespace luz
