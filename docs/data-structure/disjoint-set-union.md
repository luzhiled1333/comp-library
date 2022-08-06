---
title: Disjoint Set Union (Union Find)
documentation_of: //src/data-structure/disjoint-set-union.hpp
---

## コンストラクタ
```
DisjointSetUnion<T>(usize n)
```

$1$ 要素の集合 $n$ 個で集合を初期化する。

### 制約
- $0 \leq n$

### 計算量
- $O(n)$


## size
```
usize size() const
```

グラフの頂点集合のサイズを返す。

[ac-library の DSU](https://atcoder.github.io/ac-library/document_ja/dsu.html) の `size()` とは仕様が異なるため注意。
こちらと同じ動作をする関数として `group_size()` が用意されている。

### 計算量
- $O(1)$


## leader
```
usize leader(usize v)
```

頂点 `v` が属する連結成分の代表元を返す。

### 制約
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## same
```
bool same(usize u, usize v)
```

頂点 `u`, `v` が連結ならば `true` を、そうでないならば `false` を返す。

### 制約
- $0 \leq u < n$
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## merge
```
usize merge(usize u, usize v)
```

`u`, `v` が属する連結成分を連結し、連結後の代表元を返す。

### 制約
- $0 \leq u < n$
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## group_size
```
usize group_size(usize v)
```

頂点 `v` が属する連結成分の頂点集合のサイズを返す。

### 制約
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## groups
```
std::vector< std::vector< usize > > groups()
```

連結成分の頂点番号の集合のリストを返す。

連結成分の順番は未定義。各連結成分内の頂点番号は昇順になっている。

### 計算量
- $O(n)$
