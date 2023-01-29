// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp"

#include <iostream>
#include <limits>

namespace luz {

  template < typename T >
  class Monoid {
    static constexpr T identity_{std::numeric_limits< T >::max()};

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return std::min(a, b);
    }

    static constexpr T identity() {
      return identity_;
    }
  };

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    PointMappingRangeFoldSegmentTree< Monoid< i32 > > seg(n);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com, x, y;
      std::cin >> com >> x >> y;

      if (not com) {
        seg.update(x, y);
      } else {
        std::cout << seg.fold(x, y + 1) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
