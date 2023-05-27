// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/class/edge.hpp"
#include "src/graph/class/static-graph.hpp"
#include "src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp"

#include <iostream>

namespace luz {

  void main_() {
    using edge  = Edge< i32 >;
    using graph = StaticGraph< edge >;

    usize n;
    std::cin >> n;

    graph g(n);
    for (usize v: rep(0, n)) {
      usize k;
      std::cin >> k;

      for ([[maybe_unused]] usize _: rep(0, k)) {
        usize u;
        std::cin >> u;
        g.add_undirected_edge(u, v);
      }
    }

    g.initialize();

    OfflineLCAQuery offline_lcas(g);

    usize q;
    std::cin >> q;

    std::vector< std::pair< usize, usize > > qs(q);
    for (auto &[u, v]: qs) {
      std::cin >> u >> v;
      offline_lcas.add_query(u, v);
    }

    offline_lcas.build(0);
    for (const auto &[u, v]: qs) {
      std::cout << offline_lcas.lca(u, v) << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
