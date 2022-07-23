// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/data-structure/disjoint-set-union.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    DisjointSetUnion d(n);
    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize com, x, y;
      std::cin >> com >> x >> y;

      if (not com) {
        d.merge(x, y);
      } else {
        std::cout << (d.same(x, y)) << std::endl;
      }
    }

  }

} // namespace luz

int main() {
  luz::main_();
}
