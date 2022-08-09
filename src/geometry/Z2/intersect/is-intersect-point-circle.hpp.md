---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Z2/class/circle.hpp
    title: "\u5186 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':warning:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':warning:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':warning:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  - icon: ':warning:'
    path: src/geometry/Z2/operation/square.hpp
    title: $x^2 (x \in \mathbb{Z})$
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/abc259_d.cpp
    title: test/atcoder/abc259_d.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/intersect/is-intersect-point-circle.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/class/point.hpp\"\n\n#line 2 \"src/geometry/Z2/class/vector.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename\
    \ Z >\n  class Vector {\n\n    Z x_, y_;\n\n   public:\n    Vector(): x_(0), y_(0)\
    \ {}\n    Vector(Z x, Z y): x_(x), y_(y) {}\n\n    Z x() const {\n      return\
    \ x_;\n    }\n\n    Z y() const {\n      return y_;\n    }\n\n    bool operator==(const\
    \ Vector &v) const {\n      return x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool\
    \ operator!=(const Vector &v) const {\n      return x_ != v.x_ or  y_ != v.y_;\n\
    \    }\n\n    Vector &operator+=(const Vector &v) {\n      x_ += v.x_; y_ += v.y_;\n\
    \      return *this;\n    }\n    Vector &operator-=(const Vector &v) {\n     \
    \ x_ -= v.x_; y_ -= v.y_;\n      return *this;\n    }\n\n    Vector operator+(const\
    \ Vector &v) const {\n      return Vector(*this) += v;\n    }\n    Vector operator-(const\
    \ Vector &v) const {\n      return Vector(*this) -= v;\n    }\n\n    Vector operator+()\
    \ const {\n      return *this;\n    }\n    Vector operator-() const {\n      return\
    \ Vector() - *this;\n    }\n\n  };\n\n  template< typename Z >\n  using Vectors\
    \ = std::vector< Vector<Z> >;\n\n} // namespace Z2\n\n} // namespace luz\n#line\
    \ 4 \"src/geometry/Z2/class/point.hpp\"\n\n#line 6 \"src/geometry/Z2/class/point.hpp\"\
    \n\nnamespace luz {\n \nnamespace Z2 {\n\n  template< typename Z >\n  using Point\
    \ = Vector< Z >;\n\n  template< typename Z >\n  using Points = std::vector< Point<Z>\
    \ >;\n\n} // namespace Z2\n\n} // namespace luz\n\n#line 2 \"src/geometry/Z2/class/circle.hpp\"\
    \n\n#line 4 \"src/geometry/Z2/class/circle.hpp\"\n\nnamespace luz {\n\nnamespace\
    \ Z2 {\n\n  template< typename Z >\n  class Circle {\n\n    Point< Z > o_;\n \
    \   Z r_;\n\n   public:\n    Circle(): o_(0, 0), r_(0) {}\n\n    Circle(Point<\
    \ Z > o, Z r): o_(o), r_(r) {\n      assert(r >= 0);\n    }\n\n    Point< Z >\
    \ center() const {\n      return o_;\n    }\n\n    Z r() const {\n      return\
    \ r_;\n    }\n  };\n\n  template< typename Z >\n  using Circles = std::vector<\
    \ Circle< Z > >;\n\n} // namespace Z2\n\n} // namespace luz\n#line 2 \"src/geometry/Z2/operation/square-norm.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/operation/square.hpp\"\n\nnamespace luz {\n\nnamespace\
    \ Z2 {\n\n  template< typename Z >\n  Z square(const Z x) {\n    return x * x;\n\
    \  }\n\n} // namespace Z2\n\n} // namespace luz\n#line 5 \"src/geometry/Z2/operation/square-norm.hpp\"\
    \n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename Z >\n  Z square_norm(Vector<\
    \ Z > v) {\n    return square(v.x()) + square(v.y());\n  }\n\n} // namespace Z2\n\
    \n} // namespace luz\n#line 6 \"src/geometry/Z2/intersect/is-intersect-point-circle.hpp\"\
    \n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename Z >\n  bool is_intersect_pc(Point<\
    \ Z > p, Circle< Z > c) {\n    Z sq_norm = square_norm(c.center() - p);\n    return\
    \ sq_norm == square(c.r());\n  }\n\n} // namespace Z2\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/geometry/Z2/class/point.hpp\"\n#include \"\
    src/geometry/Z2/class/circle.hpp\"\n#include \"src/geometry/Z2/operation/square-norm.hpp\"\
    \n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename Z >\n  bool is_intersect_pc(Point<\
    \ Z > p, Circle< Z > c) {\n    Z sq_norm = square_norm(c.center() - p);\n    return\
    \ sq_norm == square(c.r());\n  }\n\n} // namespace Z2\n\n} // namespace luz\n"
  dependsOn:
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/class/vector.hpp
  - src/geometry/Z2/class/circle.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  - src/geometry/Z2/operation/square.hpp
  isVerificationFile: false
  path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  requiredBy:
  - test/atcoder/abc259_d.cpp
  timestamp: '2022-08-09 21:23:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
layout: document
title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
---

## is_intersect_pc
```
bool is_intersect_pc(Z2::Point<Z> p, Z2::Circle<Z> c)
```

`p` と `c` が交差しているかどうか (`p` が `c` 上の点かどうか) を返す。

### 制約
円の半径の2乗、円の中心と点との距離の2乗がともにオーバーフローしない。
