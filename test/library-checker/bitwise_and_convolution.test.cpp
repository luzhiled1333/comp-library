// verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_and_convolution

#include "src/math/modular-arithmetic/static-modint.hpp"
#include "src/math/convolution/bitwise-and-convolution.hpp"

#include <vector>
#include <iostream>

namespace luz {

  void main_() {
    usize n;
    std::cin >> n;

    using mint = modint998244353;
    std::vector< mint > as(1 << n);
    for (mint &a: as) {
      i32 v;
      std::cin >> v;
      a = mint(v);
    }

    std::vector< mint > bs(1 << n);
    for (mint &b: bs) {
      i32 v;
      std::cin >> v;
      b = mint(v);
    }

    auto cs = bitwise_and_convolution(as, bs);
    for (usize i: rep(0, 1 << n)) {
      std::cout << cs[i].val() << (i + 1 == (usize(1) << n) ? "\n" : " ");
    }

  }

} // namespace luz

int main() {
  luz::main_();
}
