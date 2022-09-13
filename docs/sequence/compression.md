---
title: 座標圧縮
documentation_of: //src/sequence/compression.hpp
---

## コンストラクタ
```
Compressor<T, Compare>(std::vector<T> vs)
```

引数で与えられた `vector` を 0-indexed で座標圧縮する。

簡単のため、以下では与えられた `vector` のサイズを $n$ とし、重複を除いた要素数を $m$ とする。

### Compare について
`Compare` にはデフォルトで `std::less` が与えられている。

内部的に `std::sort` を用いているため、`Compare` は狭義の弱順序を満たす必要がある。
狭義の弱順序とは以下の性質をすべて満たすものである。
- 任意の `a` について `not (a < a)`
- `a < b` ならば `not (b < a)`
- `a < b` かつ `b < c` ならば `a < c`

座標圧縮後の要素 `a, b` の `a < b` の結果と `Compare()(a, b)` の結果は一致するようになっている。

### 計算量
- `Compare()` を $O(1)$ として $O(n \log n)$


## compressed_vector
```
std::vector< usize > compressed_vector() const
```

コンストラクタに与えられた `vector` を座標圧縮した結果を返す。

### 計算量
- $O(n)$


## compress
```
usize compress(T v) const
```

座標圧縮の結果、$v$ がどこに mapping されたかを再計算して返す。

### 制約
- $v$ はコンストラクタに与えられた `vector` の要素である。

### 計算量
- $O(\log n)$


## expand
```
T expand(usize i) const
```

$i$ に対応する座標圧縮前の要素を返す。

### 制約
- $0 \leq i \lt m$

### 計算量
- $O(1)$
