---
title: オフライン Level Ancestor (Offline Level Ancestor)
documentation_of: //src/graph/offline-query-level-ancestor.hpp
---

## コンストラクタ
```
OfflineLAQuery(const Graph<cost_type> &g)
```

Level ancestor を求める木 `g` を渡す。

## add_query
```
void add_query(usize v, usize level)
```

頂点 $v$ の祖先であって深さが $level$ であるような頂点 $la(v, level)$ を求めるクエリを追加する。

後述する `build` をした後、`la(v, level)` によって $la(v, level)$ を得ることができる。

### 制約
- $0 \leq v < \|V\|$

### 計算量
- $O(1)$

## build
```
void build(usize root)
```

頂点 `root` を根とする根付き木上での Level ancestor を計算する。

### 計算量
- $O((\|V\| + Q))$
  - 追加されたクエリの数を $Q$ とする

## la
```
std::optional< usize > la(usize v, usize level)
```

$la(v, level)$ を `std::optional` でラップして返す。根は直近で呼ばれた `build(root)` に依存する。

頂点 $v$ の祖先であって深さが $level$ であるような頂点が存在しないとき `std::nullopt` が返る。

### `la()` の使用例
$la(v, level)$ が存在するときは $la(v, level)$ となる頂点の番号を、そうでない場合 `-1` を出力するサンプル

```
OfflineLAQuery la_query(g);

...

auto la = la_query.la(v, level);

if (la) {
  std::cout << la.value() << std::endl;
} else {
  std::cout << -1 << std::endl;
}
```

### 制約
- `add_query(v, level)` が呼ばれており、かつその後に `build(root)` が呼ばれていること。

### 計算量
- $O(1)$
