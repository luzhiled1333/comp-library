// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/data-structure/segment-tree/point-mapping-range-fold-segment-tree.hpp"

#include "src/cpp-template/header/size-alias.hpp"
#include "src/cpp-template/header/int-alias.hpp"

#include <cassert>
#include <iostream>
#include <numeric>
#include <typeinfo>
#include <vector>

namespace luz {

  template < typename T >
  class Monoid {
    static constexpr T identity_{};

   public:
    using value_type = T;

    static constexpr T operation(T a, T b) {
      return a + b;
    }

    static constexpr T identity() {
      return identity_;
    }
  };

  constexpr usize small  = (usize)1 << 3;
  constexpr usize medium = (usize)1 << 8;
  constexpr usize large  = (usize)1 << 24;

  template < typename V >
  void unit_test(usize n) {
    std::vector< i32 > as(n);
    std::iota(as.begin(), as.end(), 0);

    std::cerr << "    constructor : " << std::flush;
    SegmentTree< V > seg(n);
    std::cerr << "done" << std::endl;

    std::cerr << "    build() : " << std::flush;
    seg.build(as);
    std::cerr << "done" << std::endl;

    std::cerr << "    size() : " << std::flush;
    assert(seg.size() == as.size());
    std::cerr << "done" << std::endl;

    std::cerr << "    fold(i), set(i, x) : " << std::flush;
    for (usize i: rep(0, n)) {
      assert(seg.fold(i) == as[i]);

      as[i] = n - i;
      seg.set(i, as[i]);
      assert(seg.fold(i) == as[i]);
    }
    std::cerr << "done" << std::endl;

    if (n <= medium + 1) {
      std::cerr << "    fold(l, r) : " << std::flush;
      for (usize l: rep(0, n))
        for (usize r: rep(l, n + 1)) {
          i32 sum = V::identity();
          for (usize i: rep(l, r)) {
            sum = V::operation(sum, as[i]);
          }
          assert(seg.fold(l, r) == sum);
        }
      std::cerr << "done" << std::endl;
    }

    std::cerr << "    fold_all() : " << std::flush;
    assert(seg.fold_all() == seg.fold(0, n));
    std::cerr << "done" << std::endl;
  }

  template < class value_type >
  void unit_test() {
    std::vector< usize > ns({small - 1, small, small + 1, medium - 1,
                             medium, medium + 1, large - 1, large,
                             large + 1});

    std::cerr << "type : " << typeid(value_type).name() << std::endl;
    for (const usize &n: ns) {
      std::cerr << "  n = " << n << " : " << std::endl;
      unit_test< value_type >(n);
      std::cerr << "  done" << std::endl;
    }
  }

  void main_() {
    unit_test< Monoid< i32 > >();

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
