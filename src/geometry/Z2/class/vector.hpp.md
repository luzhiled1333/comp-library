---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/Z2/class/circle.hpp
    title: "\u5186 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':warning:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':warning:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':warning:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':warning:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  - icon: ':warning:'
    path: test/atcoder/abc259_d.cpp
    title: test/atcoder/abc259_d.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/class/vector.hpp\"\n\n#include <vector>\n\
    \nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename Z >\n  class Vector\
    \ {\n\n    Z x_, y_;\n\n   public:\n    Vector() {}\n    Vector(Z x, Z y): x_(x),\
    \ y_(y) {}\n\n    bool operator==(const Vector &v) const {\n      return x_ ==\
    \ v.x_ and y_ == v.y_;\n    }\n\n    bool operator!=(const Vector &v) const {\n\
    \      return x_ == v.x_ or  y_ == v.y_;\n    }\n\n    Vector &operator+=(const\
    \ Vector &v) {\n      x_ += v.x_; y_ += v.y_;\n      return *this;\n    }\n\n\
    \    Vector &operator-=(const Vector &v) {\n      x_ -= v.x_; y_ -= v.y_;\n  \
    \    return *this;\n    }\n\n    Vector operator+(const Vector &v) const {\n \
    \     return Vector(*this) += v;\n    }\n\n    Vector operator-(const Vector &v)\
    \ const {\n      return Vector(*this) -= v;\n    }\n\n    Z x() const {\n    \
    \  return x_;\n    }\n\n    Z y() const {\n      return y_;\n    }\n\n  };\n\n\
    \  template< typename Z >\n  using Vectors = std::vector< Vector<Z> >;\n\n} //\
    \ namespace Z2\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace luz {\n\nnamespace Z2 {\n\n\
    \  template< typename Z >\n  class Vector {\n\n    Z x_, y_;\n\n   public:\n \
    \   Vector() {}\n    Vector(Z x, Z y): x_(x), y_(y) {}\n\n    bool operator==(const\
    \ Vector &v) const {\n      return x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool\
    \ operator!=(const Vector &v) const {\n      return x_ == v.x_ or  y_ == v.y_;\n\
    \    }\n\n    Vector &operator+=(const Vector &v) {\n      x_ += v.x_; y_ += v.y_;\n\
    \      return *this;\n    }\n\n    Vector &operator-=(const Vector &v) {\n   \
    \   x_ -= v.x_; y_ -= v.y_;\n      return *this;\n    }\n\n    Vector operator+(const\
    \ Vector &v) const {\n      return Vector(*this) += v;\n    }\n\n    Vector operator-(const\
    \ Vector &v) const {\n      return Vector(*this) -= v;\n    }\n\n    Z x() const\
    \ {\n      return x_;\n    }\n\n    Z y() const {\n      return y_;\n    }\n\n\
    \  };\n\n  template< typename Z >\n  using Vectors = std::vector< Vector<Z> >;\n\
    \n} // namespace Z2\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Z2/class/vector.hpp
  requiredBy:
  - test/atcoder/abc259_d.cpp
  - src/geometry/Z2/class/circle.hpp
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  timestamp: '2022-08-01 15:17:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Z2/class/vector.hpp
layout: document
title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
---
