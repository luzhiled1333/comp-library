---
title: ベクトル (整数幾何)
documentation_of: //src/geometry/Z2/class/vector.hpp
---

## コンストラクタ
```
(1) Z2::Vector();
(2) Z2::Vector(Z x, Z y);
```

1. `Z2::Vector` のデフォルトコンストラクタ。$(0, 0)$ が格納される。
2. 整数型 `Z` に対するコンストラクタ。$(x, y)$ が格納される。

## 座標
```
(1) Z x();
(2) Z y();
```

1. ベクトルの x 成分を返す。
2. ベクトルの y 成分を返す。


## 各種演算
`Z2::Vector<Z> u, v` に対し以下が動作する。

```
+v
-v

u += v
u -= v

u + v
u - v

u == v
u != v
```

## エイリアス
その他、`std::vector< Vector<Z> >` のエイリアスとして `Vectors<Z>` が宣言されている。
