// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp"

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/graph/class/edge/edge.hpp"
#include "src/graph/class/static-graph.hpp"

#include <cassert>
#include <iostream>
#include <vector>

namespace luz {

  template < class G >
  usize naive(const G& fg, usize v, u64 k) {
    if (k == 0) {
      return v;
    } else {
      return naive(fg, fg[v][0].to, k - 1);
    }
  }

  void main_() {
    using edge  = Edge< u32 >;
    using graph = StaticGraph< edge >;

    graph fg(10);
    fg.add_directed_edge(0, 1);
    fg.add_directed_edge(1, 3);
    fg.add_directed_edge(2, 2);
    fg.add_directed_edge(3, 0);
    fg.add_directed_edge(4, 5);
    fg.add_directed_edge(5, 7);
    fg.add_directed_edge(6, 8);
    fg.add_directed_edge(7, 8);
    fg.add_directed_edge(8, 9);
    fg.add_directed_edge(9, 7);
    fg.initialize();

    OfflineJumpOnFunctionalGraphQuery
        offline_jump_on_functional_graph_solver(fg);
    const u64 large = 1000000000000000000ll;
    for (usize v: rep(0, 10)) {
      for (u64 k: rep(0, 100)) {
        offline_jump_on_functional_graph_solver.add_query(v, k);
      }
      offline_jump_on_functional_graph_solver.add_query(v, large);
    }

    offline_jump_on_functional_graph_solver.build();
    std::vector< usize > expected{1, 3, 2, 0, 9, 7, 8, 8, 9, 7};
    for (usize v: rep(0, 10)) {
      for (u64 k: rep(0, 100)) {
        assert(offline_jump_on_functional_graph_solver.jump(v, k) ==
               naive(fg, v, k));
      }
      assert(offline_jump_on_functional_graph_solver.jump(v, large) ==
             expected[v]);
    }

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
