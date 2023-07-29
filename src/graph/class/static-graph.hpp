#pragma once

#include "src/cpp-template/header/rep.hpp"
#include "src/cpp-template/header/size-alias.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace luz::internal {

  template < typename Iterator >
  class OutgoingEdges {
    Iterator f, l;

   public:
    OutgoingEdges(Iterator f, Iterator l): f(f), l(l) {}

    Iterator begin() const {
      return f;
    }
    Iterator end() const {
      return l;
    }
    usize size() const {
      return l - f;
    }

    auto &operator[](usize k) {
      assert(k < size());
      return begin()[k];
    }
    const auto &operator[](usize k) const {
      assert(k < size());
      return begin()[k];
    }
  };

} // namespace luz::internal

namespace luz {

  template < typename Edge >
  class StaticGraph {

    using Edges          = std::vector< Edge >;
    using iterator       = typename Edges::iterator;
    using const_iterator = typename Edges::const_iterator;

    template < typename Iterator >
    using Es = internal::OutgoingEdges< Iterator >;

   protected:
    bool initialized;
    usize vertex_count;
    usize edge_count;

    Edges edges;
    std::vector< usize > outdegrees;

   public:
    using cost_type = typename Edge::cost_type;

    StaticGraph() = default;
    explicit StaticGraph(usize n)
        : initialized(false),
          vertex_count(n),
          edge_count(0),
          outdegrees(vertex_count) {}

    usize size() const {
      return vertex_count;
    }

    void initialize() {
      assert(not initialized);

      outdegrees.emplace_back(0);
      for (usize i: rrep(0, size())) {
        outdegrees[i] += outdegrees[i + 1];
      }

      std::sort(edges.begin(), edges.end(),
                [](const Edge &e1, const Edge &e2) {
        return e1.from != e2.from ? e1.from > e2.from : e1.to < e2.to;
      });

      initialized = true;
    }

    void add_directed_edge(usize from, usize to, cost_type cost = 1) {
      assert(not initialized);
      assert(from < size());
      assert(to < size());
      edges.emplace_back(from, to, cost, edge_count++);
      outdegrees[from]++;
    }

    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {
      assert(not initialized);
      assert(u < size());
      assert(v < size());
      assert(u != v);
      edges.emplace_back(u, v, cost, edge_count);
      outdegrees[u]++;
      edges.emplace_back(v, u, cost, edge_count++);
      outdegrees[v]++;
    }

    Es< iterator > operator[](const usize &v) {
      assert(initialized);
      return Es< iterator >(edges.begin() + outdegrees[v + 1],
                            edges.begin() + outdegrees[v]);
    }

    const Es< const_iterator > operator[](const usize &v) const {
      assert(initialized);
      return Es< const_iterator >(edges.cbegin() + outdegrees[v + 1],
                                  edges.cbegin() + outdegrees[v]);
    }
  };

} // namespace luz
