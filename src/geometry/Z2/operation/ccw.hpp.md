---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/constants/ccw-constants.hpp
    title: src/geometry/Z2/constants/ccw-constants.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/cross-product.hpp
    title: src/geometry/Z2/operation/cross-product.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/inner-product.hpp
    title: src/geometry/Z2/operation/inner-product.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/square.hpp
    title: $x^2 (x \in \mathbb{Z})$
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/segment-function/counterbalance-segments.hpp
    title: src/geometry/Z2/segment-function/counterbalance-segments.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/4011.test.cpp
    title: test/aoj/4011.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/operation/ccw.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 2 \"src/geometry/Z2/class/vector.hpp\"\n\n#include\
    \ <vector>\n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  class Vector\
    \ {\n\n    Z x_, y_;\n\n   public:\n    Vector(): x_(0), y_(0) {}\n    Vector(Z\
    \ x, Z y): x_(x), y_(y) {}\n\n    Z x() const {\n      return x_;\n    }\n\n \
    \   Z y() const {\n      return y_;\n    }\n\n    bool operator==(const Vector\
    \ &v) const {\n      return x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool operator!=(const\
    \ Vector &v) const {\n      return x_ != v.x_ or y_ != v.y_;\n    }\n\n    Vector\
    \ &operator+=(const Vector &v) {\n      x_ += v.x_;\n      y_ += v.y_;\n     \
    \ return *this;\n    }\n    Vector &operator-=(const Vector &v) {\n      x_ -=\
    \ v.x_;\n      y_ -= v.y_;\n      return *this;\n    }\n\n    Vector operator+(const\
    \ Vector &v) const {\n      return Vector(*this) += v;\n    }\n    Vector operator-(const\
    \ Vector &v) const {\n      return Vector(*this) -= v;\n    }\n\n    Vector operator+()\
    \ const {\n      return *this;\n    }\n    Vector operator-() const {\n      return\
    \ Vector() - *this;\n    }\n  };\n\n  template < typename Z >\n  using Vectors\
    \ = std::vector< Vector< Z > >;\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/constants/ccw-constants.hpp\"\
    \n\nnamespace luz::Z2::constants::ccw {\n\n  constexpr i32 COUNTER_CLOCKWISE =\
    \ +1;\n  constexpr i32 CLOCKWISE         = -1;\n  constexpr i32 ONLINE_BACK  \
    \     = +2; // c-a-b\n  constexpr i32 ONLINE_FRONT      = -2; // a-b-c\n  constexpr\
    \ i32 ON_SEGMENT        = 0;  // a-c-b\n\n} // namespace luz::Z2::constants::ccw\n\
    #line 2 \"src/geometry/Z2/operation/cross-product.hpp\"\n\n#line 4 \"src/geometry/Z2/operation/cross-product.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Z cross_product(const\
    \ Vector< Z > &a, const Vector< Z > &b) {\n    return a.x() * b.y() - a.y() *\
    \ b.x();\n  }\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/operation/inner-product.hpp\"\
    \n\n#line 4 \"src/geometry/Z2/operation/inner-product.hpp\"\n\nnamespace luz::Z2\
    \ {\n\n  template < typename Z >\n  Z inner_product(const Vector< Z > &a, const\
    \ Vector< Z > &b) {\n    return a.x() * b.x() + a.y() * b.y();\n  }\n\n} // namespace\
    \ luz::Z2\n#line 2 \"src/geometry/Z2/operation/square-norm.hpp\"\n\n#line 2 \"\
    src/geometry/Z2/operation/square.hpp\"\n\nnamespace luz::Z2 {\n\n  template <\
    \ typename Z >\n  Z square(const Z x) {\n    return x * x;\n  }\n\n} // namespace\
    \ luz::Z2\n#line 5 \"src/geometry/Z2/operation/square-norm.hpp\"\n\nnamespace\
    \ luz::Z2 {\n\n  template < typename Z >\n  Z square_norm(Vector< Z > v) {\n \
    \   return square(v.x()) + square(v.y());\n  }\n\n} // namespace luz::Z2\n#line\
    \ 9 \"src/geometry/Z2/operation/ccw.hpp\"\n\nnamespace luz::Z2::impl_ccw {\n\n\
    \  using namespace constants::ccw;\n\n  template < typename Z >\n  i32 ccw(const\
    \ Vector< Z > &a, Vector< Z > b, Vector< Z > c) {\n    b -= a;\n    c -= a;\n\n\
    \    Z cp = cross_product(b, c);\n    if (cp > 0) return COUNTER_CLOCKWISE;\n\
    \    if (cp < 0) return CLOCKWISE;\n    if (inner_product(b, c) < 0) return ONLINE_BACK;\n\
    \    if (square_norm(b) < square_norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    \  }\n\n} // namespace luz::Z2::impl_ccw\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  i32 ccw(const Vector< Z > &a, const Vector< Z > &b,\n    \
    \      const Vector< Z > &c) {\n    return impl_ccw::ccw(a, b, c);\n  }\n\n} //\
    \ namespace luz::Z2\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n#include\
    \ \"src/geometry/Z2/class/vector.hpp\"\n#include \"src/geometry/Z2/constants/ccw-constants.hpp\"\
    \n#include \"src/geometry/Z2/operation/cross-product.hpp\"\n#include \"src/geometry/Z2/operation/inner-product.hpp\"\
    \n#include \"src/geometry/Z2/operation/square-norm.hpp\"\n\nnamespace luz::Z2::impl_ccw\
    \ {\n\n  using namespace constants::ccw;\n\n  template < typename Z >\n  i32 ccw(const\
    \ Vector< Z > &a, Vector< Z > b, Vector< Z > c) {\n    b -= a;\n    c -= a;\n\n\
    \    Z cp = cross_product(b, c);\n    if (cp > 0) return COUNTER_CLOCKWISE;\n\
    \    if (cp < 0) return CLOCKWISE;\n    if (inner_product(b, c) < 0) return ONLINE_BACK;\n\
    \    if (square_norm(b) < square_norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    \  }\n\n} // namespace luz::Z2::impl_ccw\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  i32 ccw(const Vector< Z > &a, const Vector< Z > &b,\n    \
    \      const Vector< Z > &c) {\n    return impl_ccw::ccw(a, b, c);\n  }\n\n} //\
    \ namespace luz::Z2\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/geometry/Z2/class/vector.hpp
  - src/geometry/Z2/constants/ccw-constants.hpp
  - src/geometry/Z2/operation/cross-product.hpp
  - src/geometry/Z2/operation/inner-product.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  - src/geometry/Z2/operation/square.hpp
  isVerificationFile: false
  path: src/geometry/Z2/operation/ccw.hpp
  requiredBy:
  - src/geometry/Z2/segment-function/counterbalance-segments.hpp
  timestamp: '2022-11-18 16:59:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/4011.test.cpp
documentation_of: src/geometry/Z2/operation/ccw.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2/operation/ccw.hpp
- /library/src/geometry/Z2/operation/ccw.hpp.html
title: src/geometry/Z2/operation/ccw.hpp
---
