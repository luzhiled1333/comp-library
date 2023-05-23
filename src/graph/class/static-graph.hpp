#pragma once

#include "src/cpp-template/header/type-alias.hpp"
#include "src/cpp-template/header/rep.hpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace luz {

  template < typename Edge >
  class StaticGraph {
    using cost_type = typename Edge::cost_type;

    using Edges = std::vector< Edge >;
    using iterator = typename Edges::iterator;
    using const_iterator = typename Edges::const_iterator;

   protected:
    bool constructed;
    usize vertex_count;
    usize edge_count;

    Edges edges;
    std::vector< usize > outdegrees;

    template<typename Iterator>
    class OutgoingEdges {
      Iterator f, l;

     public:
      OutgoingEdges(Iterator f, Iterator l) : f(f), l(l) {}

      Iterator begin() const {
        return f;
      }
      Iterator end() const {
        return l;
      }
      usize size() const {
        return l - f;
      }

      auto &&operator[](usize k) {
        assert(k < size());
        return begin()[k];
      }
    };

   public:
    StaticGraph() = default;
    explicit StaticGraph(usize n): constructed(false), vertex_count(n), edge_count(0), outdegrees(vertex_count) {}

    usize size() const {
      return vertex_count;
    }

    void construct() {
      assert(not constructed);

      outdegrees.emplace_back(0);
      for (usize i: rrep(0, size())) {
        outdegrees[i] += outdegrees[i + 1];
      }

      std::sort(edges.begin(),
                edges.end(),
                [](const Edge &e1, const Edge &e2) {
                  return e1.from != e2.from ? e1.from > e2.from : e1.to < e2.to;
                });

      constructed = true;
    }

    void add_directed_edge(usize from, usize to, cost_type cost = 1) {
      assert(not constructed);
      assert(from < size());
      assert(to < size());
      edges.emplace_back(from, to, cost, edge_count++);
      outdegrees[from]++;
    }

    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {
      assert(not constructed);
      assert(u < size());
      assert(v < size());
      assert(u != v);
      edges.emplace_back(u, v, cost, edge_count);
      outdegrees[u]++;
      edges.emplace_back(v, u, cost, edge_count++);
      outdegrees[v]++;
    }

    OutgoingEdges<iterator> operator[](const usize &v) {
      assert(constructed);
      return OutgoingEdges<iterator>(edges.begin() + outdegrees[v + 1], edges.begin() + outdegrees[v]);
    }

    const OutgoingEdges<const_iterator> &operator[](const usize &v) const {
      assert(constructed);
      return OutgoingEdges<const_iterator>(edges.begin() + outdegrees[v + 1], edges.begin() + outdegrees[v]);
    }
  };

} // namespace luz
