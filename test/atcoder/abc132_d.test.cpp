// verification-helper: PROBLEM https://atcoder.jp/contests/abc132/tasks/abc132_d

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/math/modular-arithmetic/modular-combinatorics.hpp"
#include "src/math/modular-arithmetic/static-modint.hpp"

#include <iostream>

namespace luz {

  void main_() {
    i32 n, k;
    std::cin >> n >> k;

    using mint = modint1000000007;
    Combinatorics< mint > cb;

    for (i32 i: rep(1, k + 1)) {
      i32 t = n - k - (i - 1);
      std::cout << (cb.combination_with_repetitions(i + 1, t) *
                    cb.combination_with_repetitions(i, k - i))
                       .val()
                << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
