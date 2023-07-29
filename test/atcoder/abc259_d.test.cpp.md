---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':question:'
    path: src/data-structure/disjoint-set-union.hpp
    title: Disjoint Set Union (Union Find)
  - icon: ':x:'
    path: src/geometry/Z2/class/circle.hpp
    title: "\u5186 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':question:'
    path: src/geometry/Z2/class/point.hpp
    title: "\u683C\u5B50\u70B9 (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':question:'
    path: src/geometry/Z2/class/vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB (\u6574\u6570\u5E7E\u4F55)"
  - icon: ':x:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':x:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':question:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  - icon: ':question:'
    path: src/geometry/Z2/operation/square.hpp
    title: $x^2 (x \in \mathbb{Z})$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc259/tasks/abc259_d
    links:
    - https://atcoder.jp/contests/abc259/tasks/abc259_d
  bundledCode: "#line 1 \"test/atcoder/abc259_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_d\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 2 \"src/data-structure/disjoint-set-union.hpp\"\n\n#line 5 \"src/data-structure/disjoint-set-union.hpp\"\
    \n\n#line 7 \"src/data-structure/disjoint-set-union.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace luz {\n\n  class DisjointSetUnion {\n    usize\
    \ n;\n\n    // vals[v] :=\n    //   if v is root node: -1 * component size\n \
    \   //   otherwise: parent node\n    std::vector< isize > vals;\n\n    void bound_check(usize\
    \ v) const {\n      assert(v < n);\n    }\n\n    usize impl_leader(usize v) {\n\
    \      if (vals[v] < 0) return v;\n      return vals[v] = leader(vals[v]);\n \
    \   }\n\n   public:\n    DisjointSetUnion() = default;\n    explicit DisjointSetUnion(usize\
    \ n): n(n), vals(n, -1) {}\n\n    usize size() const {\n      return n;\n    }\n\
    \n    usize leader(usize v) {\n      bound_check(v);\n      return impl_leader(v);\n\
    \    }\n\n    bool same(usize u, usize v) {\n      bound_check(u), bound_check(v);\n\
    \      return impl_leader(u) == impl_leader(v);\n    }\n\n    usize merge(usize\
    \ u, usize v) {\n      bound_check(u);\n      bound_check(v);\n\n      isize x\
    \ = impl_leader(u);\n      isize y = impl_leader(v);\n      if (x == y) return\
    \ x;\n      if (-vals[x] < -vals[y]) std::swap(x, y);\n      vals[x] += vals[y];\n\
    \      vals[y] = x;\n      return x;\n    }\n\n    usize group_size(usize v) {\n\
    \      bound_check(v);\n      return -vals[impl_leader(v)];\n    }\n\n    std::vector<\
    \ std::vector< usize > > groups() {\n      std::vector< std::vector< usize > >\
    \ result(n);\n\n      std::vector< usize > leaders(n), g_sizes(n);\n      for\
    \ (usize v: rep(0, n)) {\n        leaders[v] = impl_leader(v);\n        g_sizes[leaders[v]]++;\n\
    \      }\n      for (usize v: rep(0, n)) {\n        result[v].reserve(g_sizes[v]);\n\
    \      }\n      for (usize v: rep(0, n)) {\n        result[leaders[v]].emplace_back(v);\n\
    \      }\n\n      auto empty_check = [](const std::vector< usize > &vs) {\n  \
    \      return vs.empty();\n      };\n      result.erase(\n          std::remove_if(result.begin(),\
    \ result.end(), empty_check),\n          result.end());\n\n      return result;\n\
    \    }\n  };\n\n} // namespace luz\n#line 2 \"src/geometry/Z2/class/circle.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/class/point.hpp\"\n\n#line 2 \"src/geometry/Z2/class/vector.hpp\"\
    \n\n#line 4 \"src/geometry/Z2/class/vector.hpp\"\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  class Vector {\n\n    Z x_, y_;\n\n   public:\n    Vector():\
    \ x_(0), y_(0) {}\n    Vector(Z x, Z y): x_(x), y_(y) {}\n\n    Z x() const {\n\
    \      return x_;\n    }\n\n    Z y() const {\n      return y_;\n    }\n\n   \
    \ bool operator==(const Vector &v) const {\n      return x_ == v.x_ and y_ ==\
    \ v.y_;\n    }\n\n    bool operator!=(const Vector &v) const {\n      return x_\
    \ != v.x_ or y_ != v.y_;\n    }\n\n    Vector &operator+=(const Vector &v) {\n\
    \      x_ += v.x_;\n      y_ += v.y_;\n      return *this;\n    }\n    Vector\
    \ &operator-=(const Vector &v) {\n      x_ -= v.x_;\n      y_ -= v.y_;\n     \
    \ return *this;\n    }\n\n    Vector operator+(const Vector &v) const {\n    \
    \  return Vector(*this) += v;\n    }\n    Vector operator-(const Vector &v) const\
    \ {\n      return Vector(*this) -= v;\n    }\n\n    Vector operator+() const {\n\
    \      return *this;\n    }\n    Vector operator-() const {\n      return Vector()\
    \ - *this;\n    }\n  };\n\n  template < typename Z >\n  using Vectors = std::vector<\
    \ Vector< Z > >;\n\n} // namespace luz::Z2\n#line 4 \"src/geometry/Z2/class/point.hpp\"\
    \n\n#line 6 \"src/geometry/Z2/class/point.hpp\"\n\nnamespace luz::Z2 {\n\n  template\
    \ < typename Z >\n  using Point = Vector< Z >;\n\n  template < typename Z >\n\
    \  using Points = std::vector< Point< Z > >;\n\n} // namespace luz::Z2\n#line\
    \ 4 \"src/geometry/Z2/class/circle.hpp\"\n\n#line 6 \"src/geometry/Z2/class/circle.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  class Circle {\n\n   \
    \ Point< Z > o_;\n    Z r_;\n\n   public:\n    Circle(): o_(0, 0), r_(0) {}\n\n\
    \    Circle(Point< Z > o, Z r): o_(o), r_(r) {\n      assert(r >= 0);\n    }\n\
    \n    Point< Z > center() const {\n      return o_;\n    }\n\n    Z r() const\
    \ {\n      return r_;\n    }\n  };\n\n  template < typename Z >\n  using Circles\
    \ = std::vector< Circle< Z > >;\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/intersect/is-intersect-circle-circle.hpp\"\
    \n\n#line 2 \"src/geometry/Z2/operation/square-norm.hpp\"\n\n#line 2 \"src/geometry/Z2/operation/square.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Z square(const Z x) {\n\
    \    return x * x;\n  }\n\n} // namespace luz::Z2\n#line 5 \"src/geometry/Z2/operation/square-norm.hpp\"\
    \n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Z square_norm(Vector<\
    \ Z > v) {\n    return square(v.x()) + square(v.y());\n  }\n\n} // namespace luz::Z2\n\
    #line 7 \"src/geometry/Z2/intersect/is-intersect-circle-circle.hpp\"\n\n#include\
    \ <utility>\n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  bool is_intersect_cc(Circle<\
    \ Z > c0, Circle< Z > c1) {\n    if (c0.r() > c1.r()) std::swap(c0, c1);\n\n \
    \   Z sq_dist = square_norm(c0.center() - c1.center());\n\n    if (sq_dist < square(c1.r()\
    \ - c0.r())) return false;\n    if (square(c1.r() + c0.r()) < sq_dist) return\
    \ false;\n    return true;\n  }\n\n} // namespace luz::Z2\n#line 2 \"src/geometry/Z2/intersect/is-intersect-point-circle.hpp\"\
    \n\n#line 6 \"src/geometry/Z2/intersect/is-intersect-point-circle.hpp\"\n\nnamespace\
    \ luz::Z2 {\n\n  template < typename Z >\n  bool is_intersect_pc(Point< Z > p,\
    \ Circle< Z > c) {\n    Z sq_norm = square_norm(c.center() - p);\n    return sq_norm\
    \ == square(c.r());\n  }\n\n} // namespace luz::Z2\n#line 11 \"test/atcoder/abc259_d.test.cpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n;\n\
    \    std::cin >> n;\n\n    i64 sx, sy, tx, ty;\n    std::cin >> sx >> sy >> tx\
    \ >> ty;\n\n    using namespace Z2;\n    Point< i64 > s(sx, sy), t(tx, ty);\n\n\
    \    Circles< i64 > cs;\n    for ([[maybe_unused]] usize _: rep(0, n)) {\n   \
    \   i64 x, y, r;\n      std::cin >> x >> y >> r;\n\n      cs.emplace_back(Point<\
    \ i64 >(x, y), r);\n    }\n\n    DisjointSetUnion uf(n + 2);\n    usize s_idx\
    \ = n, t_idx = n + 1;\n\n    for (usize i: rep(0, n)) {\n      if (is_intersect_pc(s,\
    \ cs[i])) {\n        uf.merge(s_idx, i);\n      }\n      if (is_intersect_pc(t,\
    \ cs[i])) {\n        uf.merge(i, t_idx);\n      }\n    }\n\n    for (usize i:\
    \ rep(0, n))\n      for (usize j: rep(0, i)) {\n        if (is_intersect_cc(cs[i],\
    \ cs[j])) {\n          uf.merge(i, j);\n        }\n      }\n\n    std::cout <<\
    \ (uf.same(s_idx, t_idx) ? \"Yes\" : \"No\") << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc259/tasks/abc259_d\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/data-structure/disjoint-set-union.hpp\"\
    \n#include \"src/geometry/Z2/class/circle.hpp\"\n#include \"src/geometry/Z2/class/point.hpp\"\
    \n#include \"src/geometry/Z2/intersect/is-intersect-circle-circle.hpp\"\n#include\
    \ \"src/geometry/Z2/intersect/is-intersect-point-circle.hpp\"\n\n#include <iostream>\n\
    \nnamespace luz {\n\n  void main_() {\n    usize n;\n    std::cin >> n;\n\n  \
    \  i64 sx, sy, tx, ty;\n    std::cin >> sx >> sy >> tx >> ty;\n\n    using namespace\
    \ Z2;\n    Point< i64 > s(sx, sy), t(tx, ty);\n\n    Circles< i64 > cs;\n    for\
    \ ([[maybe_unused]] usize _: rep(0, n)) {\n      i64 x, y, r;\n      std::cin\
    \ >> x >> y >> r;\n\n      cs.emplace_back(Point< i64 >(x, y), r);\n    }\n\n\
    \    DisjointSetUnion uf(n + 2);\n    usize s_idx = n, t_idx = n + 1;\n\n    for\
    \ (usize i: rep(0, n)) {\n      if (is_intersect_pc(s, cs[i])) {\n        uf.merge(s_idx,\
    \ i);\n      }\n      if (is_intersect_pc(t, cs[i])) {\n        uf.merge(i, t_idx);\n\
    \      }\n    }\n\n    for (usize i: rep(0, n))\n      for (usize j: rep(0, i))\
    \ {\n        if (is_intersect_cc(cs[i], cs[j])) {\n          uf.merge(i, j);\n\
    \        }\n      }\n\n    std::cout << (uf.same(s_idx, t_idx) ? \"Yes\" : \"\
    No\") << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/data-structure/disjoint-set-union.hpp
  - src/geometry/Z2/class/circle.hpp
  - src/geometry/Z2/class/point.hpp
  - src/geometry/Z2/class/vector.hpp
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  - src/geometry/Z2/operation/square.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  isVerificationFile: true
  path: test/atcoder/abc259_d.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc259_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc259_d.test.cpp
- /verify/test/atcoder/abc259_d.test.cpp.html
title: test/atcoder/abc259_d.test.cpp
---
