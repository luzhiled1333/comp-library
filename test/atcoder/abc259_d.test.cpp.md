---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':x:'
    path: src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':x:'
    path: src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp
    title: src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp
  - icon: ':x:'
    path: src/geometry/Z2-geometry/operation/square-norm.hpp
    title: src/geometry/Z2-geometry/operation/square-norm.hpp
  - icon: ':x:'
    path: src/geometry/Z2-geometry/operation/square.hpp
    title: src/geometry/Z2-geometry/operation/square.hpp
  - icon: ':x:'
    path: src/geometry/Z2-geometry/struct/circle.hpp
    title: src/geometry/Z2-geometry/struct/circle.hpp
  - icon: ':x:'
    path: src/geometry/Z2-geometry/struct/point.hpp
    title: src/geometry/Z2-geometry/struct/point.hpp
  - icon: ':x:'
    path: src/geometry/Z2-geometry/struct/vector.hpp
    title: src/geometry/Z2-geometry/struct/vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/abc259/tasks/abc259_d
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_d
  bundledCode: "#line 1 \"test/atcoder/abc259_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_d\n// verification-helper:\
    \ IGNORE\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n  \n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept : i(i) {}\n \
    \     void operator++() noexcept { ++i; }\n      constexpr usize operator*() const\
    \ noexcept { return i; }\n      constexpr bool operator!=(const itr x) const noexcept\
    \ { return i != x.i; }\n    };\n    const itr f, l;\n    constexpr rep(const usize\
    \ f, const usize l) noexcept\n      : f(std::min(f, l)), l(l) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n \
    \     constexpr itr(const usize i) noexcept : i(i) {}\n      void operator++()\
    \ noexcept { --i; }\n      constexpr usize operator*() const noexcept { return\
    \ i; }\n      constexpr bool operator!=(const itr x) const noexcept { return i\
    \ != x.i; }\n    };\n    const itr f, l;\n    constexpr rrep(const usize f, const\
    \ usize l) noexcept\n      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n} // namespace luz\n#line 6 \"test/atcoder/abc259_d.test.cpp\"\
    \n\n#line 2 \"src/geometry/Z2-geometry/struct/point.hpp\"\n\n#line 2 \"src/geometry/Z2-geometry/struct/vector.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename\
    \ Z >\n  class Vector {\n\n    Z x_, y_;\n\n   public:\n    Vector() {}\n    Vector(Z\
    \ x, Z y): x_(x), y_(y) {}\n\n    bool operator==(const Vector &v) const {\n \
    \     return x_ == v.x_ and y_ == v.y_;\n    }\n\n    bool operator!=(const Vector\
    \ &v) const {\n      return x_ == v.x_ or  y_ == v.y_;\n    }\n\n    Vector &operator+=(const\
    \ Vector &v) {\n      x_ += v.x_; y_ += v.y_;\n      return *this;\n    }\n\n\
    \    Vector &operator-=(const Vector &v) {\n      x_ -= v.x_; y_ -= v.y_;\n  \
    \    return *this;\n    }\n\n    Vector operator+(const Vector &v) const {\n \
    \     return Vector(*this) += v;\n    }\n\n    Vector operator-(const Vector &v)\
    \ const {\n      return Vector(*this) -= v;\n    }\n\n    Z x() const {\n    \
    \  return x_;\n    }\n\n    Z y() const {\n      return y_;\n    }\n\n  };\n\n\
    \  template< typename Z >\n  using Vectors = std::vector< Vector<Z> >;\n\n} //\
    \ namespace Z2\n\n} // namespace luz\n#line 4 \"src/geometry/Z2-geometry/struct/point.hpp\"\
    \n\n#line 6 \"src/geometry/Z2-geometry/struct/point.hpp\"\n\nnamespace luz {\n\
    \ \nnamespace Z2 {\n\n  template< typename Z >\n  using Point = Vector< Z >;\n\
    \n  template< typename Z >\n  using Points = std::vector< Point<Z> >;\n\n} //\
    \ namespace Z2\n\n} // namespace luz\n\n#line 2 \"src/geometry/Z2-geometry/struct/circle.hpp\"\
    \n\n#line 4 \"src/geometry/Z2-geometry/struct/circle.hpp\"\n\nnamespace luz {\n\
    \nnamespace Z2 {\n\n  template< typename Z >\n  class Circle {\n\n    Point< Z\
    \ > center_;\n    Z r_;\n\n   public:\n    Circle() {}\n    Circle(Point< Z >\
    \ center, Z r): center_(center), r_(r) {}\n\n    Point< Z > center() const {\n\
    \      return center_;\n    }\n\n    Z r() const {\n      return r_;\n    }\n\
    \  };\n\n  template< typename Z >\n  using Circles = std::vector< Circle< Z >\
    \ >;\n\n} // namespace Z2\n\n} // namespace luz\n#line 2 \"src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp\"\
    \n\n#line 2 \"src/geometry/Z2-geometry/operation/square.hpp\"\n\nnamespace luz\
    \ {\n\nnamespace Z2 {\n\n  template< typename Z >\n  Z square(const Z z) {\n \
    \   return z * z;\n  }\n\n} // namespace Z2\n\n} // namespace luz\n#line 2 \"\
    src/geometry/Z2-geometry/operation/square-norm.hpp\"\n\n#line 5 \"src/geometry/Z2-geometry/operation/square-norm.hpp\"\
    \n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename Z >\n  Z square_norm(Vector<\
    \ Z > v) {\n    return square(v.x()) + square(v.y());\n  }\n\n} // namespace Z2\n\
    \n} // namespace luz\n#line 7 \"src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp\"\
    \n\n#include <utility>\n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename\
    \ Z >\n  bool is_intersect_cc(Circle< Z > c0, Circle< Z > c1) {\n    if (c0.r()\
    \ > c1.r()) std::swap(c0, c1);\n\n    Z sq_dist = square_norm(c0.center() - c1.center());\n\
    \n    if (sq_dist < square(c1.r() - c0.r())) return false;\n    if (square(c1.r()\
    \ + c0.r()) < sq_dist) return false;\n    return true;\n  }\n\n} // namespace\
    \ Z2\n\n} // namespace luz\n#line 2 \"src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp\"\
    \n\n#line 6 \"src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp\"\
    \n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename Z >\n  bool is_intersect_pc(Point<\
    \ Z > p, Circle< Z > c) {\n    Z sq_norm = square_norm(c.center() - p);\n    return\
    \ sq_norm == square(c.r());\n  }\n\n} // namespace Z2\n\n} // namespace luz\n\
    #line 11 \"test/atcoder/abc259_d.test.cpp\"\n\n#include <iostream>\n#include <atcoder/dsu>\n\
    \nnamespace luz {\n\n  void main_() {\n    usize n;\n    std::cin >> n;\n\n  \
    \  i64 sx, sy, tx, ty;\n    std::cin >> sx >> sy >> tx >> ty;\n\n    using namespace\
    \ Z2;\n    Point< i64 > s(sx, sy), t(tx, ty);\n\n    Circles< i64 > cs;\n    for\
    \ (usize _: rep(0, n)) {\n      i64 x, y, r;\n      std::cin >> x >> y >> r;\n\
    \n      cs.emplace_back(Point<i64>(x, y), r);\n    }\n\n    atcoder::dsu uf(n\
    \ + 2);\n    usize s_idx = n, t_idx = n + 1;\n\n    for (usize i: rep(0, n)) {\n\
    \      if (is_intersect_pc(s, cs[i])) {\n        uf.merge(s_idx, i);\n      }\n\
    \      if (is_intersect_pc(t, cs[i])) {\n        uf.merge(i, t_idx);\n      }\n\
    \    }\n\n    for (usize i: rep(0, n)) for (usize j: rep(0, i)) {\n      if (is_intersect_cc(cs[i],\
    \ cs[j])) {\n        uf.merge(i, j);\n      }\n    }\n\n    std::cout << (uf.same(s_idx,\
    \ t_idx) ? \"Yes\" : \"No\") << std::endl;\n\n  }\n\n} // namespace luz\n\nint\
    \ main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_d\n\
    // verification-helper: IGNORE\n\n#include \"src/cpp-template/header/type-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n\n#include \"src/geometry/Z2-geometry/struct/point.hpp\"\
    \n#include \"src/geometry/Z2-geometry/struct/circle.hpp\"\n#include \"src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp\"\
    \n#include \"src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp\"\
    \n\n#include <iostream>\n#include <atcoder/dsu>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    usize n;\n    std::cin >> n;\n\n    i64 sx, sy, tx, ty;\n    std::cin\
    \ >> sx >> sy >> tx >> ty;\n\n    using namespace Z2;\n    Point< i64 > s(sx,\
    \ sy), t(tx, ty);\n\n    Circles< i64 > cs;\n    for (usize _: rep(0, n)) {\n\
    \      i64 x, y, r;\n      std::cin >> x >> y >> r;\n\n      cs.emplace_back(Point<i64>(x,\
    \ y), r);\n    }\n\n    atcoder::dsu uf(n + 2);\n    usize s_idx = n, t_idx =\
    \ n + 1;\n\n    for (usize i: rep(0, n)) {\n      if (is_intersect_pc(s, cs[i]))\
    \ {\n        uf.merge(s_idx, i);\n      }\n      if (is_intersect_pc(t, cs[i]))\
    \ {\n        uf.merge(i, t_idx);\n      }\n    }\n\n    for (usize i: rep(0, n))\
    \ for (usize j: rep(0, i)) {\n      if (is_intersect_cc(cs[i], cs[j])) {\n   \
    \     uf.merge(i, j);\n      }\n    }\n\n    std::cout << (uf.same(s_idx, t_idx)\
    \ ? \"Yes\" : \"No\") << std::endl;\n\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/geometry/Z2-geometry/struct/point.hpp
  - src/geometry/Z2-geometry/struct/vector.hpp
  - src/geometry/Z2-geometry/struct/circle.hpp
  - src/geometry/Z2-geometry/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2-geometry/operation/square.hpp
  - src/geometry/Z2-geometry/operation/square-norm.hpp
  - src/geometry/Z2-geometry/intersect/is-intersect-point-circle.hpp
  isVerificationFile: true
  path: test/atcoder/abc259_d.test.cpp
  requiredBy: []
  timestamp: '2022-07-16 05:05:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc259_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc259_d.test.cpp
- /verify/test/atcoder/abc259_d.test.cpp.html
title: test/atcoder/abc259_d.test.cpp
---
