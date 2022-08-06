---
title: Disjoint Set Union (Union Find)
documentation_of: //src/data-structure/disjoint-set-union.hpp
---

TODO

## コンストラクタ
```
DisjointSetUnion<T>(usize n)
```

TODO

### 制約
- $0 \leq n$

### 計算量
- $O(n)$


## size
```
usize size() const
```

TODO

### 計算量
- $O(1)$


## leader
```
usize leader(usize v)
```

TODO

### 制約
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## same
```
bool same(usize u, usize v)
```

TODO

### 制約
- $0 \leq u < n$
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## merge
```
usize merge(usize u, usize v)
```

TODO

### 制約
- $0 \leq u < n$
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## group_size
```
usize group_size(usize v)
```

TODO

### 制約
- $0 \leq v < n$

### 計算量
- ならし $O(\alpha(n))$


## groups
```
std::vector< std::vector< usize > > groups()
```

TODO

### 計算量
- $O(n)$
