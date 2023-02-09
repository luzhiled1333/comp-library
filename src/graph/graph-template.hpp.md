---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: src/graph/distances-on-unweighted-graph.hpp
    title: src/graph/distances-on-unweighted-graph.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/functional-graph-utility.hpp
    title: src/graph/functional-graph-utility.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-jump-on-functional-graph.hpp
    title: "(offine) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$\
      \ \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Offline Jump On Functional\
      \ Graph)"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-jump-on-tree.hpp
    title: "(offine) \u6728\u306E\u30D1\u30B9 $u-v$ \u4E0A\u306E $k$ \u756A\u76EE\u306E\
      \u9802\u70B9 (Offline Jump On Tree)"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-level-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3 Level Ancestor (Offline Level Ancestor)"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-lowest-common-ancestor.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\u7956\u5148 (Offline\
      \ Lowest Common Ancestor)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a.test.cpp
    title: test/aoj/grl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_5_c.test.cpp
    title: test/aoj/grl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/offline-algorithm.test.cpp
    title: test/atcoder/abc258_e/offline-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/online-algorithm.test.cpp
    title: test/atcoder/abc258_e/online-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/jump_on_tree.test.cpp
    title: test/library-checker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/graph-template.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/graph/graph-template.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename cost_type >\n  class\
    \ Edge {\n   public:\n    usize from, to;\n    cost_type cost;\n    usize id;\n\
    \    Edge() = default;\n    Edge(usize from_, usize to_, cost_type cost_, usize\
    \ id_)\n        : from(from_),\n          to(to_),\n          cost(cost_),\n \
    \         id(id_) {}\n  };\n\n  template < typename cost_type >\n  using Edges\
    \ = std::vector< Edge< cost_type > >;\n\n  template < typename cost_type >\n \
    \ class Graph {\n   protected:\n    std::vector< std::vector< Edge< cost_type\
    \ > > > g;\n    usize edge_count;\n\n   public:\n    Graph() = default;\n    explicit\
    \ Graph(usize n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return\
    \ g.size();\n    }\n\n    void add_directed_edge(usize from, usize to, cost_type\
    \ cost = 1) {\n      assert(from < size());\n      assert(to < size());\n    \
    \  g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize\
    \ u, usize v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v\
    \ < size());\n      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    inline Edges< cost_type > &operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    inline const Edges< cost_type\
    \ > &operator[](\n        const usize &v) const {\n      return g[v];\n    }\n\
    \  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename cost_type\
    \ >\n  class Edge {\n   public:\n    usize from, to;\n    cost_type cost;\n  \
    \  usize id;\n    Edge() = default;\n    Edge(usize from_, usize to_, cost_type\
    \ cost_, usize id_)\n        : from(from_),\n          to(to_),\n          cost(cost_),\n\
    \          id(id_) {}\n  };\n\n  template < typename cost_type >\n  using Edges\
    \ = std::vector< Edge< cost_type > >;\n\n  template < typename cost_type >\n \
    \ class Graph {\n   protected:\n    std::vector< std::vector< Edge< cost_type\
    \ > > > g;\n    usize edge_count;\n\n   public:\n    Graph() = default;\n    explicit\
    \ Graph(usize n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return\
    \ g.size();\n    }\n\n    void add_directed_edge(usize from, usize to, cost_type\
    \ cost = 1) {\n      assert(from < size());\n      assert(to < size());\n    \
    \  g[from].emplace_back(from, to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize\
    \ u, usize v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v\
    \ < size());\n      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    inline Edges< cost_type > &operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    inline const Edges< cost_type\
    \ > &operator[](\n        const usize &v) const {\n      return g[v];\n    }\n\
    \  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/graph-template.hpp
  requiredBy:
  - src/graph/distances-on-unweighted-graph.hpp
  - src/graph/offline-query-level-ancestor.hpp
  - src/graph/functional-graph-utility.hpp
  - src/graph/dijkstra.hpp
  - src/graph/offline-query-jump-on-tree.hpp
  - src/graph/offline-query-lowest-common-ancestor.hpp
  - src/graph/offline-query-jump-on-functional-graph.hpp
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_5_c.test.cpp
  - test/aoj/grl_1_a.test.cpp
  - test/library-checker/jump_on_tree.test.cpp
  - test/atcoder/abc258_e/online-algorithm.test.cpp
  - test/atcoder/abc258_e/offline-algorithm.test.cpp
  - unit-test/graph/offline-query-jump-on-functional-graph.test.cpp
documentation_of: src/graph/graph-template.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
---

## コンストラクタ
```
Graph(usize n)
```

頂点数 `n` のグラフを定義する。

### 制約
- $0 \leq n$

## size
```
usize size()
```

グラフの頂点数を返す。

## add_directed_edge
```
void add_directed_edge(usize from, usize to, cost_type cost = 1)
```

`from` から `to` へのコスト`cost`の有向辺をグラフに追加する。 `cost` を指定しなかった場合、その辺のコストは 1 になる。

辺には追加された順に 0-indexed で辺番号が割り振られる。

## add_undirected_edge
```
void add_undirected_edge(usize u, usize v, cost_type cost = 1)
```

`u` から `v` へのコスト `cost` の無向辺をグラフに追加する。 `cost` を指定しなかった場合、その辺のコストは 1 になる。

辺には追加された順に 0-indexed で辺番号が割り振られる。

## operator[]
```
(1)       Edges &operator[](const usize &v)
(2) const Edges &operator[](const usize &v) const
```

`v` を始点とする辺のリストを返す。
