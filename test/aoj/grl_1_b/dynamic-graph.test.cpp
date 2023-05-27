// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/class/edge.hpp"
#include "src/graph/class/dynamic-graph.hpp"
#include "src/graph/single-source-shortest-path/in-weighted-graph.hpp"

#include <iostream>

namespace luz {

  void main_() {
    int v, e, source;
    std::cin >> v >> e >> source;

    using edge = Edge< i32 >;
    using graph = DynamicGraph< edge >;

    graph g(v);
    for ([[maybe_unused]] usize _: rep(0, e)) {
      usize s, t;
      i32 d;
      std::cin >> s >> t >> d;
      g.add_directed_edge(s, t, d);
    }

    sssp::InWeightedGraph< graph > sssp(g, source);
    auto dists = sssp.get_distances();
    for (const auto& dist: dists) {
      if (dist == sssp.negative_inf()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return;
      }
    }
    for (const auto& dist: dists) {
      if (dist == sssp.inf()) {
        std::cout << "INF" << std::endl;
      } else {
        std::cout << dist << std::endl;
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
