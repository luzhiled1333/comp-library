---
title: 座標圧縮
documentation_of: //src/sequence/compression.hpp
---

## コンストラクタ
```
Compressor<T, Compare>(std::vector<T> vs)
```

引数で与えられた `vector` を 0-indexed で座標圧縮する。

### Compare について
`Compare` にはデフォルトで `std::less` が与えられている。

内部的に `std::sort` を用いているため、`Compare` は狭義の弱順序を満たす必要がある。
狭義の弱順序とは以下の性質をすべて満たすものである。
- 任意の `a` について `not (a < a)`
- `a < b` ならば `not (b < a)`
- `a < b` かつ `b < c` ならば `a < c`

座標圧縮後の要素 `a, b` の `a < b` の結果と `Compare()(a, b)` の結果は一致するようになっている。

### 計算量
- `T` の比較を $O(1)$、`vs` のサイズを $n$ として $O(n \log n)$

## compressed_vector
```
std::vector< usize > compressed_vector() const
```
座標圧縮後の `vs` を返す。

### 計算量
- $O(n)$

## compress
```
usize compress(T v) const
```

### 計算量
- $O(\log n)$

## expand
```
T expand(usize i) const
```

### 制約
- 座標圧縮後の配列のサイズを $m$ として $i \lt m$

### 計算量
- $O(1)$
