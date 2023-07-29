// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-minimum-query-solver.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    RangeMinimumQuerySolver< i32 > seg(n);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com, x, y;
      std::cin >> com >> x >> y;

      if (not com) {
        seg.set(x, y);
      } else {
        std::cout << seg.fold(x, y + 1) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
