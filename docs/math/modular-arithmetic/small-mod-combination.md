---
title: mod が小さい場合の combination (Lucas'theorem)
documentation_of: //src/math/modular-arithmetic/small-mod-combination.hpp
---

## コンストラクタ
```
SmallModCombination< modint >()
```

### 計算量
- 法を $p$ として $O(p)$

## combination
```
mint combination(isize n, isize r)
mint C(isize n, isize r)
```

$_n\mathrm{C}_r$ を計算する。

$r < 0$ または $n < r$ のときは $0$ が返る。

### 計算量
- $O(\log_{p}(n))$
