---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/geometry/Z2-geometry/struct/vector.hpp
    title: src/geometry/Z2-geometry/struct/vector.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp
    title: src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp
  - icon: ':warning:'
    path: src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp
    title: src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp
  - icon: ':warning:'
    path: src/geometry/Z2-geometry/struct/circle.hpp
    title: src/geometry/Z2-geometry/struct/circle.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2-geometry/struct/point.hpp\"\n\n#line 2 \"\
    src/geometry/Z2-geometry/struct/vector.hpp\"\n\n#include <vector>\n\nnamespace\
    \ luz {\n\nnamespace Z2 {\n\n  template< typename Z >\n  class Vector {\n\n  \
    \  Z x_, y_;\n\n   public:\n    Vector() {}\n    Vector(Z x, Z y): x_(x), y_(y)\
    \ {}\n\n    bool operator==(const Vector &v) const {\n      return x_ == v.x_\
    \ and y_ == v.y_;\n    }\n\n    bool operator!=(const Vector &v) const {\n   \
    \   return x_ == v.x_ or  y_ == v.y_;\n    }\n\n    Vector &operator+=(const Vector\
    \ &v) {\n      x_ += v.x_; y_ += v.y_;\n      return *this;\n    }\n\n    Vector\
    \ &operator-=(const Vector &v) {\n      x_ -= v.x_; y_ -= v.y_;\n      return\
    \ *this;\n    }\n\n    Vector operator+(const Vector &v) const {\n      return\
    \ (*this) += v;\n    }\n\n    Vector operator-(const Vector &v) const {\n    \
    \  return (*this) -= v;\n    }\n  };\n\n  template< typename Z >\n  using Vectors\
    \ = std::vector< Vector<Z> >;\n\n} // namespace Z2\n\n} // namespace luz\n#line\
    \ 4 \"src/geometry/Z2-geometry/struct/point.hpp\"\n\n#line 6 \"src/geometry/Z2-geometry/struct/point.hpp\"\
    \n\nnamespace luz {\n \nnamespace Z2 {\n\n  template< typename Z >\n  using Point\
    \ = Vector< Z >;\n\n  template< typename Z >\n  using Points = std::vector< Point<Z>\
    \ >;\n\n} // namespace Z2\n\n} // namespace luz\n\n"
  code: "#pragma once\n\n#include \"src/geometry/Z2-geometry/struct/vector.hpp\"\n\
    \n#include <vector>\n\nnamespace luz {\n \nnamespace Z2 {\n\n  template< typename\
    \ Z >\n  using Point = Vector< Z >;\n\n  template< typename Z >\n  using Points\
    \ = std::vector< Point<Z> >;\n\n} // namespace Z2\n\n} // namespace luz\n\n"
  dependsOn:
  - src/geometry/Z2-geometry/struct/vector.hpp
  isVerificationFile: false
  path: src/geometry/Z2-geometry/struct/point.hpp
  requiredBy:
  - src/geometry/Z2-geometry/struct/circle.hpp
  - src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp
  timestamp: '2022-07-15 23:48:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Z2-geometry/struct/point.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2-geometry/struct/point.hpp
- /library/src/geometry/Z2-geometry/struct/point.hpp.html
title: src/geometry/Z2-geometry/struct/point.hpp
---
