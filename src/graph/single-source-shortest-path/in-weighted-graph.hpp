#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/class/dynamic-graph.hpp"

#include <limits>
#include <queue>
#include <vector>

namespace luz::sssp {

  template < class G >
  class InWeightedGraph {
    using cost_type = typename G::cost_type;
    using graph     = G;

    static constexpr cost_type inf_ =
        std::numeric_limits< cost_type >::max();
    static constexpr cost_type negative_inf_ =
        std::numeric_limits< cost_type >::min();
    static constexpr usize undefined_ =
        std::numeric_limits< usize >::max();

    graph g;
    usize g_size;
    usize source;

    std::vector< cost_type > ds;
    std::vector< usize > parents, ids;

    void spfa(usize s) {
      std::queue< usize > que;
      std::vector< usize > ds_update_cnt(g_size);
      std::vector< bool > in_que(g_size);

      ds[s]            = 0;
      in_que[s]        = true;
      ds_update_cnt[s] = 0;
      que.emplace(s);

      while (not que.empty()) {
        usize v = que.front();
        que.pop();
        in_que[v] = false;

        for (const auto &e: g[v]) {
          usize u        = e.to;
          cost_type cost = e.cost;
          if (ds[v] + cost >= ds[u]) {
            continue;
          }

          ds[u]      = ds[v] + cost;
          parents[u] = v;
          ids[u]     = e.id;

          if (in_que[u]) {
            continue;
          }

          in_que[u] = true;
          ds_update_cnt[u]++;

          if (ds_update_cnt[u] < 2 * g_size) {
            que.emplace(u);
          }
        }
      }

      for (usize v: rep(0, g_size)) {
        if (ds_update_cnt[v] >= g_size) {
          ds[v]      = negative_inf();
          parents[v] = undefined();
          ids[v]     = undefined();
        }
      }
    }

   public:
    explicit InWeightedGraph(const graph &g_, usize source_)
        : g(g_),
          g_size(g.size()),
          source(source_),
          ds(g_size, inf()),
          parents(g_size, undefined()),
          ids(g_size, undefined()) {
      spfa(source);
    }

    graph get_original_graph() const {
      return g;
    }

    static inline cost_type inf() {
      return inf_;
    }

    static inline cost_type negative_inf() {
      return negative_inf_;
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
