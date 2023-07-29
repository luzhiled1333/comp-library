---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/change-min.hpp
    title: chmin
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/dynamic-graph.test.cpp
    title: test/aoj/grl_1_a/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/static-graph.test.cpp
    title: test/aoj/grl_1_a/static-graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/change-min.hpp\"\n\nnamespace luz {\n\n\
    \  template < typename T1, typename T2 >\n  inline bool chmin(T1 &a, T2 b) {\n\
    \    return a > b and (a = b, true);\n  }\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 5 \"src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp\"\
    \n\n#include <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\nnamespace luz::sssp {\n\n  template < class G >\n  class\
    \ InNonNegativeWeightedGraph {\n    using cost_type = typename G::cost_type;\n\
    \    using graph     = G;\n\n    static constexpr usize undefined_ =\n       \
    \ std::numeric_limits< usize >::max();\n    static constexpr cost_type inf_ =\n\
    \        std::numeric_limits< cost_type >::max();\n\n    graph g;\n    usize g_size;\n\
    \    std::vector< cost_type > ds;\n    std::vector< usize > parents, ids;\n\n\
    \    void dijkstra(usize s) {\n      using pq_type = std::pair< cost_type, usize\
    \ >;\n      std::priority_queue< pq_type, std::vector< pq_type >,\n          \
    \                 std::greater< pq_type > >\n          pq;\n\n      ds[s] = 0;\n\
    \      pq.emplace(ds[s], s);\n\n      while (not pq.empty()) {\n        auto [cost,\
    \ v] = pq.top();\n        pq.pop();\n\n        if (ds[v] < cost) continue;\n \
    \       for (auto &e: g[v]) {\n          if (chmin(ds[e.to], cost + e.cost)) {\n\
    \            pq.emplace(ds[e.to], e.to);\n            parents[e.to] = v;\n   \
    \         ids[e.to]     = e.id;\n          }\n        }\n      }\n    }\n\n  \
    \ public:\n    explicit InNonNegativeWeightedGraph(const graph &g_, usize source)\n\
    \        : g(g_),\n          g_size(g.size()),\n          ds(g_size, inf_),\n\
    \          parents(g_size, undefined_),\n          ids(g_size, undefined_) {\n\
    \      dijkstra(source);\n    }\n\n    inline graph get_original_graph() const\
    \ {\n      return g;\n    }\n\n    static inline cost_type inf() {\n      return\
    \ inf_;\n    }\n\n    inline cost_type distance(const usize v) const {\n     \
    \ return ds[v];\n    }\n\n    inline std::vector< cost_type > get_distances()\
    \ const {\n      return ds;\n    }\n\n    static inline usize undefined() {\n\
    \      return undefined_;\n    }\n\n    inline usize parent(const usize v) const\
    \ {\n      return parents[v];\n    }\n\n    inline std::vector< usize > get_parents()\
    \ const {\n      return parents;\n    }\n\n    inline usize edge_label(const usize\
    \ v) const {\n      return ids[v];\n    }\n\n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n} // namespace luz::sssp\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/change-min.hpp\"\n#include\
    \ \"src/cpp-template/header/size-alias.hpp\"\n\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ luz::sssp {\n\n  template < class G >\n  class InNonNegativeWeightedGraph {\n\
    \    using cost_type = typename G::cost_type;\n    using graph     = G;\n\n  \
    \  static constexpr usize undefined_ =\n        std::numeric_limits< usize >::max();\n\
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
    \ };\n\n} // namespace luz::sssp\n"
  dependsOn:
  - src/cpp-template/header/change-min.hpp
  - src/cpp-template/header/size-alias.hpp
  isVerificationFile: false
  path: src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_1_a/dynamic-graph.test.cpp
  - test/aoj/grl_1_a/static-graph.test.cpp
documentation_of: src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
layout: document
title: "\u975E\u8CA0\u91CD\u307F\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF (Single\
  \ Source Shortest Path in Non-negative Weighted Graph, Dijkstra's Algorithm)"
---

## Appendix
[単一始点最短経路問題の solver の細かい仕様について]({{ site.baseurl }}/appendix-single-source-shortest-path-solver)

[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
sssp::InNonNegativeWeightedGraph(const G &g, usize s)
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
G get_original_graph() const
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

