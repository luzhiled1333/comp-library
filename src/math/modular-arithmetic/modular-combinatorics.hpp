#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

namespace luz {

  template < typename mint >
  class Combinatorics {
    static usize bound;
    static std::vector< mint > fact, finv, inv;

    static void expand(usize n) {
      n += 1;
      if (fact.size() >= n) return;

      if (bound == 0) bound = 1;

      fact.resize(n, mint(1));
      finv.resize(n, mint(1));
      inv.resize(n, mint(1));

      for (usize i: rep(bound, n)) {
        fact[i] = fact[i - 1] * i;
      }

      finv.back() = mint(1) / fact.back();
      for (usize i: rrep(bound, n)) {
        finv[i - 1] = finv[i] * i;
      }

      for (usize i: rep(bound, n)) {
        inv[i] = finv[i] * fact[i - 1];
      }

      bound = n;
    }

   public:
    explicit Combinatorics(usize n = 0) {
      expand(n);
    }

    static mint factorial(usize n) {
      expand(n);
      return fact[n];
    }

    static mint factorial_inverse(usize n) {
      expand(n);
      return finv[n];
    }

    static mint inverse(usize n) {
      expand(n);
      return inv[n];
    }

    static mint permutation(isize n, isize r) {
      if (r < 0 or n < r) return 0;

      expand(n);
      return fact[n] * finv[n - r];
    }

    static mint combination(isize n, isize r) {
      if (r < 0 or n < r) return 0;

      expand(n);
      return fact[n] * finv[r] * finv[n - r];
    }

    static mint combination_with_repetitions(isize n, isize r) {
      if (n < 0 or r < 0) return 0;
      return (r ? combination(n + r - 1, r) : 1);
    }
  };

  template < typename mint >
  usize Combinatorics< mint >::bound = 0;

  template < typename mint >
  std::vector< mint > Combinatorics< mint >::fact =
      std::vector< mint >();

  template < typename mint >
  std::vector< mint > Combinatorics< mint >::finv =
      std::vector< mint >();

  template < typename mint >
  std::vector< mint > Combinatorics< mint >::inv =
      std::vector< mint >();

} // namespace luz
