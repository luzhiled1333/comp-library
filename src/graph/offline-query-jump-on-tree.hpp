#pragma once

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
    std::unordered_map< result_key, usize, TupleHash > result;

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

    usize add_query(usize start, usize end, usize distance) {
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

      for (const auto &[s, t, d]: qs_) {
        usize st_lca      = lca_.lca(s, t);
        usize distance_sr = depths[s] - depths[r];
        usize distance_rt = depths[t] - depths[r];

        if (k <= sr_dist) {
          converted_qs_.emplace_back(i, s, depth[r] + sr_dist - k);
        } else if (k <= sr_dist + rt_dist) {
          converted_qs_.emplace_back(i, t, depth[r] + k - sr_dist);
        } else {
          result[result_key(s, t, d)] = std::nullopt;
        }
      }

      for (const auto &[_, v, k]: converted_qs_) {
        la_.add_query(v, k);
      }

      la_.build(root);

      for (const auto &[i, v, k]: converted_qs_) {
        auto qi    = qs_[i];
        result[qi] = la_.la(v, k).value();
      }
    }

    std::optional< usize > jump_on_tree(usize start, usize end,
                                        usize distance) {
      bound_check(start);
      bound_check(end);
      return result[result_key(start, end, distance)];
    }
  };

} // namespace luz
