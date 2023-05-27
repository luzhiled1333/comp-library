#pragma once

#include "src/cpp-template/header/type-alias.hpp"

#include <cassert>
#include <vector>

namespace luz {

  template < typename Edge >
  class DynamicGraph {

    using Edges = std::vector< Edge >;

   protected:
    std::vector< Edges > g;
    usize edge_count;

   public:
    using cost_type = typename Edge::cost_type;

    DynamicGraph() = default;
    explicit DynamicGraph(usize n): g(n), edge_count(0) {}

    usize size() const {
      return g.size();
    }

    void add_directed_edge(usize from, usize to, cost_type cost = 1) {
      assert(from < size());
      assert(to < size());
      g[from].emplace_back(from, to, cost, edge_count++);
    }

    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {
      assert(u < size());
      assert(v < size());
      assert(u != v);
      g[u].emplace_back(u, v, cost, edge_count);
      g[v].emplace_back(v, u, cost, edge_count++);
    }

    Edges operator[](const usize &v) {
      return g[v];
    }

    const Edges operator[](const usize &v) const {
      return g[v];
    }
  };

} // namespace luz
