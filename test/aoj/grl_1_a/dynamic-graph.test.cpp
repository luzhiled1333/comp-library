// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A

#include "src/cpp-template/header/input.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/class/edge.hpp"
#include "src/graph/class/dynamic-graph.hpp"
#include "src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp"

#include <iostream>

namespace luz {

  void main_() {
    usize v = input(), e = input(), source = input();

    using Edge = Edge< u32 >;
    DynamicGraph< Edge > g(v);
    for ([[maybe_unused]] usize _: rep(0, e)) {
      usize s = input(), t = input();
      u32 d = input();
      g.add_directed_edge(s, t, d);
    }

    sssp::InNonNegativeWeightedGraph solver(g, source);
    auto dists = solver.get_distances();
    for (auto &dist: dists) {
      if (dist == solver.inf()) {
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