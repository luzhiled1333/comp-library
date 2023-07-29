// verification-helper: PROBLEM https://atcoder.jp/contests/abc177/tasks/abc177_d

#include "src/cpp-template/header/change-max.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/disjoint-set-union.hpp"

#include <cassert>
#include <iostream>

namespace luz {

  void main_() {
    usize n, m;
    std::cin >> n >> m;

    DisjointSetUnion dsu(n);
    for ([[maybe_unused]] usize _: rep(0, m)) {
      usize u, v;
      std::cin >> u >> v;
      dsu.merge(u - 1, v - 1);
    }

    usize ans1 = 0, ans2 = 0;
    {
      for (usize v: rep(0, n)) {
        chmax(ans1, dsu.group_size(v));
      }
    }
    {
      auto groups = dsu.groups();
      for (const auto &group: groups) {
        chmax(ans2, group.size());
      }
    }

    assert(ans1 == ans2);

    usize ans = ans1;
    std::cout << ans << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
