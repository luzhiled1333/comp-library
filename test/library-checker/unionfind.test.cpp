// verification-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/disjoint-set-union.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    DisjointSetUnion dsu(n);

    for ([[maybe_unused]] usize _: rep(0, q)) {
      usize t, u, v;
      std::cin >> t >> u >> v;

      if (t == 0) {
        dsu.merge(u, v);
      } else {
        std::cout << dsu.same(u, v) << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
