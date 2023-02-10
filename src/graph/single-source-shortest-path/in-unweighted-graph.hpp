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

    std::vector< usize > ds, froms, ids;

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
          froms[u] = v;
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
          froms(g_size, undefined()),
          ids(g_size, undefined()) {
      bfs(source);
    }

    static inline usize undefined() {
      static usize undefined_ = std::numeric_limits< usize >::max();
      return undefined_;
    }

    static inline usize inf() {
      static usize inf_ = std::numeric_limits< usize >::max();
      return inf_;
    }

    inline usize dist(const usize v) const {
      return ds[v];
    }

    inline usize from_on_shortest_path_tree(const usize v) const {
      return froms[v];
    }

    inline usize edge_label(const usize v) const {
      return ids[v];
    }

    Graph< cost_type > get_original_graph() const {
      return g;
    }

    inline std::vector< usize > get_distances() const {
      return ds;
    }

    inline std::vector< usize > get_shortest_path_tree() const {
      return froms;
    }

    inline std::vector< usize > get_edge_labels() const {
      return ids;
    }
  };

} // namespace luz::sssp
