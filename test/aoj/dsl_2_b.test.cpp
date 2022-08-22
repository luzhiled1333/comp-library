// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/fenwick-tree.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    FenwickTree< u32 > ft(n);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com, x, y;
      std::cin >> com >> x >> y;

      if (not com) {
        ft.add(x - 1, y);
      } else {
        std::cout << ft.sum(x - 1, y) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
