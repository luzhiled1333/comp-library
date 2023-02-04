#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"

#include <limits>
#include <queue>
#include <vector>

namespace luz {

  template < typename cost_type >
  std::vector< usize > distances_on_unweighted_graph(
      const Graph< cost_type > &g, usize root) {
    usize not_reached = std::numeric_limits< usize >::max();
    std::vector< usize > distances(g.size(), not_reached);
    distances[root] = 0;

    std::queue< usize > que;
    que.emplace(root);

    while (not que.empty()) {
      usize v = que.front();
      que.pop();

      for (const auto &e: g[v]) {
        usize u = e.to;

        if (distances[u] != not_reached) continue;

        distances[u] = distances[v] + 1;
        que.emplace(u);
      }
    }

    return distances;
  }

} // namespace luz
