#include "src/graph/graph-template.hpp"

#include <queue>
#include <vector>

namespace luz {

  template< typename T, class Compare >
  std::vector< usize > lexical_order_topological_sort(const Graph< T > &g) {
    usize n = g.size();

    std::vector< usize > indegrees(n);
    for (auto v: rep(0, n)) {
      for (auto &&e: g[v]) {
        indegrees[e.to]++;
      }
    }

    std::priority_queue< usize, std::vector< usize >, Compare> pq;
    for (usize v: rep(0, n)) {
      if (indegrees[v]) continue;
      pq.emplace(v);
    }

    std::vector< usize > result;
    while (not pq.empty()) {
      auto v = pq.top();
      pq.pop();

      result.emplace_back(v);
      for (auto &&e: g[v]) {
        if (--indegrees[e.to]) continue;
        pq.emplace(e.to);
      }
    }

    return result;
  }

}
