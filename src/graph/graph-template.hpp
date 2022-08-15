#pragma once

#include <cassert>
#include <vector>

#include "src/cpp-template/header/type-alias.hpp"

namespace luz {

  template < typename cost_type >
  class Edge {
  public:
    usize from, to;
    cost_type cost;
    usize id;
    Edge() = default;
    Edge(usize from_, usize to_, cost_type cost_, usize id_): from(from_), to(to_), cost(cost_), id(id_) {}
  };

  template < typename cost_type >
  using Edges = std::vector< Edge< cost_type > >;

  template < typename cost_type >
  class Graph {
  protected:
    std::vector< std::vector< Edge< cost_type > > > g;
    usize edge_count;

  public:
    Graph() = default;
    explicit Graph(usize n): g(n), edge_count(0) {}

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
      g[u].emplace_back(u, v, cost, edge_count);
      g[v].emplace_back(v, u, cost, edge_count++);
    }

    inline Edges< cost_type > &operator[](const usize &v) {
      return g[v];
    }

    inline const Edges< cost_type > &operator[](const usize &v) const {
      return g[v];
    }
  };

} // namespace luz
