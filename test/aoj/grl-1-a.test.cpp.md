---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/input.hpp
    title: input
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: src/cpp-template/header/rep.hpp
  - icon: ':question:'
    path: src/cpp-template/header/type-alias.hpp
    title: src/cpp-template/header/type-alias.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
  bundledCode: "#line 1 \"test/aoj/grl-1-a.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\n\n#include <iostream>\n\n\
    #line 2 \"src/cpp-template/header/input.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 4 \"src/cpp-template/header/input.hpp\"\n\nnamespace\
    \ luz {\n\n  template< typename T = i64 > T input() {\n    T tmp;\n    std::cin\
    \ >> tmp;\n    return tmp;\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept : i(i) {}\n \
    \     void operator++() noexcept { ++i; }\n      constexpr usize operator*() const\
    \ noexcept { return i; }\n      constexpr bool operator!=(const itr x) const noexcept\
    \ { return i != x.i; }\n    };\n    const itr f, l;\n    constexpr rep(const usize\
    \ f, const usize l) noexcept\n      : f(std::min(f, l)), l(l) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n \
    \     constexpr itr(const usize i) noexcept : i(i) {}\n      void operator++()\
    \ noexcept { --i; }\n      constexpr usize operator*() const noexcept { return\
    \ i; }\n      constexpr bool operator!=(const itr x) const noexcept { return i\
    \ != x.i; }\n    };\n    const itr f, l;\n    constexpr rrep(const usize f, const\
    \ usize l) noexcept\n      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n} // namespace luz\n#line 8 \"test/aoj/grl-1-a.test.cpp\"\
    \n\n#line 2 \"src/graph/graph-template.hpp\"\n\n#include <vector>\n\n#line 6 \"\
    src/graph/graph-template.hpp\"\n\nnamespace luz {\n\n  template< typename cost_type\
    \ >\n  class Edge {\n   public:\n    usize from, to;\n    cost_type cost;\n  \
    \  usize id;\n    Edge() = default;\n    Edge(usize from_, usize to_, cost_type\
    \ cost_, usize id_):\n      from(from_), to(to_), cost(cost_), id(id_) {}\n  };\n\
    \n  template< typename cost_type >\n  using Edges = std::vector< Edge<cost_type>\
    \ >;\n\n  template< typename cost_type >\n  class Graph {\n    std::vector< std::vector<Edge<cost_type>>\
    \ > g;\n    usize edge_count;\n\n   public:\n    Graph() = default;\n    explicit\
    \ Graph(usize n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return\
    \ g.size();\n    }\n\n    void add_directed_edge(usize from, usize to, cost_type\
    \ cost = 1) {\n      g[from].emplace_back(from, to, cost, edge_count++);\n   \
    \ }\n\n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n\
    \      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    inline Edges< cost_type > &operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    inline const Edges< cost_type\
    \ > &operator[](const usize &v) const {\n      return g[v];\n    }\n  };\n\n}\n\
    #line 1 \"src/graph/dijkstra.hpp\"\n#include <limits>\n#include <utility>\n#include\
    \ <queue>\n\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\n\nnamespace\
    \ luz {\n\n  template <typename T1, typename T2>\n  inline bool chmax(T1 &a, T2\
    \ b) {\n    return a < b and (a = b, true);\n  }\n\n  template <typename T1, typename\
    \ T2>\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n#line 7 \"src/graph/dijkstra.hpp\"\n\nnamespace luz\
    \ {\n\n  template< typename cost_type >\n  class Dijkstra {\n    static constexpr\
    \ usize undefined_ = std::numeric_limits<usize>::max();\n    static constexpr\
    \ cost_type inf_ = std::numeric_limits<cost_type>::max();\n  \n    Graph< cost_type\
    \ > g;\n    usize g_size;\n    std::vector< cost_type > ds;\n    std::vector<\
    \ usize > froms, ids;\n  \n    void dijkstra(usize s) {\n      using pq_type =\
    \ std::pair< cost_type, usize >;\n      std::priority_queue< pq_type, std::vector<pq_type>,\
    \ std::greater<pq_type> > pq;\n  \n      ds[s] = 0;\n      pq.emplace(ds[s], s);\n\
    \  \n      while (not pq.empty()) {\n        auto [cost, v] = pq.top();\n    \
    \    pq.pop();\n  \n        if (ds[v] < cost) continue;\n        for (auto &e:\
    \ g[v]) {\n          if (chmin(ds[e.to], cost + e.cost)) {\n            pq.emplace(ds[e.to],\
    \ e.to);\n            froms[e.to] = v;\n            ids[e.to] = e.id;\n      \
    \    }\n        }\n      }\n    }\n  \n   public:\n    explicit Dijkstra(const\
    \ Graph< cost_type > &g_, usize source) : \n        g(g_), g_size(g.size()), ds(g_size,\
    \ inf_), \n        froms(g_size, undefined_), ids(g_size, undefined_) {\n    \
    \  dijkstra(source);\n    }\n  \n    inline usize undefined() const {\n      return\
    \ undefined_;\n    }\n  \n    inline cost_type inf() const {\n      return inf_;\n\
    \    }\n  \n    inline cost_type dist(const usize v) const {\n      return ds[v];\n\
    \    }\n  \n    inline usize from_on_shortest_path_tree(const usize v) const {\n\
    \      return froms[v];\n    }\n  \n    inline usize edge_label(const usize v)\
    \ const {\n      return ids[v];\n    }\n  \n    inline Graph< cost_type > get_original_graph()\
    \ const {\n      return g;\n    }\n  \n    inline std::vector< cost_type > get_distances()\
    \ const {\n      return ds;\n    }\n  \n    inline std::vector< usize > get_shortest_path_tree()\
    \ const {\n      return froms;\n    }\n  \n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n}\n#line 11 \"test/aoj/grl-1-a.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    usize v = input(), e = input(), source\
    \ = input();\n\n    Graph< u32 > G(v);\n    for (usize _: rep(0, e)) {\n     \
    \ usize s = input(), t = input();\n      u32 d = input();\n      G.add_directed_edge(s,\
    \ t, d);\n    }\n\n    Dijkstra dijkstra(G, source);\n    auto dists = dijkstra.get_distances();\n\
    \    for (auto &dist: dists) {\n      if (dist == dijkstra.inf()) {\n        std::cout\
    \ << \"INF\" << std::endl;\n      } else {\n        std::cout << dist << std::endl;\n\
    \      }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\n\
    \n#include <iostream>\n\n#include \"src/cpp-template/header/input.hpp\"\n#include\
    \ \"src/cpp-template/header/type-alias.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n\n#include \"src/graph/graph-template.hpp\"\n#include \"src/graph/dijkstra.hpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    usize v = input(), e = input(), source\
    \ = input();\n\n    Graph< u32 > G(v);\n    for (usize _: rep(0, e)) {\n     \
    \ usize s = input(), t = input();\n      u32 d = input();\n      G.add_directed_edge(s,\
    \ t, d);\n    }\n\n    Dijkstra dijkstra(G, source);\n    auto dists = dijkstra.get_distances();\n\
    \    for (auto &dist: dists) {\n      if (dist == dijkstra.inf()) {\n        std::cout\
    \ << \"INF\" << std::endl;\n      } else {\n        std::cout << dist << std::endl;\n\
    \      }\n    }\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/cpp-template/header/input.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/graph/graph-template.hpp
  - src/graph/dijkstra.hpp
  - src/cpp-template/header/change-minmax.hpp
  isVerificationFile: true
  path: test/aoj/grl-1-a.test.cpp
  requiredBy: []
  timestamp: '2022-07-16 03:55:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl-1-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl-1-a.test.cpp
- /verify/test/aoj/grl-1-a.test.cpp.html
title: test/aoj/grl-1-a.test.cpp
---
