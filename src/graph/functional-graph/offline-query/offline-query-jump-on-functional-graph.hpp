#pragma once

#include "src/cpp-template/header/int-alias.hpp"
#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"
#include "src/graph/tree/offline-query/offline-query-level-ancestor.hpp"
#include "src/utility/pair-hash.hpp"

#include <cassert>
#include <unordered_map>
#include <utility>
#include <vector>

namespace luz {

  template < class G >
  class OfflineJumpOnFunctionalGraphQuery {
    using graph     = G;
    using cost_type = typename graph::cost_type;

    usize g_size;
    graph g;

    graph tree;
    usize tree_root;
    std::vector< usize > tree_depth, subtree_roots;

    std::vector< usize > loop_id, loop_size, loop_pos;
    std::vector< std::vector< usize > > loops;

    using query_type = std::pair< usize, u64 >;
    std::vector< query_type > qs;
    std::unordered_map< query_type, usize, PairHash > result;

    void dfs_on_subtree(usize v, usize p) {
      for (auto &e: tree[v]) {
        usize u = e.to;
        if (u == p) continue;
        subtree_roots[u] = subtree_roots[v];
        tree_depth[u]    = tree_depth[v] + 1;
        dfs_on_subtree(u, v);
      }
    }

    std::vector< usize > get_indegrees() const {
      std::vector< usize > indegrees(g_size);
      for (usize v: rep(0, g_size)) {
        for (auto e: g[v]) {
          indegrees[e.to]++;
        }
      }
      return indegrees;
    }

    void construct_tree(std::vector< usize > &indegrees) {
      std::vector< usize > leaves;
      leaves.reserve(g_size);

      for (usize v: rep(0, g_size)) {
        if (indegrees[v] > 0) {
          continue;
        }
        leaves.emplace_back(v);
      }

      while (not leaves.empty()) {
        usize child = leaves.back();
        leaves.pop_back();

        usize parent = g[child][0].to;
        indegrees[parent]--;

        tree.add_undirected_edge(parent, child);

        if (indegrees[parent] == 0) {
          leaves.emplace_back(parent);
        }
      }

      for (usize v: rep(0, g_size)) {
        if (indegrees[v] == 0) {
          continue;
        }
        tree.add_undirected_edge(tree_root, v);
      }

      tree.initialize();

      for (usize v: rep(0, g_size)) {
        if (indegrees[v] == 0) {
          continue;
        }
        subtree_roots[v] = v;
        dfs_on_subtree(v, tree_root);
      }
    }

    void construct_loops(std::vector< usize > &indegrees) {
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

   public:
    explicit OfflineJumpOnFunctionalGraphQuery(const graph &g_)
        : g_size(g_.size()),
          g(g_),
          tree(g_size + 1),
          tree_root(g_size),
          tree_depth(g_size),
          subtree_roots(g_size),
          loop_id(g_size),
          loop_size(g_size),
          loop_pos(g_size) {
      for (usize v: rep(0, g_size)) {
        assert(g[v].size() == 1);
      }

      std::vector< usize > indegrees = get_indegrees();
      construct_tree(indegrees);
      construct_loops(indegrees);
    }

    void add_query(usize v, u64 k) {
      qs.emplace_back(v, k);
    }

    void build() {
      OfflineLAQuery la_solver(tree);
      result.reserve(qs.size());
      for (auto [v, k]: qs) {
        if (k < tree_depth[v]) {
          la_solver.add_query(v, tree_depth[v] - k + 1);
        } else {
          query_type qi(v, k);
          k -= tree_depth[v];
          usize root       = subtree_roots[v];
          const auto &loop = loops[loop_id[root]];
          k += loop_pos[root];
          k %= loop_size[root];
          result[qi] = loop[k];
        }
      }
      la_solver.build(g_size);

      for (auto [v, k]: qs) {
        if (tree_depth[v] <= k) {
          continue;
        }
        query_type qi(v, k);
        result[qi] = la_solver.la(v, tree_depth[v] - k + 1).value();
      }
    }

    usize jump(usize v, u64 k) const {
      query_type qi(v, k);
      assert(result.count(qi));
      return result.find(qi)->second;
    }
  };
} // namespace luz
