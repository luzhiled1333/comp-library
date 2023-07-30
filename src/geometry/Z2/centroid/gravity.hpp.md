---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2442.test.cpp
    title: test/aoj/2442.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/centroid/gravity.hpp\"\n\n#line 2 \"src/geometry/Z2/class/point.hpp\"\
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
    \ 4 \"src/geometry/Z2/centroid/gravity.hpp\"\n\n#include <numeric>\n\nnamespace\
    \ luz::Z2 {\n\n  template < typename Z >\n  Point< Z > ntimes_gravity(const Points<\
    \ Z > &pts) {\n    return std::accumulate(pts.begin(), pts.end(), Point< Z >());\n\
    \  }\n\n} // namespace luz::Z2\n"
  code: "#pragma once\n\n#include \"src/geometry/Z2/class/point.hpp\"\n\n#include\
    \ <numeric>\n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Point< Z >\
    \ ntimes_gravity(const Points< Z > &pts) {\n    return std::accumulate(pts.begin(),\
    \ pts.end(), Point< Z >());\n  }\n\n} // namespace luz::Z2\n"
  dependsOn:
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/class/vector.hpp
  isVerificationFile: false
  path: src/geometry/Z2/centroid/gravity.hpp
  requiredBy: []
  timestamp: '2023-05-23 10:28:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2442.test.cpp
documentation_of: src/geometry/Z2/centroid/gravity.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2/centroid/gravity.hpp
- /library/src/geometry/Z2/centroid/gravity.hpp.html
title: src/geometry/Z2/centroid/gravity.hpp
---
