---
title: 重みなし単一始点最短経路 (Single Source Shortest Path in Unweighted Graph, BFS)
documentation_of: //src/graph/single-source-shortest-path/in-unweighted-graph.hpp
---

## Appendix
[単一始点最短経路問題の solver の細かい仕様について]({{ site.baseurl }}/appendix-single-source-shortest-path-solver)

[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
sssp::InUnweightedGraph(const G &g, usize s)
```

頂点 $s$ からの重みなし単一始点最短経路問題を解く。

コンストラクタに渡されるグラフ $G$ の各辺は重みをもつことが可能であるが、内部では辺の存在のみを用いて最短経路を計算している。このため、例えば任意の辺の重みが正の定数 $c$ であったとすると、最短経路のコストが $\frac{1}{c}$ 倍された値が計算されることになる。

コンストラクタ内部では以下が行われている。

- 始点から各頂点への最短経路のコストの計算
- 以下で特定される最短経路木を一つ構成
  - 親の頂点番号
  - 親との間にある辺の辺番号

### 計算量
- $O(\|V\| + \|E\|)$

## get_original_graph
```
G get_original_graph() const
```

もとのグラフを返す。

## inf
```
static usize inf() const
```

$s$ からの経路が存在しないような頂点 $v$ への $s$ からの最短経路のコストとして定義されている値を返す。

内部では `std::numeric_limits< usize >::max()` によって定義されている。

## distance
```
usize distance(const usize v) const
```

$s$ から $v$ への最短経路のコストを返す。経路が存在しない場合のコストは `inf()` として定義されている。

戻り値の型が `cost_type` ではなく `usize` であることに注意。

## get_distances
```
std::vector< usize > get_distances() const
```

各頂点に対する `distance` を `std::vector` で wrap して返す。`distance(v)` は `v` 番目の要素として表される。

$s$ からの経路が存在しないような頂点へのコストは `inf()` として定義されている。

戻り値の型が `std::vector< cost_type >` ではなく `std::vector< usize >` であることに注意。

## undefined
```
static usize undefined() const
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
