// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp"

#include <iostream>
#include <limits>
#include <vector>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    using Tree = RangeUpdateRangeSumQuerySolver< i64, -1001 >;
    using F = Tree::value_type;
    std::vector< F > init(n, {0, 1});
    Tree seg(init);
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

      std::cerr << seg.fold_all().value << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
