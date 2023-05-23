---
title: 行列
documentation_of: //src/geometry/common/class/matrix.hpp
---

## コンストラクタ
```
(1) Matrix< r, c, T >()
(2) Matrix< r, 1, T >()
```

1. 各要素の型が $T$ の $r$ 行 $c$ 列の行列のコンストラクタ。
2. 各要素の型が $T$ の $r$ 次元列ベクトルのコンストラクタ。

### 制約
- `r`, `c` は正のコンパイル時定数であること。


## 各種演算
`Matrix< r, c, T > A, B` と `T x` に対し、以下の演算が実装されている。

```
+A
-A

A += B
A -= B

A + B
A - B

A *= x
A /= x

A * x
x * A
A / x

A == B
A != B
```
