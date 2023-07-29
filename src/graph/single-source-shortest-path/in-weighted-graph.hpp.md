---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/graph/single-source-shortest-path/in-weighted-graph.hpp\"\
    \n\n#include <limits>\n#include <queue>\n#include <vector>\n\nnamespace luz::sssp\
    \ {\n\n  template < class G >\n  class InWeightedGraph {\n    using cost_type\
    \ = typename G::cost_type;\n    using graph     = G;\n\n    static constexpr cost_type\
    \ inf_ =\n        std::numeric_limits< cost_type >::max();\n    static constexpr\
    \ cost_type negative_inf_ =\n        std::numeric_limits< cost_type >::min();\n\
    \    static constexpr usize undefined_ =\n        std::numeric_limits< usize >::max();\n\
    \n    graph g;\n    usize g_size;\n    usize source;\n\n    std::vector< cost_type\
    \ > ds;\n    std::vector< usize > parents, ids;\n\n    void spfa(usize s) {\n\
    \      std::queue< usize > que;\n      std::vector< usize > ds_update_cnt(g_size);\n\
    \      std::vector< bool > in_que(g_size);\n\n      ds[s]            = 0;\n  \
    \    in_que[s]        = true;\n      ds_update_cnt[s] = 0;\n      que.emplace(s);\n\
    \n      while (not que.empty()) {\n        usize v = que.front();\n        que.pop();\n\
    \        in_que[v] = false;\n\n        for (const auto &e: g[v]) {\n         \
    \ usize u        = e.to;\n          cost_type cost = e.cost;\n          if (ds[v]\
    \ + cost >= ds[u]) {\n            continue;\n          }\n\n          ds[u]  \
    \    = ds[v] + cost;\n          parents[u] = v;\n          ids[u]     = e.id;\n\
    \n          if (in_que[u]) {\n            continue;\n          }\n\n         \
    \ in_que[u] = true;\n          ds_update_cnt[u]++;\n\n          if (ds_update_cnt[u]\
    \ < 2 * g_size) {\n            que.emplace(u);\n          }\n        }\n     \
    \ }\n\n      for (usize v: rep(0, g_size)) {\n        if (ds_update_cnt[v] >=\
    \ g_size) {\n          ds[v]      = negative_inf();\n          parents[v] = undefined();\n\
    \          ids[v]     = undefined();\n        }\n      }\n    }\n\n   public:\n\
    \    explicit InWeightedGraph(const graph &g_, usize source_)\n        : g(g_),\n\
    \          g_size(g.size()),\n          source(source_),\n          ds(g_size,\
    \ inf()),\n          parents(g_size, undefined()),\n          ids(g_size, undefined())\
    \ {\n      spfa(source);\n    }\n\n    graph get_original_graph() const {\n  \
    \    return g;\n    }\n\n    static inline cost_type inf() {\n      return inf_;\n\
    \    }\n\n    static inline cost_type negative_inf() {\n      return negative_inf_;\n\
    \    }\n\n    inline cost_type distance(const usize v) const {\n      return ds[v];\n\
    \    }\n\n    inline std::vector< cost_type > get_distances() const {\n      return\
    \ ds;\n    }\n\n    static inline usize undefined() {\n      return undefined_;\n\
    \    }\n\n    inline usize parent(const usize v) const {\n      return parents[v];\n\
    \    }\n\n    inline std::vector< usize > get_parents() const {\n      return\
    \ parents;\n    }\n\n    inline usize edge_label(const usize v) const {\n    \
    \  return ids[v];\n    }\n\n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n} // namespace luz::sssp\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\nnamespace luz::sssp {\n\n \
    \ template < class G >\n  class InWeightedGraph {\n    using cost_type = typename\
    \ G::cost_type;\n    using graph     = G;\n\n    static constexpr cost_type inf_\
    \ =\n        std::numeric_limits< cost_type >::max();\n    static constexpr cost_type\
    \ negative_inf_ =\n        std::numeric_limits< cost_type >::min();\n    static\
    \ constexpr usize undefined_ =\n        std::numeric_limits< usize >::max();\n\
    \n    graph g;\n    usize g_size;\n    usize source;\n\n    std::vector< cost_type\
    \ > ds;\n    std::vector< usize > parents, ids;\n\n    void spfa(usize s) {\n\
    \      std::queue< usize > que;\n      std::vector< usize > ds_update_cnt(g_size);\n\
    \      std::vector< bool > in_que(g_size);\n\n      ds[s]            = 0;\n  \
    \    in_que[s]        = true;\n      ds_update_cnt[s] = 0;\n      que.emplace(s);\n\
    \n      while (not que.empty()) {\n        usize v = que.front();\n        que.pop();\n\
    \        in_que[v] = false;\n\n        for (const auto &e: g[v]) {\n         \
    \ usize u        = e.to;\n          cost_type cost = e.cost;\n          if (ds[v]\
    \ + cost >= ds[u]) {\n            continue;\n          }\n\n          ds[u]  \
    \    = ds[v] + cost;\n          parents[u] = v;\n          ids[u]     = e.id;\n\
    \n          if (in_que[u]) {\n            continue;\n          }\n\n         \
    \ in_que[u] = true;\n          ds_update_cnt[u]++;\n\n          if (ds_update_cnt[u]\
    \ < 2 * g_size) {\n            que.emplace(u);\n          }\n        }\n     \
    \ }\n\n      for (usize v: rep(0, g_size)) {\n        if (ds_update_cnt[v] >=\
    \ g_size) {\n          ds[v]      = negative_inf();\n          parents[v] = undefined();\n\
    \          ids[v]     = undefined();\n        }\n      }\n    }\n\n   public:\n\
    \    explicit InWeightedGraph(const graph &g_, usize source_)\n        : g(g_),\n\
    \          g_size(g.size()),\n          source(source_),\n          ds(g_size,\
    \ inf()),\n          parents(g_size, undefined()),\n          ids(g_size, undefined())\
    \ {\n      spfa(source);\n    }\n\n    graph get_original_graph() const {\n  \
    \    return g;\n    }\n\n    static inline cost_type inf() {\n      return inf_;\n\
    \    }\n\n    static inline cost_type negative_inf() {\n      return negative_inf_;\n\
    \    }\n\n    inline cost_type distance(const usize v) const {\n      return ds[v];\n\
    \    }\n\n    inline std::vector< cost_type > get_distances() const {\n      return\
    \ ds;\n    }\n\n    static inline usize undefined() {\n      return undefined_;\n\
    \    }\n\n    inline usize parent(const usize v) const {\n      return parents[v];\n\
    \    }\n\n    inline std::vector< usize > get_parents() const {\n      return\
    \ parents;\n    }\n\n    inline usize edge_label(const usize v) const {\n    \
    \  return ids[v];\n    }\n\n    inline std::vector< usize > get_edge_labels()\
    \ const {\n      return ids;\n    }\n  };\n\n} // namespace luz::sssp\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/graph/single-source-shortest-path/in-weighted-graph.hpp
  requiredBy: []
  timestamp: '2023-07-29 18:03:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl_1_b/dynamic-graph.test.cpp
  - test/aoj/grl_1_b/static-graph.test.cpp
