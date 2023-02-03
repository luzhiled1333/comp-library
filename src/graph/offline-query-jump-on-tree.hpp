#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/graph/graph-template.hpp"

#include <vector>

namespace luz {

  template< typename cost_type >
  class OfflineJumpOnTreeQuery {
    usize g_size_;
    Graph< cost_type > g_;

    usize query_count_;

   public:
    OfflineJumpOnTreeQuery(Graph< cost_type > &g) : g_(g) {}

    usize add_query(usize begin, usize end, usize distance) {}

    void build(usize root) {}

    std::optional< usize > jump_on_tree(usize begin, usize end, usize distance) {}
  };

}
