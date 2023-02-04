#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/distances-on-unweighted-graph.hpp"
#include "src/graph/graph-template.hpp"
#include "src/graph/offline-query-level-ancestor.hpp"
#include "src/graph/offline-query-lowest-common-ancestor.hpp"

#include <vector>
#include <optional>
namespace luz {

  template < typename cost_type >
  class OfflineJumpOnTreeQuery {
    usize g_size_;
    Graph< cost_type > g_;
    OfflineLCAQuery< cost_type > lca_;
    OfflineLAQuery< cost_type > la_;

    usize query_count_;
    std::vector< std::tuple< usize, usize, usize > > qs_;

    std::vector< std::pair< usize, usize > > converted_qs_;

   public:
    explicit OfflineJumpOnTreeQuery(Graph< cost_type > &g)
        : g_size_(g.size()),
          g_(g),
          lca_(g),
          la_(g),
          query_count_(0) {}

    usize add_query(usize start, usize end, usize distance) {
      qs_.emplace_back(start, end, distance);
    }

    void build(usize root) {
      for (auto &[s, t, _]: qs_) {
        lca_.add_query(s, t);
      }

      lca_.build(root);
      std::vector< usize > depths =
          distances_on_unweighted_graph(g_, root);
    }

    std::optional< usize > jump_on_tree(usize start, usize end,
                                        usize distance) {}
  };

} // namespace luz
