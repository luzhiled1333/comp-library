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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/geometry/R2/class/vector-and-point.test.cpp\"\n\
    // verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#line 2 \"src/geometry/R2/class/point.hpp\"\n\n#line 2 \"src/geometry/R2/class/vector.hpp\"\
    \n\n#line 2 \"src/geometry/R2/utility/equals.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 2 \"src/geometry/R2/numbers/sign.hpp\"\n\nnamespace\
    \ luz::numbers::sign {\n\n  constexpr i32 negative = -1;\n  constexpr i32 zero\
    \     = 0;\n  constexpr i32 positive = +1;\n\n} // namespace luz::numbers::sign\n\
    #line 2 \"src/geometry/R2/utility/sign.hpp\"\n\n#line 2 \"src/geometry/R2/numbers/eps.hpp\"\
    \n\n#include <cmath>\n\nnamespace luz::R2 {\n\n  long double &eps() {\n    static\
    \ long double EPS = 1e-10;\n    return EPS;\n  }\n\n  void set_eps(long double\
    \ EPS) {\n    eps() = EPS;\n  }\n\n} // namespace luz::R2\n#line 6 \"src/geometry/R2/utility/sign.hpp\"\
    \n\nnamespace luz::R2 {\n\n  template < typename R >\n  i32 sign(R r) {\n    if\
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
    \ >;\n\n} // namespace luz::R2\n#line 5 \"unit-test/geometry/R2/class/vector-and-point.test.cpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    using R =\
    \ double;\n\n    using Vector = R2::Vector< R >;\n    Vector a(3.0, 2.5);\n  \
    \  a += 3 * (Vector(2.0, 2.5) + Vector(-3.0, 2.0)) * 2;\n    a -= (Vector(4.0,\
    \ 1.5) - Vector(-8.0, 1.0)) / 3;\n\n    a *= 3;\n    a /= 2;\n\n    using Point\
    \ = R2::Point< R >;\n    Point b(3.0, 2.5);\n    b += 3 * (Point(2.0, 2.5) + Point(-3.0,\
    \ 2.0)) * 2;\n    b -= (Point(4.0, 1.5) - Point(-8.0, 1.0)) / 3;\n\n    b *= 3;\n\
    \    b /= 2;\n\n    a += Point(Point(1.0, 0.0) + Vector(0.0, 1.0));\n    b +=\
    \ Vector(Vector(1.0, 0.0) + Point(0.0, 1.0));\n\n    std::cout << \"Hello World\"\
    \ << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/geometry/R2/class/point.hpp\"\n#include \"src/geometry/R2/class/vector.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    using R =\
    \ double;\n\n    using Vector = R2::Vector< R >;\n    Vector a(3.0, 2.5);\n  \
    \  a += 3 * (Vector(2.0, 2.5) + Vector(-3.0, 2.0)) * 2;\n    a -= (Vector(4.0,\
    \ 1.5) - Vector(-8.0, 1.0)) / 3;\n\n    a *= 3;\n    a /= 2;\n\n    using Point\
    \ = R2::Point< R >;\n    Point b(3.0, 2.5);\n    b += 3 * (Point(2.0, 2.5) + Point(-3.0,\
    \ 2.0)) * 2;\n    b -= (Point(4.0, 1.5) - Point(-8.0, 1.0)) / 3;\n\n    b *= 3;\n\
    \    b /= 2;\n\n    a += Point(Point(1.0, 0.0) + Vector(0.0, 1.0));\n    b +=\
    \ Vector(Vector(1.0, 0.0) + Point(0.0, 1.0));\n\n    std::cout << \"Hello World\"\
    \ << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/geometry/R2/class/point.hpp
  - src/geometry/R2/class/vector.hpp
  - src/geometry/R2/utility/equals.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/geometry/R2/numbers/sign.hpp
  - src/geometry/R2/utility/sign.hpp
  - src/geometry/R2/numbers/eps.hpp
  - src/geometry/R2/utility/is-fp-exception.hpp
  isVerificationFile: true
  path: unit-test/geometry/R2/class/vector-and-point.test.cpp
  requiredBy: []
  timestamp: '2023-02-03 00:11:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/geometry/R2/class/vector-and-point.test.cpp
layout: document
redirect_from:
- /verify/unit-test/geometry/R2/class/vector-and-point.test.cpp
- /verify/unit-test/geometry/R2/class/vector-and-point.test.cpp.html
title: unit-test/geometry/R2/class/vector-and-point.test.cpp
---