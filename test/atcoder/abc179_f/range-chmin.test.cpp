// verification-helper: PROBLEM https://atcoder.jp/contests/abc179/tasks/abc179_f

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-chmin-query-solver.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    RangeChminQuerySolver< i32 > v_seg(n, n - 1), h_seg(n, n - 1);

    u64 ans = u64(n - 2) * u64(n - 2);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize type, x;
      std::cin >> type >> x;

      x -= 1;

      if (type == 1) {
        usize idx = h_seg.fold(x);

        ans -= idx - 1;
        v_seg.apply(0, idx, x);
      } else {
        usize idx = v_seg.fold(x);

        ans -= idx - 1;
        h_seg.apply(0, idx, x);
      }
    }

    std::cout << ans << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
