#pragma once

#include "src/cpp-template/header/change-minmax.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"

#include <vector>

namespace luz::decomposition {

  template < typename cost_type >
  class StronglyConnectedComponents {
    Graph< cost_type > g;
    usize g_size;
    std::vector< usize > low, ord, visited, group_id;
    usize ord_cnt, group_cnt;

    void dfs(usize v) {
      low[v] = ord[v] = ord_cnt++;
      visited.emplace_back(v);
      for (auto& e: g[v]) {
        if (ord[e.to] == g_size) {
          dfs(e.to);
          chmin(low[v], low[e.to]);
        } else {
          chmin(low[v], ord[e.to]);
        }
      }
      if (low[v] == ord[v]) {
        while (true) {
          usize u = visited.back();
          visited.pop_back();
          ord[u]      = g_size + 1;
          group_id[u] = group_cnt;
          if (u == v) break;
        }
        group_cnt++;
      }
    }

   public:
    explicit StronglyConnectedComponents(const Graph< cost_type >& g_)
        : g(g_),
          g_size(g.size()),
          low(g_size),
          ord(g_size, g_size),
          group_id(g_size),
          ord_cnt(0),
          group_cnt(0) {
      visited.reserve(g_size);
      for (usize v: rep(0, g_size)) {
        if (ord[v] == g_size) {
          dfs(v);
        }
      }
      for (auto& id: group_id) {
        id = group_cnt - id - 1;
      }
    }

    std::vector< std::vector< usize > > groups() const {
      std::vector< usize > counts(group_cnt);
      for (usize i: rep(0, g_size)) {
        counts[group_id[i]]++;
      }
      std::vector< std::vector< usize > > groups(group_cnt);
      for (usize i: rep(0, group_cnt)) {
        groups[i].reserve(counts[i]);
      }
      for (usize i: rep(0, g_size)) {
        groups[group_id[i]].emplace_back(i);
      }
      return groups;
    }

    std::vector< usize > group_ids() const {
      return group_id;
    }
  };

} // namespace luz::decomposition
