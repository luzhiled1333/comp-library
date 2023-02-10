#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"
#include "src/utility/bit/bit-width.hpp"

#include <cassert>
#include <utility>
#include <vector>

namespace luz {

  template < typename cost_type >
  class OnlineJumpOnFunctionalGraphQuery {
    usize g_size;
    Graph< cost_type > g;

    usize LOG;
    std::vector< std::vector< usize > > doubling_table;

    std::vector< usize > loop_id, loop_size, loop_pos;
    std::vector< std::vector< usize > > loops;

    void check_functional_graph() {
      for (usize v: rep(0, g_size)) {
        assert(g[v].size() == 1);
      }
    }

    void build_doubling_table() {
      for (usize v: rep(0, g_size)) {
        doubling_table[0][v] = g[v][0].to;
      }
      for (usize k: rep(1, LOG)) {
        for (usize v: rep(0, g_size)) {
          usize pv             = doubling_table[k - 1][v];
          doubling_table[k][v] = doubling_table[k - 1][pv];
        }
      }
    }

    std::vector< usize > get_indegrees() const {
      std::vector< usize > indegrees(g_size);
      for (usize v: rep(0, g_size)) {
        indegrees[g[v][0].to]++;
      }
      return indegrees;
    }

    void delete_leaves(std::vector< usize > &indegrees) {
      std::vector< usize > leaves;
      leaves.reserve(g_size);

      for (usize v: rep(0, g_size)) {
        if (indegrees[v] > 0) {
          continue;
        }
        leaves.emplace_back(v);
      }

      while (not leaves.empty()) {
        usize v = leaves.back();
        leaves.pop_back();

        usize u = g[v][0].to;
        indegrees[u]--;

        if (indegrees[u] == 0) {
          leaves.emplace_back(u);
        }
      }
    }

    void construct_loops() {
      std::vector< usize > indegrees = get_indegrees();
      delete_leaves(indegrees);

      for (usize v: rep(0, g_size)) {
        if (indegrees[v] == 0) {
          continue;
        }

        usize cur = v;
        std::vector< usize > loop;

        do {
          loop_id[cur]  = loops.size();
          loop_pos[cur] = loop.size();
          loop.emplace_back(cur);
          indegrees[cur] = 0;
          cur            = g[cur][0].to;
        } while (cur != v);

        do {
          loop_size[cur] = loop.size();
          cur            = g[cur][0].to;
        } while (cur != v);

        loops.emplace_back(std::move(loop));
      }
    }

    usize jump_small(usize v, usize k) {
      assert(k < g_size);

      for (usize i: rep(0, LOG)) {
        if ((k & 1) == 1) {
          v = doubling_table[i][v];
        }
        k >>= 1;
      }
      return v;
    }

   public:
    OnlineJumpOnFunctionalGraphQuery(const Graph< cost_type > &g_)
        : g_size(g_.size()),
          g(g_),
          LOG(bit_width(g_size - 1)),
          doubling_table(LOG, std::vector< usize >(g_size)),
          loop_id(g_size, -1),
          loop_size(g_size),
          loop_pos(g_size, -1) {
      check_functional_graph();

      build_doubling_table();
      construct_loops();
    }

    usize jump(usize v, u64 k) {
      if (k == 0) {
        return v;
      }

      if (k < g_size) {
        return jump_small(v, k);
      }

      v = jump_small(v, g_size - 1);
      k -= (g_size - 1);

      const auto &loop = loops[loop_id[v]];
      k += loop_pos[v];
      k %= loop_size[v];
      return loop[k];
    }
  };

} // namespace luz
