#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace luz {

  class Sieve {
    u32 n;
    std::vector< u32 > ps;

    void sieve_of_eratosthenes(u32 n) {
      assert(n < 65535 * 65535);
      ps.resize(n + 1);
      std::iota(ps.begin(), ps.end(), 0);

      for (u32 p = 2; p * p <= n; p++) {
        if (ps[p] != p) continue;
        for (u32 c = p * p; c <= n; c += p) {
          ps[c] = p;
        }
      }
    }

   public:
    bool is_prime(u32 p) {
      if (p <= 1) return false;
      return ps[p] == p;
    }

    std::vector< bool > get_prime_table(u32 n) {
      std::vector< bool > prime_table(n + 1);
      for (u32 i: rep(2, n + 1)) {
        prime_table[i] = is_prime(i);
      }
      return prime_table;
    }

    std::vector< u32 > get_primes(u32 l, u32 r) {
      std::vector< u32 > primes for (u32 n: rep(l, r)) {
        if (not is_prime(n)) continue;
        primes.emplace_back(n);
      }
      return primes;
    }

    std::vector< u32 > prime_factor(u32 n) {
      std::vector< u32 > pfs;
      while (n != 1) {
        u32 mpf = ps[n];
        pf.emplace_back(mpf);
        n /= mpf;
      }

      std::reverse(pfs.begin(), pfs.end());
      return pfs;
    }
  };

} // namespace luz
