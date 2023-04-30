---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/change-minmax.hpp
    title: chmin / chmax
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a.test.cpp
    title: test/aoj/grl_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/change-minmax.hpp\"\n\nnamespace luz {\n\
    \n  template < typename T1, typename T2 >\n  inline bool chmax(T1 &a, T2 b) {\n\
    \    return a < b and (a = b, true);\n  }\n\n  template < typename T1, typename\
    \ T2 >\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n#line 2 \"src/graph/graph-template.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include\
    \ <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize\
    \ = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/graph/graph-template.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace luz {\n\n  template < typename cost_type >\n  class Edge\
    \ {\n   public:\n    usize from, to;\n    cost_type cost;\n    usize id;\n   \
    \ Edge() = default;\n    Edge(usize from_, usize to_, cost_type cost_, usize id_)\n\
    \        : from(from_),\n          to(to_),\n          cost(cost_),\n        \
    \  id(id_) {}\n  };\n\n  template < typename cost_type >\n  using Edges = std::vector<\
    \ Edge< cost_type > >;\n\n  template < typename cost_type >\n  class Graph {\n\
    \   protected:\n    std::vector< std::vector< Edge< cost_type > > > g;\n    usize\
    \ edge_count;\n\n   public:\n    Graph() = default;\n    explicit Graph(usize\
    \ n): g(n), edge_count(0) {}\n\n    usize size() const {\n      return g.size();\n\
    \    }\n\n    void add_directed_edge(usize from, usize to, cost_type cost = 1)\
    \ {\n      assert(from < size());\n      assert(to < size());\n      g[from].emplace_back(from,\
    \ to, cost, edge_count++);\n    }\n\n    void add_undirected_edge(usize u, usize\
    \ v, cost_type cost = 1) {\n      assert(u < size());\n      assert(v < size());\n\
    \      g[u].emplace_back(u, v, cost, edge_count);\n      g[v].emplace_back(v,\
    \ u, cost, edge_count++);\n    }\n\n    inline Edges< cost_type > &operator[](const\
    \ usize &v) {\n      return g[v];\n    }\n\n    inline const Edges< cost_type\
    \ > &operator[](\n        const usize &v) const {\n      return g[v];\n    }\n\
    \  };\n\n} // namespace luz\n#line 5 \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\n#include <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #line 11 \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\nnamespace luz::sssp {\n\n  template < typename cost_type >\n  class InNonNegativeWeightedGraph\
    \ {\n\n    static constexpr usize undefined_ =\n        std::numeric_limits< usize\
    \ >::max();\n    static constexpr cost_type inf_ =\n        std::numeric_limits<\
    \ cost_type >::max();\n\n    Graph< cost_type > g;\n    usize g_size;\n    std::vector<\
    \ cost_type > ds;\n    std::vector< usize > parents, ids;\n\n    void dijkstra(usize\
    \ s) {\n      using pq_type = std::pair< cost_type, usize >;\n      std::priority_queue<\
    \ pq_type, std::vector< pq_type >,\n                           std::greater< pq_type\
    \ > >\n          pq;\n\n      ds[s] = 0;\n      pq.emplace(ds[s], s);\n\n    \
    \  while (not pq.empty()) {\n        auto [cost, v] = pq.top();\n        pq.pop();\n\
    \n        if (ds[v] < cost) continue;\n        for (auto &e: g[v]) {\n       \
    \   if (chmin(ds[e.to], cost + e.cost)) {\n            pq.emplace(ds[e.to], e.to);\n\
    \            parents[e.to] = v;\n            ids[e.to]     = e.id;\n         \
    \ }\n        }\n      }\n    }\n\n   public:\n    explicit InNonNegativeWeightedGraph(const\
    \ Graph< cost_type > &g_,\n                                        usize source)\n\
    \        : g(g_),\n          g_size(g.size()),\n          ds(g_size, inf_),\n\
    \          parents(g_size, undefined_),\n          ids(g_size, undefined_) {\n\
    \      dijkstra(source);\n    }\n\n    inline Graph< cost_type > get_original_graph()\
    \ const {\n      return g;\n    }\n\n    static inline cost_type inf() {\n   \
    \   return inf_;\n    }\n\n    inline cost_type distance(const usize v) const\
    \ {\n      return ds[v];\n    }\n\n    inline std::vector< cost_type > get_distances()\
    \ const {\n      return ds;\n    }\n\n    static inline usize undefined() {\n\
    \      return undefined_;\n    }\n\n    inline usize parent(const usize v) const\
    \ {\n      return parents[v];\n    }\n\n    inline std::vector< usize > get_parents()\
    \ const {\n      return parents;\n    }\n\n    inline usize edge_label(const usize\
    \ v) const {\n      return ids[v];\n    }\n\n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n} // namespace luz::sssp\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/change-minmax.hpp\"\n\
    #include \"src/graph/graph-template.hpp\"\n\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace luz::sssp\
    \ {\n\n  template < typename cost_type >\n  class InNonNegativeWeightedGraph {\n\
    \n    static constexpr usize undefined_ =\n        std::numeric_limits< usize\
    \ >::max();\n    static constexpr cost_type inf_ =\n        std::numeric_limits<\
    \ cost_type >::max();\n\n    Graph< cost_type > g;\n    usize g_size;\n    std::vector<\
    \ cost_type > ds;\n    std::vector< usize > parents, ids;\n\n    void dijkstra(usize\
    \ s) {\n      using pq_type = std::pair< cost_type, usize >;\n      std::priority_queue<\
    \ pq_type, std::vector< pq_type >,\n                           std::greater< pq_type\
    \ > >\n          pq;\n\n      ds[s] = 0;\n      pq.emplace(ds[s], s);\n\n    \
    \  while (not pq.empty()) {\n        auto [cost, v] = pq.top();\n        pq.pop();\n\
    \n        if (ds[v] < cost) continue;\n        for (auto &e: g[v]) {\n       \
    \   if (chmin(ds[e.to], cost + e.cost)) {\n            pq.emplace(ds[e.to], e.to);\n\
    \            parents[e.to] = v;\n            ids[e.to]     = e.id;\n         \
    \ }\n        }\n      }\n    }\n\n   public:\n    explicit InNonNegativeWeightedGraph(const\
    \ Graph< cost_type > &g_,\n                                        usize source)\n\
    \        : g(g_),\n          g_size(g.size()),\n          ds(g_size, inf_),\n\
    \          parents(g_size, undefined_),\n          ids(g_size, undefined_) {\n\
    \      dijkstra(source);\n    }\n\n    inline Graph< cost_type > get_original_graph()\
    \ const {\n      return g;\n    }\n\n    static inline cost_type inf() {\n   \
    \   return inf_;\n    }\n\n    inline cost_type distance(const usize v) const\
    \ {\n      return ds[v];\n    }\n\n    inline std::vector< cost_type > get_distances()\
    \ const {\n      return ds;\n    }\n\n    static inline usize undefined() {\n\
    \      return undefined_;\n    }\n\n    inline usize parent(const usize v) const\
    \ {\n      return parents[v];\n    }\n\n    inline std::vector< usize > get_parents()\
    \ const {\n      return parents;\n    }\n\n    inline usize edge_label(const usize\
    \ v) const {\n      return ids[v];\n    }\n\n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n} // namespace luz::sssp\n"
  dependsOn:
  - src/cpp-template/header/change-minmax.hpp
  - src/graph/graph-template.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
  requiredBy: []
  timestamp: '2023-04-30 17:38:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_1_a.test.cpp
