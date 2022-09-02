---
title: 座標圧縮
documentation_of: //src/sequence/compression.hpp
---

## Compressor
```
Compressor(std::vector<T> vs)
```

`vs` を 0-indexed で座標圧縮する。

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
