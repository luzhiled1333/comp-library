---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/polygon.hpp
    title: src/geometry/Z2/class/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/segment.hpp
    title: src/geometry/Z2/class/segment.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/4011.test.cpp
    title: test/aoj/4011.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/utility/polygon-to-segments.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        ++i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rep(const usize f, const usize l)\
    \ noexcept\n        : f(std::min(f, l)),\n          l(l) {}\n    constexpr auto\
    \ begin() const noexcept {\n      return f;\n    }\n    constexpr auto end() const\
    \ noexcept {\n      return l;\n    }\n  };\n\n  struct rrep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        --i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rrep(const usize f, const usize l)\
    \ noexcept\n        : f(l - 1),\n          l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept {\n      return f;\n    }\n    constexpr auto end()\
    \ const noexcept {\n      return l;\n    }\n  };\n\n} // namespace luz\n#line\
    \ 2 \"src/geometry/Z2/class/polygon.hpp\"\n\n#line 2 \"src/geometry/Z2/class/point.hpp\"\
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
    \ 4 \"src/geometry/Z2/class/polygon.hpp\"\n\n#line 6 \"src/geometry/Z2/class/polygon.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  using Polygon = std::vector<\
    \ Point< Z > >;\n\n  template < typename Z >\n  using Polygons = std::vector<\
    \ Polygon< Z > >;\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/class/segment.hpp\"\
    \n\n#line 4 \"src/geometry/Z2/class/segment.hpp\"\n\n#include <cassert>\n#line\
    \ 7 \"src/geometry/Z2/class/segment.hpp\"\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  class Segment {\n    Point< Z > p0_, p1_;\n\n   public:\n\
    \    Segment() = default;\n\n    Segment(Point< Z > p0, Point< Z > p1): p0_(p0),\
    \ p1_(p1) {\n      assert(p0 != p1);\n    }\n\n    Point< Z > p0() const {\n \
    \     return p0_;\n    }\n\n    Point< Z > p1() const {\n      return p1_;\n \
    \   }\n  };\n\n  template < typename Z >\n  using Segments = std::vector< Segment<\
    \ Z > >;\n\n} // namespace luz::Z2\n#line 7 \"src/geometry/Z2/utility/polygon-to-segments.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Segments< Z > polygon_to_segments(const\
    \ Polygon< Z > &poly) {\n    usize n = poly.size();\n\n    Segments< Z > segments(n);\n\
    \    for (usize i: rep(0, n)) {\n      segments[i] = Segment< Z >(poly[i], poly[next_idx(i,\
    \ n)]);\n    }\n\n    return segments;\n  }\n\n} // namespace luz::Z2\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/rep.hpp\"\n#include \"\
    src/cpp-template/header/size-alias.hpp\"\n#include \"src/geometry/Z2/class/polygon.hpp\"\
    \n#include \"src/geometry/Z2/class/segment.hpp\"\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  Segments< Z > polygon_to_segments(const Polygon< Z > &poly)\
    \ {\n    usize n = poly.size();\n\n    Segments< Z > segments(n);\n    for (usize\
    \ i: rep(0, n)) {\n      segments[i] = Segment< Z >(poly[i], poly[next_idx(i,\
    \ n)]);\n    }\n\n    return segments;\n  }\n\n} // namespace luz::Z2\n"
  dependsOn:
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/geometry/Z2/class/polygon.hpp
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/class/vector.hpp
  - src/geometry/Z2/class/segment.hpp
  isVerificationFile: false
  path: src/geometry/Z2/utility/polygon-to-segments.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/4011.test.cpp
documentation_of: src/geometry/Z2/utility/polygon-to-segments.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2/utility/polygon-to-segments.hpp
- /library/src/geometry/Z2/utility/polygon-to-segments.hpp.html
title: src/geometry/Z2/utility/polygon-to-segments.hpp
---
