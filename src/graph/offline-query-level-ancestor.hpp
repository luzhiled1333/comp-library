#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"

#include <cassert>
#include <optional>
#include <unordered_map>
#include <vector>

namespace luz {

  template < typename cost_type >
  class OfflineLAQuery {
    usize g_size_;
    Graph< cost_type > g_;

    usize query_count_;
    std::vector< std::vector< std::pair< usize, usize > > > qs_;

    std::vector< std::unordered_map< usize, usize > > to_qi_;

    std::vector< bool > visited_;
    std::vector< usize > path_;

    std::vector< std::optional< usize > > query_results_;

    void bound_check(usize v) const {
      assert(v < g_size_);
    }

    void dfs(usize v) {
      visited_[v] = true;
      path_.push_back(v);

      for (const auto &[level, qi]: qs_[v]) {
        if (level < path_.size()) {
          query_results_[qi] = path_[level];
        }
      }

      for (const auto &e: g_[v]) {
        if (visited_[e.to]) continue;
        dfs(e.to);
      }

      path_.pop_back();
    }

   public:
    explicit OfflineLAQuery(Graph< cost_type > &g)
        : g_size_(g.size()),
          g_(g),
          query_count_(0),
          qs_(g_size_),
          to_qi_(g_size_),
          visited_(g_size_, false) {}

    usize add_query(usize v, usize level) {
      bound_check(v);
      qs_[v].emplace_back(level, query_count_);
      to_qi_[v][level] = query_count_;
      return query_count_++;
    }

    void build(usize root) {
      bound_check(root);
      query_results_.resize(query_count_);
      path_.reserve(g_size_);
      dfs(root);
    }

    std::optional< usize > la(usize v, usize level) {
      bound_check(v);
      assert(to_qi_[v].count(level));
      usize qi = to_qi_[v][level];
      return query_results_[qi];
    }
  };

} // namespace luz
