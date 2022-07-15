// verification-helper: PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_d

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"

#include "src/geometry/Z2-geometry/struct/point.hpp"
#include "src/geometry/Z2-geometry/struct/circle.hpp"
#include "src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp"
#include "src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp"

#include <iostream>
#include <atcoder/dsu>

namespace luz {

  void main_() {
    usize n;
    std::cin >> n;

    i64 sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    using namespace Z2;
    Point< i64 > s(sx, sy), t(tx, ty);

    Circles< i64 > cs;
    for (usize _: rep(0, n)) {
      i64 x, y, r;
      std::cin >> x >> y >> r;

      cs.emplace_back(Point<i64>(x, y), r);
    }

    atcoder::dsu uf(n + 2);
    usize s_idx = n, t_idx = n + 1;

    for (usize i: rep(0, n)) {
      if (is_intersect_pc(s, cs[i])) {
        uf.merge(s_idx, i);
      }
      if (is_intersect_pc(t, cs[i])) {
        uf.merge(i, t_idx);
      }
    }

    for (usize i: rep(0, n)) for (usize j: rep(0, i)) {
      if (is_intersect_cc(cs[i], cs[j])) {
        uf.merge(i, j);
      }
    }

    std::cout << (uf.same(s_idx, t_idx) ? "Yes" : "No") << std::endl;

  }

} // namespace luz

int main() {
  luz::main_();
}
