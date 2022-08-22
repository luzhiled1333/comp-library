// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A

#include "src/cpp-template/header/input.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/dijkstra.hpp"
#include "src/graph/graph-template.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize v = input(), e = input(), source = input();

    Graph< u32 > G(v);
    for ([[maybe_unused]] usize _: rep(0, e)) {
      usize s = input(), t = input();
      u32 d = input();
      G.add_directed_edge(s, t, d);
    }

    Dijkstra dijkstra(G, source);
    auto dists = dijkstra.get_distances();
    for (auto &dist: dists) {
      if (dist == dijkstra.inf()) {
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
