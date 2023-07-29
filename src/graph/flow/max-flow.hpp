#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace luz {

  template < typename cap_type >
  class MaxFlowGraph {
    static constexpr cap_type INF =
        std::numeric_limits< cap_type >::max();

    struct Edge {
      usize to;
      cap_type cap;
      usize rev;
      Edge() = default;
      Edge(usize to, cap_type cap, usize rev)
          : to(to),
            cap(cap),
            rev(rev) {}
    };

    usize g_size;
    std::vector< i32 > min_cost;
    std::vector< usize > iter;
    std::vector< std::vector< Edge > > graph;

    bool build_augment_path(usize s, usize t) {
      min_cost.assign(g_size, -1);
      std::queue< usize > que;
      que.push(s);
      min_cost[s] = 0;
      while (not que.empty() and min_cost[t] == -1) {
        usize v = que.front();
        que.pop();
        for (const auto &e: graph[v]) {
          if (e.cap > 0 and min_cost[e.to] == -1) {
            min_cost[e.to] = min_cost[v] + 1;
            que.push(e.to);
          }
        }
      }
      return min_cost[t] != -1;
    }

    cap_type find_augment_path(usize v, usize t,
                               cap_type flow_limit) {
      if (v == t) return flow_limit;
      for (usize &i = iter[v]; i < graph[v].size(); i++) {
        Edge &e = graph[v][i];
        if (e.cap > 0 and min_cost[v] + 1 == min_cost[e.to]) {
          cap_type d =
              find_augment_path(e.to, t, std::min(flow_limit, e.cap));
          if (d > 0) {
            e.cap -= d;
            graph[e.to][e.rev].cap += d;
            return d;
          }
        }
      }
      return 0;
    }

   public:
    MaxFlowGraph() = default;

    explicit MaxFlowGraph(usize n): g_size(n), graph(n) {}

    void add_directed_edge(usize from, usize to, cap_type cap) {
      assert(from < g_size);
      assert(to < g_size);
      assert(from != to);
      graph[from].emplace_back(to, cap, graph[to].size());
      graph[to].emplace_back(from, 0, graph[from].size() - 1);
    }

    inline cap_type inf() const {
      return INF;
    }

    cap_type max_flow(usize s, usize t) {
      return max_flow(s, t, inf());
    }

    cap_type max_flow(usize s, usize t, cap_type flow_limit) {
      assert(s < g_size);
      assert(t < g_size);
      assert(s != t);
      cap_type flow = 0, add = 0;
      while (build_augment_path(s, t) and flow < flow_limit) {
        iter.assign(g_size, 0);
        do {
          add = find_augment_path(s, t, flow_limit - add);
          flow += add;
        } while (add > 0);
      }
      return flow;
    }
  };

} // namespace luz
