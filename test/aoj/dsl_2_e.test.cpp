// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-add-query-solver.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    RangeAddQuerySolver< i32 > seg(n);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com;
      std::cin >> com;

      if (not com) {
        usize s, t;
        i32 x;
        std::cin >> s >> t >> x;

        seg.apply(s - 1, t, x);
      } else {
        usize i;
        std::cin >> i;

        std::cout << seg.fold(i - 1) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
