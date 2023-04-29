#pragma once

#include "src/cpp-template/header/change-minmax.hpp"
#include "src/graph/graph-template.hpp"

#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace luz::sssp {

  template < typename cost_type >
  class InNonNegativeWeightedGraph {

    static constexpr usize undefined_ =
        std::numeric_limits< usize >::max();
    static constexpr cost_type inf_ =
        std::numeric_limits< cost_type >::max();

    Graph< cost_type > g;
    usize g_size;
    std::vector< cost_type > ds;
    std::vector< usize > froms, ids;

    void dijkstra(usize s) {
      using pq_type = std::pair< cost_type, usize >;
      std::priority_queue< pq_type, std::vector< pq_type >,
                           std::greater< pq_type > >
          pq;

      ds[s] = 0;
      pq.emplace(ds[s], s);

      while (not pq.empty()) {
        auto [cost, v] = pq.top();
        pq.pop();

        if (ds[v] < cost) continue;
        for (auto &e: g[v]) {
          if (chmin(ds[e.to], cost + e.cost)) {
            pq.emplace(ds[e.to], e.to);
            froms[e.to] = v;
            ids[e.to]   = e.id;
          }
        }
      }
    }

   public:
    explicit InNonNegativeWeightedGraph(const Graph< cost_type > &g_, usize source)
        : g(g_),
          g_size(g.size()),
          ds(g_size, inf_),
          froms(g_size, undefined_),
          ids(g_size, undefined_) {
      dijkstra(source);
    }

    inline Graph< cost_type > get_original_graph() const {
      return g;
    }

    inline cost_type inf() const {
      return inf_;
    }

    inline cost_type distance(const usize v) const {
      return ds[v];
    }

    inline std::vector< cost_type > get_distances() const {
      return ds;
    }

    inline usize undefined() const {
      return undefined_;
    }

    inline usize parent(const usize v) const {
      return froms[v];
    }

    inline std::vector< usize > get_parents() const {
      return froms;
    }

    inline usize edge_label(const usize v) const {
      return ids[v];
    }

    inline std::vector< usize > get_edge_labels() const {
      return ids;
    }
  };

} // namespace luz
