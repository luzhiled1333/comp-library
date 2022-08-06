#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/disjoint-set-union.hpp"
#include "src/graph/graph-template.hpp"

#include <vector>
#include <utility>
#include <unordered_map>

namespace luz {

  template< typename cost_type >
  class OfflineLCAQuery {
    usize g_size_;
    Graph< cost_type > g_;

    usize query_count_;
    std::vector< std::vector< std::pair< usize, usize > > > qs_;

    std::vector< std::unordered_map< usize, usize > > to_qi_;

    DisjointSetUnion dsu_;
    std::vector< bool > visited_;
    std::vector< usize > ancestors_;

    std::vector< usize > query_results_;

    void dfs(usize v) {
      visited_[v] = true;
      ancestors_[v] = v;

      for (const auto &e: g_[v]) {
        if (visited_[e.to]) continue;
        dfs(e.to);
        dsu_.merge(v, e.to);
        ancestors_[dsu_.leader(v)] = v;
      }

      for (const auto &[u, qi]: qs_[v]) {
        if (not visited_[u]) continue;
        query_results_[qi] = ancestors_[dsu_.leader(u)];
      }
    }

   public:
    using Queries = std::vector< std::pair< usize, usize > >;

    OfflineLCAQuery(Graph< cost_type > &g):
      g_size_(g.size()), g_(g),
      query_count_(0), qs_(g_size_), to_qi_(g_size_),
      dsu_(g_size_), visited_(g_size_, false), ancestors_(g_size_) {}

    usize add_query(usize u, usize v) {
      qs_[u].emplace_back(v, query_count_);
      qs_[v].emplace_back(u, query_count_);
      to_qi_[u][v] = to_qi_[v][u] = query_count_;
      return query_count_++;
    }

    void build(usize root) {
      query_results_.resize(query_count_);
      dfs(root);
    }

    usize lca(usize u, usize v) {
      usize qi = to_qi_[u][v];
      return query_results_[qi];
    }

  };

} // namespace luz
