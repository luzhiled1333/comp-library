#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"

#include <limits>
#include <queue>
#include <vector>

namespace luz::sssp {

  template < typename cost_type >
  class InUnweightedGraph {
    using graph = Graph< cost_type >;

    graph g;
    usize g_size;
    usize source;

    std::vector< usize > ds, parents, ids;

    void bfs(usize s) {
      std::queue< usize > que;

      ds[s] = 0;
      que.emplace(s);

      while (not que.empty()) {
        usize v = que.front();
        que.pop();

        for (const auto &e: g[v]) {
          usize u = e.to;
          if (ds[u] != inf()) {
            continue;
          }

          ds[u] = ds[v] + 1;
          que.emplace(u);
          parents[u] = v;
          ids[u]   = e.id;
        }
      }
    }

   public:
    explicit InUnweightedGraph(const graph &g_, usize source_)
        : g(g_),
          g_size(g.size()),
          source(source_),
          ds(g_size, inf()),
          parents(g_size, undefined()),
          ids(g_size, undefined()) {
      bfs(source);
    }

    graph get_original_graph() const {
      return g;
    }

    static inline usize inf() {
      static usize inf_ = std::numeric_limits< usize >::max();
      return inf_;
    }

    inline usize distance(const usize v) const {
      return ds[v];
    }

    inline std::vector< usize > get_distances() const {
      return ds;
    }

    static inline usize undefined() {
      static usize undefined_ = std::numeric_limits< usize >::max();
      return undefined_;
    }

    inline usize parent(const usize v) const {
      return parents[v];
    }

    inline std::vector< usize > get_parent() const {
      return parents;
    }

    inline usize edge_label(const usize v) const {
      return ids[v];
    }

    inline std::vector< usize > get_edge_labels() const {
      return ids;
    }
  };

} // namespace luz::sssp
