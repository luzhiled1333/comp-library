// verification-helper: PROBLEM https://atcoder.jp/contests/abc258/tasks/abc258_e

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/cpp-template/header/vector-ios.hpp"
#include "src/graph/class/edge/edge.hpp"
#include "src/graph/class/static-graph.hpp"
#include "src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp"

#include <iostream>
#include <numeric>
#include <vector>

namespace luz {

  void main_() {
    using edge  = Edge< i64 >;
    using graph = StaticGraph< edge >;

    usize n, q, x;
    std::cin >> n >> q >> x;

    std::vector< i64 > ws(n);
    std::cin >> ws;

    i64 sum_w = std::accumulate(ws.begin(), ws.end(), i64());
    i64 xp    = x % sum_w;
    std::vector< i64 > ans(n, x / sum_w * n);

    ws.resize(2 * n + 1);
    for (usize i: rep(0, n)) {
      ws[n + i] = ws[i];
    }
    for (usize i: rrep(0, 2 * n)) {
      ws[i] += ws[i + 1];
    }

    graph fg(n);
    usize r = 0;
    for (usize l: rep(0, n)) {
      while (ws[l] - ws[r] < xp) {
        r++;
      }

      fg.add_directed_edge(l, r % n);
      ans[l] += r - l;
    }

    fg.initialize();

    std::vector< u64 > qs(q);
    OfflineJumpOnFunctionalGraphQuery
        offline_jump_on_functional_graph_solver(fg);
    for (usize i: rep(0, q)) {
      std::cin >> qs[i];
      --qs[i];
      offline_jump_on_functional_graph_solver.add_query(0, qs[i]);
    }
    offline_jump_on_functional_graph_solver.build();
    for (usize i: rep(0, q)) {
      std::cout << ans[offline_jump_on_functional_graph_solver.jump(
                       0, qs[i])]
                << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
