---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/circle.hpp
    title: "\u5186 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/line.hpp
    title: src/geometry/Z2/class/line.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/polygon.hpp
    title: src/geometry/Z2/class/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/segment.hpp
    title: src/geometry/Z2/class/segment.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/normalize/line-normalize.hpp
    title: src/geometry/Z2/normalize/line-normalize.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/segment-function/counterbalance-segments.hpp
    title: src/geometry/Z2/segment-function/counterbalance-segments.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/utility/polygon-to-segments.hpp
    title: src/geometry/Z2/utility/polygon-to-segments.hpp
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
  bundledCode: "#line 2 \"src/geometry/Z2/class/point.hpp\"\n\n#line 2 \"src/geometry/Z2/class/vector.hpp\"\
    \n\n#include <vector>\n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  class\
    \ Vector {\n\n    Z x_, y_;\n\n   public:\n    Vector(): x_(0), y_(0) {}\n   \
    \ Vector(Z x, Z y): x_(x), y_(y) {}\n\n    Z x() const {\n      return x_;\n \
    \   }\n\n    Z y() const {\n      return y_;\n    }\n\n    bool operator==(const\
    \ Vector &v) const {\n      return x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool\
    \ operator!=(const Vector &v) const {\n      return x_ != v.x_ or y_ != v.y_;\n\
    \    }\n\n    Vector &operator+=(const Vector &v) {\n      x_ += v.x_;\n     \
    \ y_ += v.y_;\n      return *this;\n    }\n    Vector &operator-=(const Vector\
    \ &v) {\n      x_ -= v.x_;\n      y_ -= v.y_;\n      return *this;\n    }\n\n\
    \    Vector operator+(const Vector &v) const {\n      return Vector(*this) +=\
    \ v;\n    }\n    Vector operator-(const Vector &v) const {\n      return Vector(*this)\
    \ -= v;\n    }\n\n    Vector operator+() const {\n      return *this;\n    }\n\
    \    Vector operator-() const {\n      return Vector() - *this;\n    }\n  };\n\
    \n  template < typename Z >\n  using Vectors = std::vector< Vector< Z > >;\n\n\
    } // namespace luz::Z2\n#line 4 \"src/geometry/Z2/class/point.hpp\"\n\n#line 6\
    \ \"src/geometry/Z2/class/point.hpp\"\n\nnamespace luz::Z2 {\n\n  template < typename\
    \ Z >\n  using Point = Vector< Z >;\n\n  template < typename Z >\n  using Points\
    \ = std::vector< Point< Z > >;\n\n} // namespace luz::Z2\n"
  code: "#pragma once\n\n#include \"src/geometry/Z2/class/vector.hpp\"\n\n#include\
    \ <vector>\n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  using Point\
    \ = Vector< Z >;\n\n  template < typename Z >\n  using Points = std::vector< Point<\
    \ Z > >;\n\n} // namespace luz::Z2\n"
  dependsOn:
  - src/geometry/Z2/class/vector.hpp
  isVerificationFile: false
  path: src/geometry/Z2/class/point.hpp
  requiredBy:
  - src/geometry/Z2/class/line.hpp
  - src/geometry/Z2/class/segment.hpp
  - src/geometry/Z2/class/polygon.hpp
  - src/geometry/Z2/class/circle.hpp
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  - src/geometry/Z2/segment-function/counterbalance-segments.hpp
  - src/geometry/Z2/utility/polygon-to-segments.hpp
  - src/geometry/Z2/normalize/line-normalize.hpp
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/4011.test.cpp
  - test/atcoder/abc259_d.test.cpp
documentation_of: src/geometry/Z2/class/point.hpp
layout: document
title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
---

位置ベクトルを表す。実態はベクトルとなっているため、詳細は Depends on の項目を参照すること。

## エイリアス
その他、`std::vector< Point<Z> >` のエイリアスとして `Points<Z>` が定義されている。
