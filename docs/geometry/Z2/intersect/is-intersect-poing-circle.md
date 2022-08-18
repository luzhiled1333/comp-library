---
title: 点と円の交差判定
documentation_of: //src/geometry/Z2/intersect/is-intersect-point-circle.hpp
---

## is_intersect_pc
```
bool is_intersect_pc(Z2::Point<Z> p, Z2::Circle<Z> c)
```

`p` と `c` が交差しているかどうか (`p` が `c` 上の点かどうか) を返す。

### 制約
円の半径の2乗、円の中心と点との距離の2乗がともにオーバーフローしない。
