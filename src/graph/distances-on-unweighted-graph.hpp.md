---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-jump-on-tree.hpp
    title: "(offine) \u6728\u306E\u30D1\u30B9 $u-v$ \u4E0A\u306E $k$ \u756A\u76EE\u306E\
      \u9802\u70B9 (Offline Jump On Tree)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/distances-on-unweighted-graph.hpp\"\n\n#line 2\
    \ \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include <cstdint>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n\
    \  using u64 = std::uint64_t;\n\n} // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\
    \n\n#line 4 \"src/graph/graph-template.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz {\n\n  template < typename cost_type >\n  class Edge {\n   public:\n\
    \    usize from, to;\n    cost_type cost;\n    usize id;\n    Edge() = default;\n\
    \    Edge(usize from_, usize to_, cost_type cost_, usize id_)\n        : from(from_),\n\
    \          to(to_),\n          cost(cost_),\n          id(id_) {}\n  };\n\n  template\
    \ < typename cost_type >\n  using Edges = std::vector< Edge< cost_type > >;\n\n\
    \  template < typename cost_type >\n  class Graph {\n   protected:\n    std::vector<\
    \ std::vector< Edge< cost_type > > > g;\n    usize edge_count;\n\n   public:\n\
    \    Graph() = default;\n    explicit Graph(usize n): g(n), edge_count(0) {}\n\
    \n    usize size() const {\n      return g.size();\n    }\n\n    void add_directed_edge(usize\
    \ from, usize to, cost_type cost = 1) {\n      assert(from < size());\n      assert(to\
    \ < size());\n      g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\
    \n    void add_undirected_edge(usize u, usize v, cost_type cost = 1) {\n     \
    \ assert(u < size());\n      assert(v < size());\n      g[u].emplace_back(u, v,\
    \ cost, edge_count);\n      g[v].emplace_back(v, u, cost, edge_count++);\n   \
    \ }\n\n    inline Edges< cost_type > &operator[](const usize &v) {\n      return\
    \ g[v];\n    }\n\n    inline const Edges< cost_type > &operator[](\n        const\
    \ usize &v) const {\n      return g[v];\n    }\n  };\n\n} // namespace luz\n#line\
    \ 5 \"src/graph/distances-on-unweighted-graph.hpp\"\n\n#include <limits>\n#include\
    \ <queue>\n#line 9 \"src/graph/distances-on-unweighted-graph.hpp\"\n\nnamespace\
    \ luz {\n\n  template < typename cost_type >\n  std::vector< usize > distances_on_unweighted_graph(\n\
    \      const Graph< cost_type > &g, usize root) {\n    usize not_reached = std::numeric_limits<\
    \ usize >::max();\n    std::vector< usize > distances(g.size(), not_reached);\n\
    \    distances[root] = 0;\n\n    std::queue< usize > que;\n    que.emplace(root);\n\
    \n    while (not que.empty()) {\n      usize v = que.front();\n      que.pop();\n\
    \n      for (const auto &e: g[v]) {\n        usize u = e.to;\n\n        if (distances[u]\
    \ != not_reached) continue;\n\n        distances[u] = distances[v] + 1;\n    \
    \    que.emplace(u);\n      }\n    }\n\n    return distances;\n  }\n\n} // namespace\
    \ luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n#include\
    \ \"src/graph/graph-template.hpp\"\n\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename cost_type >\n  std::vector<\
    \ usize > distances_on_unweighted_graph(\n      const Graph< cost_type > &g, usize\
    \ root) {\n    usize not_reached = std::numeric_limits< usize >::max();\n    std::vector<\
    \ usize > distances(g.size(), not_reached);\n    distances[root] = 0;\n\n    std::queue<\
    \ usize > que;\n    que.emplace(root);\n\n    while (not que.empty()) {\n    \
    \  usize v = que.front();\n      que.pop();\n\n      for (const auto &e: g[v])\
    \ {\n        usize u = e.to;\n\n        if (distances[u] != not_reached) continue;\n\
    \n        distances[u] = distances[v] + 1;\n        que.emplace(u);\n      }\n\
    \    }\n\n    return distances;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/graph/graph-template.hpp
  isVerificationFile: false
  path: src/graph/distances-on-unweighted-graph.hpp
  requiredBy:
  - src/graph/offline-query-jump-on-tree.hpp
  timestamp: '2023-02-05 12:10:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/jump_on_tree.test.cpp
documentation_of: src/graph/distances-on-unweighted-graph.hpp
layout: document
redirect_from:
- /library/src/graph/distances-on-unweighted-graph.hpp
- /library/src/graph/distances-on-unweighted-graph.hpp.html
title: src/graph/distances-on-unweighted-graph.hpp
---
