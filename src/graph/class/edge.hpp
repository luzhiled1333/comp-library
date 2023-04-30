#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

namespace luz {

  template < typename cost_type >
  class Edge {
   public:
    usize from, to;
    cost_type cost;
    usize id;
    Edge() = default;
    Edge(usize from_, usize to_, cost_type cost_, usize id_)
        : from(from_),
          to(to_),
          cost(cost_),
          id(id_) {}
  };

  template < typename cost_type >
  using Edges = std::vector< Edge< cost_type > >;

} // namespace luz
