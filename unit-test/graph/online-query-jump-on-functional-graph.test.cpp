// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A

#include "src/graph/online-query-jump-on-functional-graph.hpp"

#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"

#include <cassert>
#include <iostream>
#include <vector>

namespace luz {

  template < typename cost_type >
  usize naive(const Graph< cost_type >& fg, usize v, u64 k) {
    if (k == 0) {
      return v;
    } else {
      return naive(fg, fg[v][0].to, k - 1);
    }
  }

  void main_() {
    Graph< u32 > fg(10);
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

    OnlineJumpOnFunctionalGraphQuery
        online_jump_on_functional_graph_solver(fg);
    const u64 large = 1000000000000000000ll;
    std::vector< usize > expected{1, 3, 2, 0, 9, 7, 8, 8, 9, 7};
    for (usize v: rep(0, 10)) {
      for (u64 k: rep(0, 100)) {
        assert(online_jump_on_functional_graph_solver.jump(v, k) ==
               naive(fg, v, k));
      }
      assert(online_jump_on_functional_graph_solver.jump(v, large) ==
             expected[v]);
    }

    std::cout << "Hello World" << std::endl;
  }

} // namespace luz

int main() {
  luz::main_();
}
