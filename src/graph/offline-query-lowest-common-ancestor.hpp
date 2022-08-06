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
    Graph< cost_type > g_;

    std::vector< std::vector< std::pair< usize, usize > > > qs_;

    DisjointSetUnion dsu_;
    std::vector< bool > visited_;
    std::vector< usize > ancestors_;

    void dfs(usize v, std::vector< usize > &ret) {
      visited_[v] = true;
      ancestors_[v] = v;

      for (const auto &e: g_[v]) {
        if (visited_[e.to]) continue;
        dfs(e.to, ret);
        dsu_.merge(v, e.to);
        ancestors_[dsu_.leader(v)] = v;
      }

      for (const auto &[u, qi]: qs_[v]) {
        if (not visited_[u]) continue;
        ret[qi] = ancestors_[dsu_.leader(u)];
      }
    }

   public:
    using Queries = std::vector< std::pair< usize, usize > >;

    OfflineLCAQuery(Graph< cost_type > &g): g_size_(g.size()), g_(g) {}

    std::vector< usize > solve(const Queries &queries, usize root) {
      usize q = queries.size();
      qs_.resize(g_size_);
      for (usize qi: rep(0, q)) {
        const auto [u, v] = queries[qi];
        qs_[u].emplace_back(v, qi);
        qs_[v].emplace_back(u, qi);
      }

      dsu_ = DisjointSetUnion(g_size_);
      visited_.assign(g_size_, false);
      ancestors_.resize(g_size_);

      std::vector< usize > ret(q);
      dfs(root, ret);
      qs_.clear();
      return ret;
    }

  };

} // namespace luz