documentation_of: src/graph/single-source-shortest-path/in-weighted-graph.hpp
layout: document
title: "\u91CD\u307F\u3042\u308A\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF (Single\
  \ Source Shortest Path in Unweighted Graph, SPFA)"
---

## Appendix
[単一始点最短経路問題の solver の細かい仕様について]({{ site.baseurl }}/appendix-single-source-shortest-path-solver)

[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
sssp::InWeightedGraph(const G &g, usize s)
```

頂点 $s$ からの重みあり単一始点最短経路問題を解く。

コンストラクタ内部では以下が行われている。

- 始点から各頂点への最短経路のコストの計算
- 以下で特定される最短経路木を一つ構成
  - 親の頂点番号
  - 親との間にある辺の辺番号

### 計算量
- $O(\|V\| \|E\|)$

## get_original_graph
```
G get_original_graph() const
```

もとのグラフを返す。

## inf
```
static cost_type inf()
```

$s$ からの経路が存在しないような頂点 $v$ への $s$ からの最短経路のコストとして定義されている値を返す。

内部では `std::numeric_limits< cost_type >::max()` によって定義されている。

## negative_inf
```
static cost_type negative_inf()
```

$s$ から $v$ への経路に負閉路が含まれる場合の最短経路のコストとして定義されている値を返す。


内部では `std::numeric_limits< cost_type >::min()` によって定義されている。

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
static usize undefined()
```

構成された最短経路木において親が存在しない、または経路上に負閉路が含まれるときに返される値。

内部では `std::numeric_limits< usize >::max()` によって定義されている。

## parent
```
usize parent(const usize v) const
```

構成された最短経路木においての `v` の親を返す。

親が存在しない、または経路上に負閉路が含まれる場合 `undefined()` が返される。


## get_parents 
```
std::vector< usize > get_parents() const
```

各頂点に対する `parent` を `std::vector` で wrap して返す。`parent(v)` は `v` 番目の要素として表される。

親が存在しない、または経路上に負閉路が含まれる頂点に対応する要素は `undefined()` となる。

## edge_label
```
usize edge_label(const usize v) const
```

構成された最短経路木における `v` とその親との間にある辺の、もとのグラフでの辺番号を返す。

親が存在しない、または経路上に負閉路が含まれる場合 `undefined()` が返される。

## get_edge_labels
```
usize get_edge_labels() const
```

各頂点に対する `edge_label(v)` を `std::vector` で wrap して返す。`edge_label(v)` は `v` 番目の要素として表される。

親が存在しない、または経路上に負閉路が含まれる頂点に対応する要素は `undefined()` となる。
