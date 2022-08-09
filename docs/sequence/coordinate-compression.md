---
title: 座標圧縮
documentation_of: //src/sequence/coordinate-compression.hpp
---

## coordinate_compression
```
std::vector< usize > coordinate_compression(std::vector<T> vs)
```

`std::vector<T>` を 0-indexed で座標圧縮して返す。

### 計算量
- `T` の比較を $O(1)$、`vs` のサイズを $n$ として $O(n \log n)$
