---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':warning:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':warning:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':warning:'
    path: test/atcoder/abc259_d.cpp
    title: test/atcoder/abc259_d.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/class/circle.hpp\"\n\n#line 2 \"src/geometry/Z2/class/point.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/class/vector.hpp\"\n\n#include <vector>\n\nnamespace\
    \ luz::Z2 {\n\n  template < typename Z >\n  class Vector {\n\n    Z x_, y_;\n\n\
    \   public:\n    Vector(): x_(0), y_(0) {}\n    Vector(Z x, Z y): x_(x), y_(y)\
    \ {}\n\n    Z x() const {\n      return x_;\n    }\n\n    Z y() const {\n    \
    \  return y_;\n    }\n\n    bool operator==(const Vector &v) const {\n      return\
    \ x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool operator!=(const Vector &v) const\
    \ {\n      return x_ != v.x_ or y_ != v.y_;\n    }\n\n    Vector &operator+=(const\
    \ Vector &v) {\n      x_ += v.x_;\n      y_ += v.y_;\n      return *this;\n  \
    \  }\n    Vector &operator-=(const Vector &v) {\n      x_ -= v.x_;\n      y_ -=\
    \ v.y_;\n      return *this;\n    }\n\n    Vector operator+(const Vector &v) const\
    \ {\n      return Vector(*this) += v;\n    }\n    Vector operator-(const Vector\
    \ &v) const {\n      return Vector(*this) -= v;\n    }\n\n    Vector operator+()\
    \ const {\n      return *this;\n    }\n    Vector operator-() const {\n      return\
    \ Vector() - *this;\n    }\n  };\n\n  template < typename Z >\n  using Vectors\
    \ = std::vector< Vector< Z > >;\n\n} // namespace luz::Z2\n#line 4 \"src/geometry/Z2/class/point.hpp\"\
    \n\n#line 6 \"src/geometry/Z2/class/point.hpp\"\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  using Point = Vector< Z >;\n\n  template < typename Z >\n\
    \  using Points = std::vector< Point< Z > >;\n\n} // namespace luz::Z2\n#line\
    \ 4 \"src/geometry/Z2/class/circle.hpp\"\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  class Circle {\n\n    Point< Z > o_;\n    Z r_;\n\n   public:\n\
    \    Circle(): o_(0, 0), r_(0) {}\n\n    Circle(Point< Z > o, Z r): o_(o), r_(r)\
    \ {\n      assert(r >= 0);\n    }\n\n    Point< Z > center() const {\n      return\
    \ o_;\n    }\n\n    Z r() const {\n      return r_;\n    }\n  };\n\n  template\
    \ < typename Z >\n  using Circles = std::vector< Circle< Z > >;\n\n} // namespace\
    \ luz::Z2\n"
  code: "#pragma once\n\n#include \"src/geometry/Z2/class/point.hpp\"\n\nnamespace\
    \ luz::Z2 {\n\n  template < typename Z >\n  class Circle {\n\n    Point< Z > o_;\n\
    \    Z r_;\n\n   public:\n    Circle(): o_(0, 0), r_(0) {}\n\n    Circle(Point<\
    \ Z > o, Z r): o_(o), r_(r) {\n      assert(r >= 0);\n    }\n\n    Point< Z >\
    \ center() const {\n      return o_;\n    }\n\n    Z r() const {\n      return\
    \ r_;\n    }\n  };\n\n  template < typename Z >\n  using Circles = std::vector<\
    \ Circle< Z > >;\n\n} // namespace luz::Z2\n"
  dependsOn:
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/class/vector.hpp
  isVerificationFile: false
  path: src/geometry/Z2/class/circle.hpp
  requiredBy:
  - test/atcoder/abc259_d.cpp
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Z2/class/circle.hpp
layout: document
title: "\u5186 (\u6574\u6570\u5E7E\u4F55)"
---

中心座標 $\boldsymbol{o} \in {\mathbb{Z}}^2$、半径 $r \in {\mathbb{Z}}_{\geq 0}$ の円を表す。

## コンストラクタ
```
(1) Z2::Circle()
(2) Z2::Circle(Z2::Point o, Z2 r)
```

1. `Z2::Circle` のデフォルトコンストラクタ。原点を中心とする半径 $0$ の円が格納される。
2. 中心座標 `o`、半径 `r` の円が格納される。

### 制約
- $0 \leq r$

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
