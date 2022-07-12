---
title: Dijkstra's Algorithm
documentation_of: //src/graph/dijkstra.hpp
---

## コンストラクタ
```
Dijkstra(const Graph<cost_type> &g_, usize source);
```

頂点 `source` からの単一始点最短経路問題を解く。

このとき、各頂点に対し

1. 始点からの距離
1. 最短経路木上での親の頂点番号
1. 最短経路木上での親との間にある辺の辺番号

を計算している。

### 制約
- 各辺のコストは非負整数である。
- 任意の頂点について `source` からの最短経路のコストが `cost_type` に収まる。

### 計算量
- $O(E + V \log V)$

## dist
```
cost_type dist(const usize v)
```

`source` から `v` への最短経路のコストを返す。

最短経路が存在しない場合は `inf()` が返される。

## get_distances
```
std::vector< cost_type > get_distances()
```

`source` から各頂点への最短経路のコストの配列を返す。

最短経路が存在しない頂点の値は `inf()` となる。

## from_on_shortest_path_tree
```
usize from_on_shortest_path_tree(const usize v)
```

`source` からの最短経路木においての `v` の親を返す。

親が存在しない場合 `undefined()` が返される。

## get_shortest_path_tree
```
std::vector< usize > get_shortest_path_tree()
```

`source` からの最短経路木の一つを、頂点 `v` の親は `v` 番目の要素として表した `vector` で返す。

親が存在しないような頂点に対応する要素は `undefined()` となる。

## edge_label
```
usize edge_label(const usize v)
```

`source` からの最短経路木において、親との間の辺の番号を返す。

親が存在しない場合 `undefined()` が返される。

## get_edge_labels
```
usize get_edge_labels()
```

`source` からの最短経路木において、各頂点の親との間の辺の番号からなる `vector` を返す。

親が存在しないような頂点に対応する要素は `undefined()` となる。

## get_original_graph
```
Graph< cost_type > get_original_graph()
```

もとのグラフを返す。

## inf
```
cost_type inf()
```

`cost_type` で表現できるような最大の値を返す。

## undefined
```
usize undefined()
```

最短経路木において親が存在しないときに返される値。

`std::numeric_limits<usize>::max()` によって定義されている。
