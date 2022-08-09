---
title: 円 (整数幾何)
documentation_of: //src/geometry/Z2/class/circle.hpp
---

中心座標 $\boldsymbol{o} \in {\mathbb{Z}}^2$、半径 $r \in {\mathbb{Z}}_{\geq 0}$ の円を表す。

## コンストラクタ
```
(1) Z2::Circle()
(2) Z2::Circle(Z2::Point o, Z2 r)
```


## 中心座標
```
Z2::Point center() const
```

円の中心座標を返す。

## 半径
```
Z r() const
```

円の半径を返す。


## エイリアス
その他、`std::vector< Circle<Z> >` のエイリアスとして `Circles<Z>` が定義されている。
