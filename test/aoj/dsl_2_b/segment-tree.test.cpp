// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-sum-query-solver.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    RangeSumQuerySolver< u32 > seg(n);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com, x, y;
      std::cin >> com >> x >> y;

      if (not com) {
        seg.set(x - 1, y + seg.fold(x - 1));
      } else {
        std::cout << seg.fold(x - 1, y) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
