---
title: (offine) Functional Graph 上の頂点 $v$ から $k$ 回移動した先の頂点 (Offline Jump On Functional Graph)
documentation_of: //src/graph/functional-graph/offline-query/offline-query-jump-on-functional-graph.hpp
---
 
Functional Graph において、頂点 $v$ からちょうど $k$ 本の辺を辿って到達する頂点を求めるクエリをオフラインで処理する。このようなクエリを $jump(v, k)$ と表記する。

## Appendix
[テンプレートパラメータに渡すグラフ $G$ の仕様について]({{ site.baseurl }}/appendix-graph-type)

## コンストラクタ
```
OfflineJumpOnFunctionalGraphQuery(const G &g)
```

$jump$ クエリを求めるグラフ $g$ を渡す。

内部では $g$ を loop と tree に分解している。

### 制約
- $g$ は Functional Graph である。
  - $g$ の任意の任意の頂点の出次数は $1$ であるとも言い換えられる。

### 計算量
- $O(\|V\|)$

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
