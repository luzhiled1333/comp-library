---
title: (offine) 適当なタイトルをつけてください (Offline Jump On Functional Graph)
documentation_of: //src/graph/offline-query-jump-on-functional-graph.hpp
---

Functional Graph において、頂点 $v$ からちょうど $k$ 本の辺を辿って到達する頂点を求めるクエリをオフラインで処理する。このようなクエリを $jump(v, k)$ と表記する。

## コンストラクタ
```
OfflineJumpOnFunctionalGraphQuery(const Graph<cost_type> &g)
```

## add_query
```
void add_query(usize v, u64 k)
```

$jump(v, k)$ を求めるクエリを追加する。

後述する `build` をした後、`jump(v, k)` によってクエリに対する答えを得ることができる。

### 制約
- $0 \leq v < \|V\|$

### 計算量
- $O(1)$

## build
```
void build()
```

$g$ 上での $jump$ クエリを計算する。

### 計算量
- $O(\|V\| + Q)$
  - 追加されたクエリの数を $Q$ とする

## jump
```
usize jump(usize v, u64 k)
```

$jump(v, k)$ を返す。

### 制約
- `add_query(v, k)` が呼ばれており、かつその後に `build()` が呼ばれていること。

### 計算量
- $O(1)$
