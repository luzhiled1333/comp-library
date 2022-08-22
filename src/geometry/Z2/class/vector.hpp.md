---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/circle.hpp
    title: "\u5186 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc259_d.test.cpp
    title: test/atcoder/abc259_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/class/vector.hpp\"\n\n#include <vector>\n\
    \nnamespace luz::Z2 {\n\n  template < typename Z >\n  class Vector {\n\n    Z\
    \ x_, y_;\n\n   public:\n    Vector(): x_(0), y_(0) {}\n    Vector(Z x, Z y):\
    \ x_(x), y_(y) {}\n\n    Z x() const {\n      return x_;\n    }\n\n    Z y() const\
    \ {\n      return y_;\n    }\n\n    bool operator==(const Vector &v) const {\n\
    \      return x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool operator!=(const Vector\
    \ &v) const {\n      return x_ != v.x_ or y_ != v.y_;\n    }\n\n    Vector &operator+=(const\
    \ Vector &v) {\n      x_ += v.x_;\n      y_ += v.y_;\n      return *this;\n  \
    \  }\n    Vector &operator-=(const Vector &v) {\n      x_ -= v.x_;\n      y_ -=\
    \ v.y_;\n      return *this;\n    }\n\n    Vector operator+(const Vector &v) const\
    \ {\n      return Vector(*this) += v;\n    }\n    Vector operator-(const Vector\
    \ &v) const {\n      return Vector(*this) -= v;\n    }\n\n    Vector operator+()\
    \ const {\n      return *this;\n    }\n    Vector operator-() const {\n      return\
    \ Vector() - *this;\n    }\n  };\n\n  template < typename Z >\n  using Vectors\
    \ = std::vector< Vector< Z > >;\n\n} // namespace luz::Z2\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace luz::Z2 {\n\n  template <\
    \ typename Z >\n  class Vector {\n\n    Z x_, y_;\n\n   public:\n    Vector():\
    \ x_(0), y_(0) {}\n    Vector(Z x, Z y): x_(x), y_(y) {}\n\n    Z x() const {\n\
    \      return x_;\n    }\n\n    Z y() const {\n      return y_;\n    }\n\n   \
    \ bool operator==(const Vector &v) const {\n      return x_ == v.x_ and y_ ==\
    \ v.y_;\n    }\n\n    bool operator!=(const Vector &v) const {\n      return x_\
    \ != v.x_ or y_ != v.y_;\n    }\n\n    Vector &operator+=(const Vector &v) {\n\
    \      x_ += v.x_;\n      y_ += v.y_;\n      return *this;\n    }\n    Vector\
    \ &operator-=(const Vector &v) {\n      x_ -= v.x_;\n      y_ -= v.y_;\n     \
    \ return *this;\n    }\n\n    Vector operator+(const Vector &v) const {\n    \
    \  return Vector(*this) += v;\n    }\n    Vector operator-(const Vector &v) const\
    \ {\n      return Vector(*this) -= v;\n    }\n\n    Vector operator+() const {\n\
    \      return *this;\n    }\n    Vector operator-() const {\n      return Vector()\
    \ - *this;\n    }\n  };\n\n  template < typename Z >\n  using Vectors = std::vector<\
    \ Vector< Z > >;\n\n} // namespace luz::Z2\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Z2/class/vector.hpp
  requiredBy:
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/class/circle.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc259_d.test.cpp
documentation_of: src/geometry/Z2/class/vector.hpp
layout: document
title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
---

## コンストラクタ
```
(1) Z2::Vector()
(2) Z2::Vector(Z x, Z y)
```

1. `Z2::Vector` のデフォルトコンストラクタ。$(0, 0)$ が格納される。
2. 整数型 `Z` に対するコンストラクタ。$(x, y)$ が格納される。

## 座標
```
(1) Z x() const
(2) Z y() const
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
その他、`std::vector< Vector<Z> >` のエイリアスとして `Vectors<Z>` が定義されている。
