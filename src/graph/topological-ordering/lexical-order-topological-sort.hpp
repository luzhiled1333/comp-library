#include <queue>
#include <vector>

namespace luz {

  template < class G, class Compare >
  std::vector< usize > lexical_order_topological_sort(const G &g) {
    usize n = g.size();

    std::vector< usize > indegrees(n);
    for (auto v: rep(0, n)) {
      for (auto &&e: g[v]) {
        indegrees[e.to]++;
      }
    }

    std::priority_queue< usize, std::vector< usize >, Compare > pq;
    for (usize v: rep(0, n)) {
      if (indegrees[v]) continue;
      pq.emplace(v);
    }

    std::vector< usize > result;
    result.reserve(n);
    while (not pq.empty()) {
      auto v = pq.top();
      pq.pop();

      result.emplace_back(v);
      for (auto &&e: g[v]) {
        if (--indegrees[e.to]) continue;
        pq.emplace(e.to);
      }
    }

    if (result.size() != n) {
      return {};
    }

    return result;
  }

} // namespace luz
