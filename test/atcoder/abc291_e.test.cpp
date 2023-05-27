// verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_e

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/vector-ios.hpp"
#include "src/graph/class/edge.hpp"
#include "src/graph/class/static-graph.hpp"
#include "src/graph/topological-ordering/lexical-order-topological-sort.hpp"

#include <functional>
#include <iostream>

namespace luz {

  void main_() {
    using edge = Edge< usize >;
    using graph = StaticGraph< edge >;

    usize n, m;
    std::cin >> n >> m;

    graph g(n);
    for ([[maybe_unused]] usize _: rep(0, m)) {
      usize t, f;
      std::cin >> t >> f;
      g.add_directed_edge(t - 1, f - 1);
    }
    g.initialize();

    auto ord =
        lexical_order_topological_sort< graph,
                                        std::greater< usize > >(g);
    auto rev =
        lexical_order_topological_sort< graph, std::less< usize > >(
            g);

    if (ord == rev) {
      std::cout << "Yes" << std::endl;

      std::vector< usize > ans(n);
      for (usize i: rep(0, n)) {
        ans[ord[i]] = i + 1;
      }

      std::cout << ans << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
