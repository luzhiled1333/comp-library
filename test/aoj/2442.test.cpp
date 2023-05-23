// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2442
// verification-helper: ERROR 0.00000001

#include "src/cpp-template/header/io-set.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/geometry/Z2/centroid/gravity.hpp"
#include "src/geometry/Z2/class/point.hpp"
#include "src/geometry/Z2/utility/multiply-for-all-points.hpp"

#include <iostream>

namespace luz {

  void main_() {
    using Z = i32;

    usize n;
    std::cin >> n;

    if (n & 1) {
      std::cout << "NA" << std::endl;
      return;
    }

    Z2::Points< Z > pts(n);
    for (auto &point: pts) {
      Z x, y;
      std::cin >> x >> y;
      point = {x, y};
    }

    Z2::Point< Z > g = ntimes_gravity(pts);
    pts              = multiply_for_all_points((Z)n, pts);

    n /= 2;
    for (usize i: rep(0, n)) {
      if (pts[i] - g == g - pts[i + n]) continue;

      std::cout << "NA" << std::endl;
      return;
    }

    io_set(5);
    std::cout << (double)g.x() / (2 * n) << " "
              << (double)g.y() / (2 * n) << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
