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
    static constexpr cap_type INF_ =
        std::numeric_limits< cap_type >::max();

    struct Edge {
      usize to_;
      cap_type cap_;
      usize rev_;
      Edge() = default;
      Edge(usize to, cap_type cap, usize rev)
          : to_(to),
            cap_(cap),
            rev_(rev) {}
    };

    usize g_size_;
    std::vector< i32 > min_cost_;
    std::vector< usize > iter_;
    std::vector< std::vector< Edge > > graph_;

    bool build_augment_path(usize s, usize t) {
      min_cost_.assign(g_size_, -1);
      std::queue< usize > que;
      que.push(s);
      min_cost_[s] = 0;
      while (not que.empty() and min_cost_[t] == -1) {
        usize v = que.front();
        que.pop();
        for (const auto &e: graph_[v]) {
          if (e.cap_ > 0 and min_cost_[e.to_] == -1) {
            min_cost_[e.to_] = min_cost_[v] + 1;
            que.push(e.to_);
          }
        }
      }
      return min_cost_[t] != -1;
    }

    cap_type find_augment_path(usize v, usize t,
                               cap_type flow_limit) {
      if (v == t) return flow_limit;
      for (usize &i = iter_[v]; i < graph_[v].size(); i++) {
        Edge &e = graph_[v][i];
        if (e.cap_ > 0 and min_cost_[v] + 1 == min_cost_[e.to_]) {
          cap_type d = find_augment_path(
              e.to_, t, std::min(flow_limit, e.cap_));
          if (d > 0) {
            e.cap_ -= d;
            graph_[e.to_][e.rev_].cap_ += d;
            return d;
          }
        }
      }
      return 0;
    }

   public:
    MaxFlowGraph() = default;

    explicit MaxFlowGraph(usize n): g_size_(n), graph_(n) {}

    void add_directed_edge(usize from, usize to, cap_type cap) {
      assert(from < g_size_);
      assert(to < g_size_);
      assert(from != to);
      graph_[from].emplace_back(to, cap, graph_[to].size());
      graph_[to].emplace_back(from, 0, graph_[from].size() - 1);
    }

    inline cap_type inf() const {
      return INF_;
    }

    cap_type max_flow(usize s, usize t) {
      return max_flow(s, t, inf());
    }

    cap_type max_flow(usize s, usize t, cap_type flow_limit) {
      assert(s < g_size_);
      assert(t < g_size_);
      assert(s != t);
      cap_type flow = 0, add = 0;
      while (build_augment_path(s, t) and flow < flow_limit) {
        iter_.assign(g_size_, 0);
        do {
          add = find_augment_path(s, t, flow_limit - add);
          flow += add;
        } while (add > 0);
      }
      return flow;
    }
  };

} // namespace luz
