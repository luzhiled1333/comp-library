// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/graph/graph-template.hpp"
#include "src/graph/offline-query-lowest-common-ancestor.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize n;
    std::cin >> n;

    Graph< i32 > g(n);
    // OfflineLCAQuery< i32 > g(n);
    for (usize v: rep(0, n)) {
      usize k;
      std::cin >> k;

      for ([[maybe_unused]] usize _: rep(0, k)) {
        usize u;
        std::cin >> u;
        g.add_undirected_edge(u, v);
      }
    }

    OfflineLCAQuery lca(g);

    usize q;
    std::cin >> q;

    decltype(lca)::Queries qs(q);
    for (auto &[u, v]: qs) {
      std::cin >> u >> v;
    }

    auto ans = lca.solve(qs, 0);
    for (auto &v: ans) {
      std::cout << v << std::endl;
    }

  }

} // namespace luz

int main() {
  luz::main_();
}
