#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/distances-on-unweighted-graph.hpp"
#include "src/graph/graph-template.hpp"
#include "src/graph/offline-query-level-ancestor.hpp"
#include "src/graph/offline-query-lowest-common-ancestor.hpp"
#include "src/utility/tuple-hash.hpp"

#include <cassert>
#include <optional>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace luz {

  template < typename cost_type >
  class OfflineJumpOnTreeQuery {
    usize g_size_;
    Graph< cost_type > g_;
    OfflineLCAQuery< cost_type > lca_;
    OfflineLAQuery< cost_type > la_;

    usize query_count_;
    std::vector< std::tuple< usize, usize, usize > > qs_;

    std::vector< std::tuple< usize, usize, usize > > converted_qs_;

    using result_key = std::tuple< usize, usize, usize >;
    std::unordered_map< result_key, std::optional< usize >,
                        TupleHash >
        result;

    void bound_check(usize v) const {
      assert(v < g_size_);
    }

   public:
    explicit OfflineJumpOnTreeQuery(Graph< cost_type > &g)
        : g_size_(g.size()),
          g_(g),
          lca_(g),
          la_(g),
          query_count_(0) {}

    void add_query(usize start, usize end, usize distance) {
      bound_check(start);
      bound_check(end);
      qs_.emplace_back(start, end, distance);
    }

    void build(usize root) {
      bound_check(root);
      for (const auto &[s, t, _]: qs_) {
        lca_.add_query(s, t);
      }

      lca_.build(root);

      std::vector< usize > depths =
          distances_on_unweighted_graph(g_, root);

      converted_qs_.reserve(query_count_);
      result.reserve(query_count_);

      for (usize i: rep(0, qs_.size())) {
        const auto &[s, t, d] = qs_[i];
        usize r               = lca_.lca(s, t);
        usize distance_sr     = depths[s] - depths[r];
        usize distance_rt     = depths[t] - depths[r];

        if (d <= distance_sr) {
          converted_qs_.emplace_back(i, s,
                                     depths[r] + distance_sr - d);
        } else if (d <= distance_sr + distance_rt) {
          converted_qs_.emplace_back(i, t,
                                     depths[r] + d - distance_sr);
        } else {
          result[qs_[i]] = std::nullopt;
        }
      }

      for (const auto &[_, v, k]: converted_qs_) {
        la_.add_query(v, k);
      }

      la_.build(root);

      for (const auto &[i, v, k]: converted_qs_) {
        auto qi    = qs_[i];
        result[qi] = la_.la(v, k);
      }
    }

    std::optional< usize > jump_on_tree(usize start, usize end,
                                        usize distance) {
      bound_check(start);
      bound_check(end);
      result_key qi(start, end, distance);
      return result[qi];
    }
  };

} // namespace luz
