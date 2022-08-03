---
title: Fenwick Tree (Binary Indexed Tree)
documentation_of: //src/data-structure/fenwick-tree.hpp
---

# Fenwick Tree

長さ $n$ の列 $(a_0, a_1, \cdots, a_{n-1})$ に対し

- $a_k$ への加算
- $a_l, a_{l+1}, \cdots, a_{r-1}$ の総和

を $O(\log n)$ で求めることが可能なデータ構造

## コンストラクタ
```
(1) FenwickTree<T>(usize n)
(2) FenwickTree<T>(const std::vector<T> &as)
```

1. 列 $(a_0, a_1, \cdots a_{n-1})$ の全要素を `T()` で初期化する。
2. 列 $(a_0, a_1, \cdots a_{n-1})$ を $a_i = $ `as[i]` として初期化する。

### 制約
- $0 \leq n$

### 計算量
- $O(n)$


## add
```
void add(usize k, const T &v)
```

$a_{k} \leftarrow a_{k} + v$ で更新を行う。

### 制約
- $0 \leq k < n$

### 計算量
- $O(\log n)$


## sum
```
T sum(usize l, usize r) const
```

$a_{l} + a_{l+1} + \cdots + a_{r-1}$ を返す。

### 制約
- $0 \leq l \leq r \leq n$

### 計算量
- $O(\log n)$
