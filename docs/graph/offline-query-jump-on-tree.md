---
title: (offine) 木のパス $u-v$ 上の $k$ 番目の頂点 (Offline Jump On Tree)
documentation_of: //src/graph/offline-query-jump-on-tree.hpp
---

静的木上のパス $u-v$ 上の頂点のうち $u$ からの距離が $k$ であるような頂点を求めるクエリをオフラインで処理する。

このドキュメントでは、このようなクエリを $jump(u, v, k)$ と表記する。

## コンストラクタ
```
OfflineJumpOnTreeQuery(const Graph<cost_type> &g)
```

## add_query
```
void add_query(usize u, usize v, usize k)
```

$jump(u, v, k)$ を求めるクエリを追加する。

後述する `build` をした後、`jump_on_tree(u, v, k)` によって $jump(u, v, k)$ を得ることができる。

### 制約
- $0 \leq u, v < \|V\|$

### 計算量
- $O(1)$

## build
```
void build(usize root)
```

頂点 `root` を根とする根付き木上での $jump$ クエリを計算する。

`root` は解に影響しないため何が選ばれても問題はない。

### 制約
- $0 \leq root < \|V\|$

### 計算量
- $O((\|V\| + Q) \alpha (\|V\|))$
  - 追加されたクエリの数を $Q$ とする
  - アッカーマン関数の逆関数を $\alpha(n)$ とする

## jump_on_tree
```
std::optional< usize >
jump_on_tree(usize u, usize v, usize k)
```

$jump(u, v, k)$ を `std::optional` でラップして返す。

パス $u-v$ 上に $u$ からの距離が $k$ であるような頂点が存在しない場合は `std::nullopt` が返る。

### 使用例
$jump(u, v, k)$ が存在するときは $jump(u, v, k)$ となる頂点の番号を、そのような頂点が存在しない場合は `-1` を出力するサンプル

```
OfflineJumpOnTreeQuery jump_query(g);

...

auto jump = jump_query.jump_on_tree(u, v, k);

if (jump) {
  std::cout << jump.value() << std::endl;
} else {
  std::cout << -1 << std::endl;
}
```

### 制約
- `add_query(u, v)` が呼ばれており、かつその後に `build(root)` が呼ばれていること。

### 計算量
- $O(1)$
