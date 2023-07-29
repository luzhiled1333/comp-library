// verification-helper: PROBLEM https://judge.yosupo.jp/problem/jump_on_tree

#include "src/cpp-template/header/fast-ios.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/cpp-template/header/int-alias.hpp"
#include "src/graph/class/edge/edge.hpp"
#include "src/graph/class/static-graph.hpp"
#include "src/graph/tree/offline-query/offline-query-jump-on-tree.hpp"

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

namespace luz {

  void main_() {
    usize n, q;
    std::cin >> n >> q;

    using edge  = Edge< i32 >;
    using graph = StaticGraph< edge >;

    graph g(n);
    for ([[maybe_unused]] usize _: rep(1, n)) {
      usize a, b;
      std::cin >> a >> b;
      g.add_undirected_edge(a, b);
    }

    g.initialize();

    OfflineJumpOnTreeQuery offline_jump_on_tree_solver(g);
    std::vector< std::tuple< usize, usize, usize > > qs(q);
    for (auto& [s, t, i]: qs) {
      std::cin >> s >> t >> i;
      offline_jump_on_tree_solver.add_query(s, t, i);
    }
    offline_jump_on_tree_solver.build(0);

    for (const auto& [s, t, i]: qs) {
      auto ans = offline_jump_on_tree_solver.jump_on_tree(s, t, i);
      if (ans) {
        std::cout << ans.value() << std::endl;
      } else {
        std::cout << -1 << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::set_fast_ios();

  luz::main_();
}
