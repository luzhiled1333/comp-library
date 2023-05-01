// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp"

#include <iostream>
#include <limits>
#include <vector>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    RangeAddRangeSumQuerySolver< i64 > seg(n, {0, 1});
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com;
      std::cin >> com;

      if (not com) {
        usize s, t;
        i32 x;
        std::cin >> s >> t >> x;

        seg.apply(s - 1, t, x);
      } else {
        usize s, t;
        std::cin >> s >> t;

        std::cout << seg.fold(s - 1, t).value << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
