// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    RangeUpdateRangeSumQuerySolver< i64, -1001 > seg(n, {0, 1});
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com;
      std::cin >> com;

      if (not com) {
        usize s, t;
        i32 x;
        std::cin >> s >> t >> x;

        seg.apply(s, t + 1, x);
      } else {
        usize s, t;
        std::cin >> s >> t;

        std::cout << seg.fold(s, t + 1).value << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
