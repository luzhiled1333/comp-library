// verification-helper: PROBLEM https://atcoder.jp/contests/abc298/tasks/abc298_f

#include "src/cpp-template/header/change-max.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/data-structure/segment-tree/presets/range-maximum-query-solver.hpp"
#include "src/sequence/compression.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

namespace luz {

  void main_() {
    usize n;
    std::cin >> n;

    std::vector< usize > rs, cs;
    std::vector< i32 > xs(n);

    { // input and compression
      std::vector< u32 > as(n), bs(n);
      for (usize i: rep(0, n)) {
        std::cin >> as[i] >> bs[i] >> xs[i];
      }

      Compressor< u32 > r_cp(as), c_cp(bs);
      rs = r_cp.compressed_vector();
      cs = c_cp.compressed_vector();
    }

    std::vector< std::tuple< usize, usize, i32 > > qs(n);
    for (usize i: rep(0, n)) {
      qs[i] = {rs[i], cs[i], xs[i]};
    }

    std::sort(qs.begin(), qs.end());

    RangeMaximumQuerySolver< i64 > seg(n, 0);
    auto seg_add = [&](usize idx, i64 x) {
      seg.set(idx, seg.fold(idx) + x);
    };

    for (usize i: rep(0, n)) {
      seg_add(cs[i], xs[i]);
    }

    usize m = *max_element(rs.begin(), rs.end()) + 1;

    i64 ans   = 0;
    usize idx = 0;

    for (usize r: rep(0, m)) {
      usize prev_idx = idx;

      i64 max = 0;
      while (idx < qs.size() and std::get< 0 >(qs[idx]) == r) {
        i32 x = std::get< 2 >(qs[idx]);
        max += x;

        i32 c = std::get< 1 >(qs[idx]);
        seg_add(c, -x);

        idx++;
      }

      max += seg.fold_all();
      chmax(ans, max);

      for (usize i: rep(prev_idx, idx)) {
        auto [_, c, x] = qs[i];
        seg_add(c, x);
      }
    }

    std::cout << ans << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
