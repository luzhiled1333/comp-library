#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/utility/pair-hash.hpp"

#include <cassert>
#include <optional>
#include <unordered_map>
#include <utility>
#include <vector>

namespace luz {

  template < class G >
  class OfflineLAQuery {
    using graph = G;
    using cost_type = typename graph::cost_type;

    usize g_size;
    graph g;

    usize query_count;
    std::vector< std::vector< usize > > qs;

    std::vector< bool > visited;
    std::vector< usize > path;

    using query_type = std::pair< usize, usize >;
    std::unordered_map< query_type, std::optional< usize >, PairHash >
        results;

    void bound_check(usize v) const {
      assert(v < g_size);
    }

    void dfs(usize v) {
      visited[v] = true;
      path.emplace_back(v);

      for (const auto &level: qs[v]) {
        if (level < path.size()) {
          results[query_type(v, level)] = path[level];
        }
      }

      for (const auto &e: g[v]) {
        if (visited[e.to]) continue;
        dfs(e.to);
      }

      path.pop_back();
    }

   public:
    explicit OfflineLAQuery() = default;

    explicit OfflineLAQuery(graph &g)
        : g_size(g.size()),
          g(g),
          query_count(0),
          qs(g_size),
          visited(g_size, false) {}

    void add_query(usize v, usize level) {
      bound_check(v);
      qs[v].emplace_back(level);
      query_count++;
    }

    void build(usize root) {
      bound_check(root);
      results.reserve(query_count);
      path.reserve(g_size);
      dfs(root);
    }

    std::optional< usize > la(usize v, usize level) const {
      bound_check(v);
      query_type qi(v, level);
      assert(results.count(qi));
      return (*results.find(qi)).second;
    }
  };

} // namespace luz
