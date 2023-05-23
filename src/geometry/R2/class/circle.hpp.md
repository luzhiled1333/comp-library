---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/class/point.hpp
    title: src/geometry/R2/class/point.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/class/vector.hpp
    title: src/geometry/R2/class/vector.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/numbers/eps.hpp
    title: src/geometry/R2/numbers/eps.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/numbers/sign.hpp
    title: src/geometry/R2/numbers/sign.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/utility/equals.hpp
    title: src/geometry/R2/utility/equals.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/utility/is-fp-exception.hpp
    title: src/geometry/R2/utility/is-fp-exception.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/utility/sign.hpp
    title: src/geometry/R2/utility/sign.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/R2/class/circle.hpp\"\n\n#line 2 \"src/geometry/R2/class/point.hpp\"\
    \n\n#line 2 \"src/geometry/R2/class/vector.hpp\"\n\n#line 2 \"src/geometry/R2/utility/equals.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/geometry/R2/numbers/sign.hpp\"\n\nnamespace luz::numbers::sign\
    \ {\n\n  constexpr i32 negative = -1;\n  constexpr i32 zero     = 0;\n  constexpr\
    \ i32 positive = +1;\n\n} // namespace luz::numbers::sign\n#line 2 \"src/geometry/R2/utility/sign.hpp\"\
    \n\n#line 2 \"src/geometry/R2/numbers/eps.hpp\"\n\n#include <cmath>\n\nnamespace\
    \ luz::R2 {\n\n  long double &eps() {\n    static long double EPS = 1e-10;\n \
    \   return EPS;\n  }\n\n  void set_eps(long double EPS) {\n    eps() = EPS;\n\
    \  }\n\n} // namespace luz::R2\n#line 6 \"src/geometry/R2/utility/sign.hpp\"\n\
    \nnamespace luz::R2 {\n\n  template < typename R >\n  i32 sign(R r) {\n    if\
    \ (r < -eps()) return numbers::sign::negative;\n    if (r > +eps()) return numbers::sign::positive;\n\
    \    return numbers::sign::zero;\n  }\n\n} // namespace luz::R2\n#line 6 \"src/geometry/R2/utility/equals.hpp\"\
    \n\nnamespace luz::R2 {\n\n  template < typename R >\n  i32 equals(R r0, R r1)\
    \ {\n    return sign(r1 - r0) == numbers::sign::zero;\n  }\n\n} // namespace luz::R2\n\
    #line 2 \"src/geometry/R2/utility/is-fp-exception.hpp\"\n\n#line 4 \"src/geometry/R2/utility/is-fp-exception.hpp\"\
    \n\nnamespace luz::R2 {\n\n  template < typename R >\n  bool is_fp_exception(R\
    \ r) {\n    return std::isinf(r) or std::isnan(r);\n  }\n\n} // namespace luz::R2\n\
    #line 5 \"src/geometry/R2/class/vector.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace luz::R2 {\n\n  template < typename R >\n  class Vector {\n\n    R\
    \ x_, y_;\n\n   public:\n    Vector(): x_(0), y_(0) {}\n    Vector(R x, R y):\
    \ x_(x), y_(y) {\n      assert(not is_fp_exception(x_) and not is_fp_exception(y_));\n\
    \    }\n\n    R x() const {\n      return x_;\n    }\n\n    R y() const {\n  \
    \    return y_;\n    }\n\n    friend bool equals(const Vector &v0, const Vector\
    \ &v1) {\n      return equals(v0.x(), v1.x()) and equals(v0.y(), v1.y());\n  \
    \  }\n\n    Vector &operator+=(const Vector &v) {\n      x_ += v.x_;\n      y_\
    \ += v.y_;\n      return *this;\n    }\n    Vector &operator-=(const Vector &v)\
    \ {\n      x_ -= v.x_;\n      y_ -= v.y_;\n      return *this;\n    }\n\n    Vector\
    \ operator+(const Vector &v) const {\n      return Vector(*this) += v;\n    }\n\
    \    Vector operator-(const Vector &v) const {\n      return Vector(*this) -=\
    \ v;\n    }\n\n    Vector operator+() const {\n      return *this;\n    }\n  \
    \  Vector operator-() const {\n      return Vector() - *this;\n    }\n\n    Vector\
    \ &operator*=(const R r) {\n      x_ *= r;\n      y_ *= r;\n      return *this;\n\
    \    }\n    Vector &operator/=(const R r) {\n      x_ /= r;\n      y_ /= r;\n\
    \      return *this;\n    }\n\n    Vector operator*(const R r) const {\n     \
    \ return Vector(*this) *= r;\n    }\n    Vector operator/(const R r) const {\n\
    \      return Vector(*this) /= r;\n    }\n\n    friend Vector operator*(const\
    \ R r, const Vector &v) {\n      return Vector(v) *= r;\n    }\n  };\n\n  template\
    \ < typename R >\n  using Vectors = std::vector< Vector< R > >;\n\n} // namespace\
    \ luz::R2\n#line 4 \"src/geometry/R2/class/point.hpp\"\n\n#line 6 \"src/geometry/R2/class/point.hpp\"\
    \n\nnamespace luz::R2 {\n\n  template < typename R >\n  using Point = Vector<\
    \ R >;\n\n  template < typename R >\n  using Points = std::vector< Point< R >\
    \ >;\n\n} // namespace luz::R2\n#line 5 \"src/geometry/R2/class/circle.hpp\"\n\
    \n#line 9 \"src/geometry/R2/class/circle.hpp\"\n\nnamespace luz::R2 {\n\n  template\
    \ < typename R >\n  class Circle {\n\n    Point< R > o_;\n    Z r_;\n\n   public:\n\
    \    Circle() {}\n\n    Circle(Point< R > o, R r): o_(o), r_(r) {\n      assert(not\
    \ is_fp_exception(r_));\n      assert(not std::signbit(r_));\n    }\n\n    Point<\
    \ R > center() const {\n      return o_;\n    }\n\n    Z r() const {\n      r_;\n\
    \    }\n  };\n\n  template < typename R >\n  using Circles = std::vector< Circle<\
    \ R > >;\n} // namespace luz::R2\n"
  code: "#pragma once\n\n#include \"src/geometry/R2/class/point.hpp\"\n#include \"\
    src/geometry/R2/utility/is-fp-exception.hpp\"\n\n#include <cassert>\n#include\
    \ <cmath>\n#include <vector>\n\nnamespace luz::R2 {\n\n  template < typename R\
    \ >\n  class Circle {\n\n    Point< R > o_;\n    Z r_;\n\n   public:\n    Circle()\
    \ {}\n\n    Circle(Point< R > o, R r): o_(o), r_(r) {\n      assert(not is_fp_exception(r_));\n\
    \      assert(not std::signbit(r_));\n    }\n\n    Point< R > center() const {\n\
    \      return o_;\n    }\n\n    Z r() const {\n      r_;\n    }\n  };\n\n  template\
    \ < typename R >\n  using Circles = std::vector< Circle< R > >;\n} // namespace\
    \ luz::R2\n"
  dependsOn:
  - src/geometry/R2/class/point.hpp
  - src/geometry/R2/class/vector.hpp
  - src/geometry/R2/utility/equals.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/geometry/R2/numbers/sign.hpp
  - src/geometry/R2/utility/sign.hpp
  - src/geometry/R2/numbers/eps.hpp
  - src/geometry/R2/utility/is-fp-exception.hpp
  isVerificationFile: false
  path: src/geometry/R2/class/circle.hpp
  requiredBy: []
  timestamp: '2023-02-03 00:11:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/R2/class/circle.hpp
layout: document
redirect_from:
- /library/src/geometry/R2/class/circle.hpp
- /library/src/geometry/R2/class/circle.hpp.html
title: src/geometry/R2/class/circle.hpp
---