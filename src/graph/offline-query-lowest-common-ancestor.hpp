#include <vector>
#include <utility>

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/disjoint-set-union.hpp"
#include "src/graph/graph-template.hpp"

namespace luz {

  template< typename cost_type >
  class OfflineLCAQuery: Graph< cost_type > {
    using Graph< cost_type >::g;

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

    using Graph< cost_type >::Graph;
    using Graph< cost_type >::add_undirected_edge;
    using Graph< cost_type >::size;

    std::vector< usize > solve(const Queries &queries, usize root) {
      usize q = queries.size();
      qs.resize(size());
      for (usize qi: rep(0, q)) {
        const auto [u, v] = queries[qi];
        qs[u].emplace_back(v, qi);
        qs[v].emplace_back(u, qi);
      }

      dsu = DisjointSetUnion(size());
      visited.assign(size(), false);
      ancestors.resize(size());

      std::vector< usize > ret(q);
      dfs(root, ret);
      qs.clear();
      return ret;
    }

  };

} // namespace luz
