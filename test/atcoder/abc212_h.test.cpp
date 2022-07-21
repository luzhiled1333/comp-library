// verification-helper: PROBLEM https://atcoder.jp/contests/abc212/tasks/abc212_h

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/input.hpp"

#include "src/math/convolution/fast-walsh-hadamard-transform.hpp"
#include "src/math/modular-arithmetic/static-modint.hpp"

// TODO: replace #11
namespace luz {

  template< typename T >
  T sum_of_geometric_sequence(const T &a_0, const T &r, const usize &n) {
    if (r == T(1)) return a_0 * n;
    return a_0 * (r.pow(n) - 1) / (r - 1);
  }

} // namespace luz

#include <iostream>
#include <vector>
#include <numeric>

namespace luz {

  void main_() {
    usize n = input(), k = input();

    using mint = modint998244353;
    std::vector< mint > cs(1 << 16);
    for ([[maybe_unused]] usize _: rep(0, k)) {
      cs[input()] = 1;
    }

    fast_walsh_hadamard_transform(cs);
    for (mint &c: cs) {
      c = sum_of_geometric_sequence(c, c, n);
    }
    fast_walsh_hadamard_inverse_transform(cs);

    std::cout << (std::accumulate(cs.begin(), cs.end(), mint()) - cs[0]).val() << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}

