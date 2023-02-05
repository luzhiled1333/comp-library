#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/disjoint-set-union.hpp"
#include "src/graph/graph-template.hpp"
#include "src/utility/pair-hash.hpp"

#include <cassert>
#include <unordered_map>
#include <utility>
#include <vector>

namespace luz {

  template < typename cost_type >
  class OfflineLCAQuery {
    usize g_size_;
    Graph< cost_type > g_;

    usize query_count_;
    std::vector< std::vector< usize > > qs_;

    DisjointSetUnion dsu_;
    std::vector< bool > visited_;
    std::vector< usize > ancestors_;

    using query_type = std::pair< usize, usize >;
    std::unordered_map< query_type, usize, PairHash > results_;

    void bound_check(usize v) const {
      assert(v < g_size_);
    }

    void dfs(usize v) {
      visited_[v]   = true;
      ancestors_[v] = v;

      for (const auto &e: g_[v]) {
        if (visited_[e.to]) continue;
        dfs(e.to);
        dsu_.merge(v, e.to);
        ancestors_[dsu_.leader(v)] = v;
      }

      for (const auto &u: qs_[v]) {
        if (not visited_[u]) continue;
        results_[query_type(u, v)] = results_[query_type(v, u)] =
            ancestors_[dsu_.leader(u)];
      }
    }

   public:
    using Queries = std::vector< std::pair< usize, usize > >;

    OfflineLCAQuery(Graph< cost_type > &g)
        : g_size_(g.size()),
          g_(g),
          query_count_(0),
          qs_(g_size_),
          dsu_(g_size_),
          visited_(g_size_, false),
          ancestors_(g_size_) {}

    void add_query(usize u, usize v) {
      bound_check(u);
      bound_check(v);
      qs_[u].emplace_back(v);
      qs_[v].emplace_back(u);
      query_count_++;
    }

    void build(usize root) {
      bound_check(root);
      results_.reserve(2 * query_count_);
      dfs(root);
    }

    usize lca(usize u, usize v) {
      bound_check(u);
      bound_check(v);
      query_type qi(u, v);
      assert(results_.count(qi));
      return results_[qi];
    }
  };

} // namespace luz
