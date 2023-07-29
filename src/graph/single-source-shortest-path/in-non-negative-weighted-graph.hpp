#pragma once

#include "src/cpp-template/header/change-min.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace luz::sssp {

  template < class G >
  class InNonNegativeWeightedGraph {
    using cost_type = typename G::cost_type;
    using graph     = G;

    static constexpr usize undefined_ =
        std::numeric_limits< usize >::max();
    static constexpr cost_type inf_ =
        std::numeric_limits< cost_type >::max();

    graph g;
    usize g_size;
    std::vector< cost_type > ds;
    std::vector< usize > parents, ids;

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
            parents[e.to] = v;
            ids[e.to]     = e.id;
          }
        }
      }
    }

   public:
    explicit InNonNegativeWeightedGraph(const graph &g_, usize source)
        : g(g_),
          g_size(g.size()),
          ds(g_size, inf_),
          parents(g_size, undefined_),
          ids(g_size, undefined_) {
      dijkstra(source);
    }

    inline graph get_original_graph() const {
      return g;
    }

    static inline cost_type inf() {
      return inf_;
    }

    inline cost_type distance(const usize v) const {
      return ds[v];
    }

    inline std::vector< cost_type > get_distances() const {
      return ds;
    }

    static inline usize undefined() {
      return undefined_;
    }

    inline usize parent(const usize v) const {
      return parents[v];
    }

    inline std::vector< usize > get_parents() const {
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
