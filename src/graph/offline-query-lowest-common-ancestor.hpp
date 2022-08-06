#include <vector>
#include <utility>

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/disjoint-set-union.hpp"
#include "src/graph/graph-template.hpp"

namespace luz {

  template< typename cost_type >
  class OfflineLCAQuery {
    usize g_size_;
    Graph< cost_type > g;

    std::vector< std::vector< std::pair< usize, usize > > > qs;

    DisjointSetUnion dsu;
    std::vector< bool > visited;
    std::vector< usize > ancestors;

    void dfs(usize v, std::vector< usize > &ret) {
      visited[v] = true;
      ancestors[v] = v;

      for (const auto &e: g[v]) {
        if (visited[e.to]) continue;
        dfs(e.to, ret);
        dsu.merge(v, e.to);
        ancestors[dsu.leader(v)] = v;
      }

      for (const auto &[u, qi]: qs[v]) {
        if (not visited[u]) continue;
        ret[qi] = ancestors[dsu.leader(u)];
      }
    }

   public:
    using Queries = std::vector< std::pair< usize, usize > >;

    OfflineLCAQuery(Graph< cost_type > &g_): g_size_(g_.size()), g(g_) {}

    std::vector< usize > solve(const Queries &queries, usize root) {
      usize q = queries.size();
      qs.resize(g_size_);
      for (usize qi: rep(0, q)) {
        const auto [u, v] = queries[qi];
        qs[u].emplace_back(v, qi);
        qs[v].emplace_back(u, qi);
      }

      dsu = DisjointSetUnion(g_size_);
      visited.assign(g_size_, false);
      ancestors.resize(g_size_);

      std::vector< usize > ret(q);
      dfs(root, ret);
      qs.clear();
      return ret;
    }

  };

} // namespace luz
