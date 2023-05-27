---
title: オフライン最小共通祖先 (Offline Lowest Common Ancestor)
documentation_of: //src/graph/tree/offline-query/offline-query-lowest-common-ancestor.hpp
---

Tarjan's Offline Algorithm によって実装されているオフライン最小共通祖先

## コンストラクタ
```
OfflineLCAQuery(const Graph<cost_type> &g)
```

最小共通祖先を求める木 `g` を渡す。

## add_query
```
void add_query(usize u, usize v)
```

頂点 $u$ と $v$ の最小共通祖先 $lca(u, v)$ を求めるクエリを追加する。

後述する `build` をした後、`lca(u, v)` によって $lca(u, v)$ を得ることができる。

### 制約
- $0 \leq u, v < \|V\|$

### 計算量
- $O(1)$

## build
```
void build(usize root)
```

頂点 `root` を根とする根付き木上での最小共通祖先を計算する。

### 制約
- $0 \leq root < \|V\|$

### 計算量
- $O((\|V\| + Q) \alpha (\|V\|))$
  - 追加されたクエリの数を $Q$ とする
  - アッカーマン関数の逆関数を $\alpha(n)$ とする

## lca
```
usize lca(usize u, usize v)
```

$lca(u, v)$ を返す。根は直近で呼ばれた `build(root)` に依存する。

### 制約
- `add_query(u, v)` が呼ばれており、かつその後に `build(root)` が呼ばれていること。

### 計算量
- $O(1)$
