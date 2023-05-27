#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/data-structure/disjoint-set-union.hpp"
#include "src/utility/pair-hash.hpp"

#include <cassert>
#include <unordered_map>
#include <utility>
#include <vector>

namespace luz {

  template < class G >
  class OfflineLCAQuery {
    using graph = G;
    using cost_type = typename G::cost_type;
    usize g_size;
    graph g;

    usize query_count;
    std::vector< std::vector< usize > > qs;

    DisjointSetUnion dsu;
    std::vector< bool > visited;
    std::vector< usize > ancestors;

    using query_type = std::pair< usize, usize >;
    std::unordered_map< query_type, usize, PairHash > results;

    void bound_check(usize v) const {
      assert(v < g_size);
    }

    void dfs(usize v) {
      visited[v]   = true;
      ancestors[v] = v;

      for (const auto &e: g[v]) {
        if (visited[e.to]) continue;
        dfs(e.to);
        dsu.merge(v, e.to);
        ancestors[dsu.leader(v)] = v;
      }

      for (const auto &u: qs[v]) {
        if (not visited[u]) continue;
        results[query_type(u, v)] = results[query_type(v, u)] =
            ancestors[dsu.leader(u)];
      }
    }

   public:
    using Queries = std::vector< std::pair< usize, usize > >;

    OfflineLCAQuery(G &g)
        : g_size(g.size()),
          g(g),
          query_count(0),
          qs(g_size),
          dsu(g_size),
          visited(g_size, false),
          ancestors(g_size) {}

    void add_query(usize u, usize v) {
      bound_check(u);
      bound_check(v);
      qs[u].emplace_back(v);
      qs[v].emplace_back(u);
      query_count++;
    }

    void build(usize root) {
      bound_check(root);
      results.reserve(2 * query_count);
      dfs(root);
    }

    usize lca(usize u, usize v) {
      bound_check(u);
      bound_check(v);
      query_type qi(u, v);
      assert(results.count(qi));
      return results[qi];
    }
  };

} // namespace luz
