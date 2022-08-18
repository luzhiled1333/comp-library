---
title: 円と円の交差判定
documentation_of: //src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
---

## is_intersect_cc
```
bool is_intersect_cc(Z2::Circle<Z> c0, Z2::Circle<Z> c1)
```

円 `c0` と `c1` が交差しているかどうかを返す。

### 制約
- 中心座標間の距離の2乗が `Z` 上でオーバーフローしないこと。
- 半径の和の2乗が `Z` 上でオーバーフローしないこと。


### 解説
2つの円が交点を持たないのは以下の2通り。

1. 一方の円がもう一方の円に内包されている場合
2. 円周も面積も共有しない場合

1 の場合、$(中心間の距離 + 小さいほうの半径) < 大きいほうの半径$ が条件である。
![内包されている場合](https://github.com/luzhiled1333/comp-library/blob/main/assets/geometry/Z2/intersect/is-intersect-circle-circle-001.png?raw=true)

2 の場合、$(中心間の距離 - 一方の半径) > もう一方の半径$ が条件となる。
![面積を共有しない場合](https://github.com/luzhiled1333/comp-library/blob/main/assets/geometry/Z2/intersect/is-intersect-circle-circle-002.png?raw=true)

距離や半径の計算には `sqrt` が出てくるが、式を整理して2乗して扱うことで整数上で考えることができ、誤差なく交差判定を扱うことができる。
