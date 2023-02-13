// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"
#include "src/graph/single-source-shortest-path/in-weighted-graph.hpp"

#include <iostream>

namespace luz {

  void main_() {
    int v, e, source;
    std::cin >> v >> e >> source;
    Graph< i32 > G(v);
    for ([[maybe_unused]] usize _: rep(0, e)) {
      usize s, t;
      i32 d;
      std::cin >> s >> t >> d;
      G.add_directed_edge(s, t, d);
    }

    sssp::InWeightedGraph sssp(G, source);
    if (sssp.is_negative_cycle()) {
      std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
      auto dists = sssp.get_distances();
      for (auto &dist: dists) {
        if (dist == sssp::InWeightedGraph< i32 >::inf()) {
          std::cout << "INF" << std::endl;
        } else {
          std::cout << dist << std::endl;
        }
      }
    }
  }

} // namespace luz

int main() {
  luz::main_();
}
