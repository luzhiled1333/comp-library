#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"
#include "src/graph/offline-query-level-ancestor.hpp"
#include "src/utility/pair-hash.hpp"

#include <unordered_map>
#include <utility>
#include <vector>

namespace luz {
  template < typename cost_type >
  class OfflineJumpOnFunctionalGraphQuery {
    usize g_size_;
    Graph< cost_type > g_;
    Graph< usize > tree_;
    std::vector< usize > tree_depth_, tree_root_;
    using query_type = std::pair< usize, u64 >;
    std::vector< query_type > qs_;
    std::unordered_map< query_type, usize, PairHash > results_;

    void dfs_on_tree(usize v, usize p) {
      for (auto &e: tree_[v]) {
        usize u = e.to;
        if (u == p) continue;
        tree_root_[u]  = tree_root_[v];
        tree_depth_[u] = tree_depth_[v] + 1;
        dfs_on_tree(u, v);
      }
    }

   public:
    explicit OfflineJumpOnFunctionalGraphQuery(
        const Graph< cost_type > &g)
        : g_size_(g.size()),
          tree_(g.size() + 1),
          tree_depth_(g.size()),
          tree_root_(g.size()),
          g_(g) {
      for (usize v: rep(0, g_size_)) {
        assert(g_[v].size() == 1);
      }
    }

    void add_query(usize v, u64 k) {
      qs_.emplace_back(v, k);
    }

    void build() {
      std::vector< usize > degs(g_size_);
      for (usize v: rep(0, g_size_)) {
        degs[g_[v][0].to]++;
      }
      std::vector< usize > que;
      for (usize v: rep(0, g_size_)) {
        if (degs[v] == 0) {
          que.emplace_back(v);
        }
      }
      while (not que.empty()) {
        usize v = que.back();
        que.pop_back();
        usize u = g_[v][0].to;
        degs[u]--;
        tree_.add_undirected_edge(u, v);
        if (degs[u] == 0) {
          que.emplace_back(u);
        }
      }
      for (usize v: rep(0, g_size_)) {
        if (degs[v] != 0) {
          tree_root_[v] = v;
          tree_.add_undirected_edge(g_size_, v);
          dfs_on_tree(v, g_size_);
        }
      }
      std::vector< usize > loop_id(g_size_), loop_size(g_size_),
          loop_pos(g_size_);
      std::vector< std::vector< usize > > loops;
      for (usize v: rep(0, g_size_)) {
        if (degs[v] != 0) {
          usize cur = v;
          std::vector< usize > loop;
          do {
            loop_id[cur]  = loops.size();
            loop_pos[cur] = loop.size();
            loop.emplace_back(cur);
            degs[cur] = 0;
            cur       = g_[cur][0].to;
          } while (cur != v);
          do {
            loop_size[cur] = loop.size();
            cur            = g_[cur][0].to;
          } while (cur != v);
          loops.emplace_back(std::move(loop));
        }
      }
      OfflineLAQuery< usize > la(tree_);
      for (auto [v, k]: qs_) {
        if (k < tree_depth_[v]) {
          la.add_query(v, tree_depth_[v] - k + 1);
        } else {
          query_type qi(v, k);
          k -= tree_depth_[v];
          usize root = tree_root_[v];
          auto &loop = loops[loop_id[root]];
          k += loop_pos[root];
          k %= loop_size[root];
          results_[qi] = loop[k];
        }
      }
      la.build(g_size_);
      for (auto [v, k]: qs_) {
        if (k < tree_depth_[v]) {
          query_type qi(v, k);
          results_[qi] = la.la(v, tree_depth_[v] - k + 1).value();
        }
      }
    }

    usize jump(usize v, u64 k) const {
      query_type qi(v, k);
      assert(results_.count(qi));
      return results_.find(qi)->second;
    }
  };
} // namespace luz
