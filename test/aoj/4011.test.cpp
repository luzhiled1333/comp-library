// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/4011

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/geometry/Z2/class/point.hpp"
#include "src/geometry/Z2/class/polygon.hpp"
#include "src/geometry/Z2/class/segment.hpp"
#include "src/geometry/Z2/compare/compare-yx.hpp"
#include "src/geometry/Z2/segment-function/counterbalance-segments.hpp"
#include "src/geometry/Z2/utility/polygon-to-segments.hpp"

#include <iostream>
#include <map>
#include <vector>

namespace luz {

  void main_() {
    usize n;
    std::cin >> n;

    using Z = i64;
    Z2::Segments< Z > segs;
    for ([[maybe_unused]] usize _: rep(0, n)) {
      Z2::Polygon< Z > triangle(3);
      for (usize i: rep(0, 3)) {
        Z x, y;
        std::cin >> x >> y;
        triangle[i] = Z2::Point< Z >(x, y);
      }

      auto edges = polygon_to_segments(triangle);
      for (auto &edge: edges) segs.emplace_back(edge);
    }

    auto edges = counterbalance_segments(segs);

    using Point = Z2::Point< Z >;
    std::map< Point, Point, Z2::CompareYX< Z > > mp;
    constexpr Z inf = 1e9 + 5;
    Point pt(inf, inf);

    for (auto &edge: edges) {
      Point from = edge.p0();
      Point to   = edge.p1();

      mp[from] = to;

      Z2::CompareYX< Z > comp;
      if (comp(from, pt)) pt = from;
    }

    for ([[maybe_unused]] usize _: rep(0, edges.size())) {
      std::cout << pt.x() << " " << pt.y() << std::endl;
      pt = mp[pt];
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
