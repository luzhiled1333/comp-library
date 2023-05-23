#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <vector>

namespace luz {

  template < typename T >
  class Edge {
   public:
    using cost_type = T;

    usize from, to;
    T cost;
    usize id;
    Edge() = default;
    Edge(usize from_, usize to_, T cost_, usize id_)
        : from(from_),
          to(to_),
          cost(cost_),
          id(id_) {}
  };

  template < typename T >
  using Edges = std::vector< Edge< T > >;

} // namespace luz
