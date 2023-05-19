// verification-helper: PROBLEM https://judge.yosupo.jp/problem/convolution_mod

#include "src/math/convolution/modint-convolution.hpp"
#include "src/math/modular-arithmetic/static-modint.hpp"

#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    usize n, m;
    std::cin >> n >> m;

    using mint = modint998244353;
    std::vector< mint > as(n);
    for (mint &a: as) {
      i32 v;
      std::cin >> v;
      a = mint(v);
    }

    std::vector< mint > bs(m);
    for (mint &b: bs) {
      i32 v;
      std::cin >> v;
      b = mint(v);
    }

    auto cs = modint_convolution(as, bs);
    for (usize i: rep(0, cs.size())) {
      std::cout << cs[i].val() << (i + 1 == cs.size() ? "\n" : " ");
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
