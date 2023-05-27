---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/single-source-shortest-path/in-weighted-graph.hpp
    title: "\u91CD\u307F\u3042\u308A\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
      \ (Single Source Shortest Path in Unweighted Graph, SPFA)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/dynamic-graph.test.cpp
    title: test/aoj/grl_1_a/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_b/dynamic-graph.test.cpp
    title: test/aoj/grl_1_b/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_b/static-graph.test.cpp
    title: test/aoj/grl_1_b/static-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/class/dynamic-graph.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/graph/class/dynamic-graph.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename Edge\
    \ >\n  class DynamicGraph {\n\n    using Edges = std::vector< Edge >;\n\n   protected:\n\
    \    std::vector< Edges > g;\n    usize edge_count;\n\n   public:\n    using cost_type\
    \ = typename Edge::cost_type;\n\n    DynamicGraph() = default;\n    explicit DynamicGraph(usize\
    \ n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return g.size();\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      assert(from < size());\n      assert(to < size());\n      g[from].emplace_back(from,\
    \ to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize u, usize\
    \ v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v < size());\n\
    \      assert(u != v);\n      g[u].emplace_back(u, v, cost, edge_count);\n   \
    \   g[v].emplace_back(v, u, cost, edge_count++);\n    }\n\n    Edges operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    const Edges operator[](const usize\
    \ &v) const {\n      return g[v];\n    }\n  };\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename Edge\
    \ >\n  class DynamicGraph {\n\n    using Edges = std::vector< Edge >;\n\n   protected:\n\
    \    std::vector< Edges > g;\n    usize edge_count;\n\n   public:\n    using cost_type\
    \ = typename Edge::cost_type;\n\n    DynamicGraph() = default;\n    explicit DynamicGraph(usize\
    \ n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return g.size();\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      assert(from < size());\n      assert(to < size());\n      g[from].emplace_back(from,\
    \ to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize u, usize\
    \ v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v < size());\n\
    \      assert(u != v);\n      g[u].emplace_back(u, v, cost, edge_count);\n   \
    \   g[v].emplace_back(v, u, cost, edge_count++);\n    }\n\n    Edges operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    const Edges operator[](const usize\
    \ &v) const {\n      return g[v];\n    }\n  };\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/class/dynamic-graph.hpp
  requiredBy:
  - src/graph/single-source-shortest-path/in-weighted-graph.hpp
  timestamp: '2023-05-28 01:36:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_1_a/dynamic-graph.test.cpp
  - test/aoj/grl_1_b/dynamic-graph.test.cpp
  - test/aoj/grl_1_b/static-graph.test.cpp
documentation_of: src/graph/class/dynamic-graph.hpp
layout: document
title: "\u52D5\u7684\u306A\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
---

## コンストラクタ
```
DynamicGraph< edge >(usize n)
```

頂点数 `n` のグラフを定義する。

### 制約
- $0 \leq n$

### `edge` の制約
- 辺のコストを表す型として `cost_type` が公開されていること。
- 辺の始点、終点、コスト、辺番号としてメンバ変数 `from`, `to`, `cost`, `id` をもつこと。また、この順にコンストラクタを呼べること。

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
