---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/input.hpp
    title: input
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/graph/class/dynamic-graph.hpp
    title: "\u52D5\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/class/edge/edge.hpp
    title: src/graph/class/edge/edge.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
    title: "\u975E\u8CA0\u91CD\u307F\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
      \ (Single Source Shortest Path in Non-negative Weighted Graph, Dijkstra's Algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
  bundledCode: "#line 1 \"test/aoj/grl_1_a/dynamic-graph.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\n\n#line 2 \"src/graph/class/dynamic-graph.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/graph/class/dynamic-graph.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename Edge >\n  class DynamicGraph\
    \ {\n\n    using Edges = std::vector< Edge >;\n\n   protected:\n    std::vector<\
    \ Edges > g;\n    usize edge_count;\n\n   public:\n    using cost_type = typename\
    \ Edge::cost_type;\n\n    DynamicGraph() = default;\n    explicit DynamicGraph(usize\
    \ n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return g.size();\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      assert(from < size());\n      assert(to < size());\n      g[from].emplace_back(from,\
    \ to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize u, usize\
    \ v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v < size());\n\
    \      assert(u != v);\n      g[u].emplace_back(u, v, cost, edge_count);\n   \
    \   g[v].emplace_back(v, u, cost, edge_count++);\n    }\n\n    Edges operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    const Edges operator[](const usize\
    \ &v) const {\n      return g[v];\n    }\n  };\n\n} // namespace luz\n#line 4\
    \ \"test/aoj/grl_1_a/dynamic-graph.test.cpp\"\n\n#line 2 \"src/cpp-template/header/input.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/input.hpp\"\n\n#include <iostream>\n\nnamespace\
    \ luz {\n\n  template < typename T = i64 >\n  T input() {\n    T tmp;\n    std::cin\
    \ >> tmp;\n    return tmp;\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace\
    \ luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n        ++i;\n\
    \      }\n      constexpr usize operator*() const noexcept {\n        return i;\n\
    \      }\n      constexpr bool operator!=(const itr x) const noexcept {\n    \
    \    return i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rep(const\
    \ usize f, const usize l) noexcept\n        : f(std::min(f, l)),\n          l(l)\
    \ {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n  \
    \  constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n  struct\
    \ rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const usize i)\
    \ noexcept: i(i) {}\n      void operator++() noexcept {\n        --i;\n      }\n\
    \      constexpr usize operator*() const noexcept {\n        return i;\n     \
    \ }\n      constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rrep(const usize\
    \ f, const usize l) noexcept\n        : f(l - 1),\n          l(std::min(f, l)\
    \ - 1) {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n\
    \    constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n}\
    \ // namespace luz\n#line 2 \"src/graph/class/edge/edge.hpp\"\n\n#line 4 \"src/graph/class/edge/edge.hpp\"\
    \n\n#line 6 \"src/graph/class/edge/edge.hpp\"\n\nnamespace luz {\n\n  template\
    \ < typename T >\n  class Edge {\n   public:\n    using cost_type = T;\n\n   \
    \ usize from, to;\n    T cost;\n    usize id;\n    Edge() = default;\n    Edge(usize\
    \ from_, usize to_, T cost_, usize id_)\n        : from(from_),\n          to(to_),\n\
    \          cost(cost_),\n          id(id_) {}\n  };\n\n  template < typename T\
    \ >\n  using Edges = std::vector< Edge< T > >;\n\n} // namespace luz\n#line 2\
    \ \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\n\nnamespace luz {\n\
    \n  template < typename T1, typename T2 >\n  inline bool chmax(T1 &a, T2 b) {\n\
    \    return a < b and (a = b, true);\n  }\n\n  template < typename T1, typename\
    \ T2 >\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n#line 5 \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\n#include <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #line 11 \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\nnamespace luz::sssp {\n\n  template < class G >\n  class InNonNegativeWeightedGraph\
    \ {\n    using cost_type = typename G::cost_type;\n    using graph     = G;\n\n\
    \    static constexpr usize undefined_ =\n        std::numeric_limits< usize >::max();\n\
    \    static constexpr cost_type inf_ =\n        std::numeric_limits< cost_type\
    \ >::max();\n\n    graph g;\n    usize g_size;\n    std::vector< cost_type > ds;\n\
    \    std::vector< usize > parents, ids;\n\n    void dijkstra(usize s) {\n    \
    \  using pq_type = std::pair< cost_type, usize >;\n      std::priority_queue<\
    \ pq_type, std::vector< pq_type >,\n                           std::greater< pq_type\
    \ > >\n          pq;\n\n      ds[s] = 0;\n      pq.emplace(ds[s], s);\n\n    \
    \  while (not pq.empty()) {\n        auto [cost, v] = pq.top();\n        pq.pop();\n\
    \n        if (ds[v] < cost) continue;\n        for (auto &e: g[v]) {\n       \
    \   if (chmin(ds[e.to], cost + e.cost)) {\n            pq.emplace(ds[e.to], e.to);\n\
    \            parents[e.to] = v;\n            ids[e.to]     = e.id;\n         \
    \ }\n        }\n      }\n    }\n\n   public:\n    explicit InNonNegativeWeightedGraph(const\
    \ graph &g_, usize source)\n        : g(g_),\n          g_size(g.size()),\n  \
    \        ds(g_size, inf_),\n          parents(g_size, undefined_),\n         \
    \ ids(g_size, undefined_) {\n      dijkstra(source);\n    }\n\n    inline graph\
    \ get_original_graph() const {\n      return g;\n    }\n\n    static inline cost_type\
    \ inf() {\n      return inf_;\n    }\n\n    inline cost_type distance(const usize\
    \ v) const {\n      return ds[v];\n    }\n\n    inline std::vector< cost_type\
    \ > get_distances() const {\n      return ds;\n    }\n\n    static inline usize\
    \ undefined() {\n      return undefined_;\n    }\n\n    inline usize parent(const\
    \ usize v) const {\n      return parents[v];\n    }\n\n    inline std::vector<\
    \ usize > get_parents() const {\n      return parents;\n    }\n\n    inline usize\
    \ edge_label(const usize v) const {\n      return ids[v];\n    }\n\n    inline\
    \ std::vector< usize > get_edge_labels() const {\n      return ids;\n    }\n \
    \ };\n\n} // namespace luz::sssp\n#line 10 \"test/aoj/grl_1_a/dynamic-graph.test.cpp\"\
    \n\n#line 12 \"test/aoj/grl_1_a/dynamic-graph.test.cpp\"\n\nnamespace luz {\n\n\
    \  void main_() {\n    usize v = input(), e = input(), source = input();\n\n \
    \   using edge  = Edge< u32 >;\n    using graph = DynamicGraph< edge >;\n\n  \
    \  graph g(v);\n    for ([[maybe_unused]] usize _: rep(0, e)) {\n      usize s\
    \ = input(), t = input();\n      u32 d = input();\n      g.add_directed_edge(s,\
    \ t, d);\n    }\n\n    sssp::InNonNegativeWeightedGraph solver(g, source);\n \
    \   auto dists = solver.get_distances();\n    for (auto &dist: dists) {\n    \
    \  if (dist == solver.inf()) {\n        std::cout << \"INF\" << std::endl;\n \
    \     } else {\n        std::cout << dist << std::endl;\n      }\n    }\n  }\n\
    \n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\n\
    \n#include \"src/graph/class/dynamic-graph.hpp\"\n\n#include \"src/cpp-template/header/input.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/graph/class/edge/edge.hpp\"\n#include \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize v =\
    \ input(), e = input(), source = input();\n\n    using edge  = Edge< u32 >;\n\
    \    using graph = DynamicGraph< edge >;\n\n    graph g(v);\n    for ([[maybe_unused]]\
    \ usize _: rep(0, e)) {\n      usize s = input(), t = input();\n      u32 d =\
    \ input();\n      g.add_directed_edge(s, t, d);\n    }\n\n    sssp::InNonNegativeWeightedGraph\
    \ solver(g, source);\n    auto dists = solver.get_distances();\n    for (auto\
    \ &dist: dists) {\n      if (dist == solver.inf()) {\n        std::cout << \"\
    INF\" << std::endl;\n      } else {\n        std::cout << dist << std::endl;\n\
    \      }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/graph/class/dynamic-graph.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/input.hpp
  - src/cpp-template/header/rep.hpp
  - src/graph/class/edge/edge.hpp
  - src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
  - src/cpp-template/header/change-minmax.hpp
  isVerificationFile: true
  path: test/aoj/grl_1_a/dynamic-graph.test.cpp
  requiredBy: []
  timestamp: '2023-05-28 01:36:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl_1_a/dynamic-graph.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl_1_a/dynamic-graph.test.cpp
- /verify/test/aoj/grl_1_a/dynamic-graph.test.cpp.html
title: test/aoj/grl_1_a/dynamic-graph.test.cpp
---
