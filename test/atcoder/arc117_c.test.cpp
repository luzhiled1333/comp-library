// verification-helper: PROBLEM https://atcoder.jp/contests/arc117/tasks/arc117_c

#include "src/math/modular-arithmetic/small-mod-combination.hpp"
#include "src/math/modular-arithmetic/static-modint.hpp"

#include <iostream>
#include <string>

namespace luz {

  void main_() {
    using mint = StaticPrimeModInt< 3 >;
    SmallModCombination< mint > mc;

    usize n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    auto convert = [](char c) {
      switch (c) {
        case 'B':
          return 0;
        case 'W':
          return 1;
        case 'R':
          return 2;
        default:
          exit(-1);
      }
    };

    mint sum;
    for (usize i = 0; i < n; i++) {
      sum +=
          (n & 1 ? 1 : -1) * convert(s[i]) * mc.combination(n - 1, i);
    }

    auto inverse = [](mint x) {
      switch (x.val()) {
        case 0:
          return 'B';
        case 1:
          return 'W';
        case 2:
          return 'R';
        default:
          exit(-1);
      }
    };

    std::cout << inverse(sum) << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