documentation_of: src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
layout: document
title: "\u975E\u8CA0\u91CD\u307F\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF (Single\
  \ Source Shortest Path in Non-negative Weighted Graph, Dijkstra's Algorithm)"
---

## Appendix
[単一始点最短経路問題の solver の細かい仕様について]({{ site.baseurl }}/appendix-single-source-shortest-path-solver)

## コンストラクタ
```
sssp::InNonNegativeWeightedGraph(const Graph<cost_type> &g, usize s)
```

負辺がないようなグラフ $G$ において、頂点 $s$ からの単一始点最短経路問題を解く。

コンストラクタ内部では以下が行われている。

- 始点から各頂点への最短経路のコストの計算
- 以下で特定される最短経路木を一つ構成
  - 親の頂点番号
  - 親との間にある辺の辺番号

### 制約
- 各辺のコストは非負整数である。
- 任意の頂点について $s$ からの最短経路のコストが `cost_type` に収まる。

### 計算量
- $O((\|E\| + \|V\|) \log \|V\|)$

## get_original_graph
```
Graph< cost_type > get_original_graph() const
```

もとのグラフを返す。

## inf
```
cost_type inf() const
```

$s$ からの経路が存在しないような頂点 $v$ への $s$ からの最短経路のコストとして定義されている値を返す。

内部では `std::numeric_limits< cost_type >::max()` によって定義されている。

## distance
```
cost_type distance(const usize v) const
```

$s$ から $v$ への最短経路のコストを返す。経路が存在しない場合のコストは `inf()` として定義されている。

## get_distances
```
std::vector< cost_type > get_distances() const
```

各頂点に対する `distance` を `std::vector` で wrap して返す。`distance(v)` は `v` 番目の要素として表される。

$s$ からの経路が存在しないような頂点へのコストは `inf()` として定義されている。

## undefined
```
usize undefined() const
```

構成された最短経路木において親が存在しないときに返される値。

内部では `std::numeric_limits< usize >::max()` によって定義されている。

## parent
```
usize parent(const usize v) const
```

構成された最短経路木においての `v` の親を返す。

親が存在しない場合 `undefined()` が返される。

## get_parents
```
std::vector< usize > get_parents() const
```

各頂点に対する `parent` を `std::vector` で wrap して返す。`parent(v)` は `v` 番目の要素として表される。

親が存在しないような頂点の場合は `undefined()` となる。

## edge_label
```
usize edge_label(const usize v) const
```

構成された最短経路木における `v` とその親との間にある辺の、もとのグラフでの辺番号を返す。

親が存在しない場合 `undefined()` が返される。

## get_edge_labels
```
usize get_edge_labels() const
```

各頂点に対する `edge_label(v)` を `std::vector` で wrap して返す。`edge_label(v)` は `v` 番目の要素として表される。

親が存在しないような頂点に対応する要素は `undefined()` となる。

