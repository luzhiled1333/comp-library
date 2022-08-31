// verification-helper: PROBLEM https://atcoder.jp/contests/abc212/tasks/abc212_h

#include "src/cpp-template/header/input.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/math/convolution/fast-walsh-hadamard-transform.hpp"
#include "src/math/modular-arithmetic/static-modint.hpp"

// TODO: replace #11
namespace luz {

  template < typename T >
  T sum_of_geometric_sequence(const T& a_0, const T& r,
                              const usize& n) {
    if (r == T(1)) return a_0 * n;
    return a_0 * (r.pow(n) - 1) / (r - 1);
  }

} // namespace luz

#include <iostream>
#include <numeric>
#include <vector>

namespace luz {

  void main_() {
    usize n = input(), k = input();

    using mint = modint998244353;
    std::vector< mint > cs(1 << 16);
    for ([[maybe_unused]] usize _: rep(0, k)) {
      cs[input()] = 1;
    }

    mint inv2 = mint(1) / mint(2);
    auto zeta = [](mint& lo, mint& hi) {
      mint x = lo + hi;
      mint y = lo - hi;
      lo     = x;
      hi     = y;
    };
    auto mobius = [inv2](mint& lo, mint& hi) {
      mint x = lo + hi;
      mint y = lo - hi;
      lo     = x * inv2;
      hi     = y * inv2;
    };
    fast_walsh_hadamard_transform(cs, zeta);
    for (mint& c: cs) {
      c = sum_of_geometric_sequence(c, c, n);
    }
    fast_walsh_hadamard_transform(cs, mobius);

    std::cout << (std::accumulate(cs.begin(), cs.end(), mint()) -
                  cs[0])
                     .val()
              << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
