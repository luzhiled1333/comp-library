// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-update-range-maximum-query-solver.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    RangeUpdateRangeMaximumQuerySolver< i32, 1 > seg(n,
                                                     -(1u << 31) + 1);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com;
      std::cin >> com;

      if (not com) {
        usize s, t;
        i32 x;
        std::cin >> s >> t >> x;

        seg.apply(s, t + 1, -x);
      } else {
        usize s, t;
        std::cin >> s >> t;

        std::cout << -seg.fold(s, t + 1) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
