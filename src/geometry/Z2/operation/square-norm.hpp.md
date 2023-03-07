---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/square.hpp
    title: $x^2 (x \in \mathbb{Z})$
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/ccw.hpp
    title: src/geometry/Z2/operation/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/segment-function/counterbalance-segments.hpp
    title: src/geometry/Z2/segment-function/counterbalance-segments.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/4011.test.cpp
    title: test/aoj/4011.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc259_d.test.cpp
    title: test/atcoder/abc259_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/operation/square-norm.hpp\"\n\n#line 2 \"\
    src/geometry/Z2/class/vector.hpp\"\n\n#include <vector>\n\nnamespace luz::Z2 {\n\
    \n  template < typename Z >\n  class Vector {\n\n    Z x_, y_;\n\n   public:\n\
    \    Vector(): x_(0), y_(0) {}\n    Vector(Z x, Z y): x_(x), y_(y) {}\n\n    Z\
    \ x() const {\n      return x_;\n    }\n\n    Z y() const {\n      return y_;\n\
    \    }\n\n    bool operator==(const Vector &v) const {\n      return x_ == v.x_\
    \ and y_ == v.y_;\n    }\n\n    bool operator!=(const Vector &v) const {\n   \
    \   return x_ != v.x_ or y_ != v.y_;\n    }\n\n    Vector &operator+=(const Vector\
    \ &v) {\n      x_ += v.x_;\n      y_ += v.y_;\n      return *this;\n    }\n  \
    \  Vector &operator-=(const Vector &v) {\n      x_ -= v.x_;\n      y_ -= v.y_;\n\
    \      return *this;\n    }\n\n    Vector operator+(const Vector &v) const {\n\
    \      return Vector(*this) += v;\n    }\n    Vector operator-(const Vector &v)\
    \ const {\n      return Vector(*this) -= v;\n    }\n\n    Vector operator+() const\
    \ {\n      return *this;\n    }\n    Vector operator-() const {\n      return\
    \ Vector() - *this;\n    }\n  };\n\n  template < typename Z >\n  using Vectors\
    \ = std::vector< Vector< Z > >;\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/operation/square.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Z square(const Z x) {\n\
    \    return x * x;\n  }\n\n} // namespace luz::Z2\n#line 5 \"src/geometry/Z2/operation/square-norm.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Z square_norm(Vector<\
    \ Z > v) {\n    return square(v.x()) + square(v.y());\n  }\n\n} // namespace luz::Z2\n"
  code: "#pragma once\n\n#include \"src/geometry/Z2/class/vector.hpp\"\n#include \"\
    src/geometry/Z2/operation/square.hpp\"\n\nnamespace luz::Z2 {\n\n  template <\
    \ typename Z >\n  Z square_norm(Vector< Z > v) {\n    return square(v.x()) + square(v.y());\n\
    \  }\n\n} // namespace luz::Z2\n"
  dependsOn:
  - src/geometry/Z2/class/vector.hpp
  - src/geometry/Z2/operation/square.hpp
  isVerificationFile: false
  path: src/geometry/Z2/operation/square-norm.hpp
  requiredBy:
  - src/geometry/Z2/operation/ccw.hpp
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  - src/geometry/Z2/segment-function/counterbalance-segments.hpp
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/4011.test.cpp
  - test/atcoder/abc259_d.test.cpp
documentation_of: src/geometry/Z2/operation/square-norm.hpp
layout: document
title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
---

## square_norm
```
Z square_norm(Vector<Z> v)
```

`v` の長さ(norm)の2乗を返す。

オーバーフローに注意。
