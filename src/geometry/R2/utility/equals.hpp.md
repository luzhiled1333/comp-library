---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/numbers/eps.hpp
    title: src/geometry/R2/numbers/eps.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/numbers/sign.hpp
    title: src/geometry/R2/numbers/sign.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/utility/sign.hpp
    title: src/geometry/R2/utility/sign.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/R2/class/circle.hpp
    title: src/geometry/R2/class/circle.hpp
  - icon: ':warning:'
    path: src/geometry/R2/class/line.hpp
    title: src/geometry/R2/class/line.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/class/point.hpp
    title: src/geometry/R2/class/point.hpp
  - icon: ':warning:'
    path: src/geometry/R2/class/polygon.hpp
    title: src/geometry/R2/class/polygon.hpp
  - icon: ':warning:'
    path: src/geometry/R2/class/segment.hpp
    title: src/geometry/R2/class/segment.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/class/vector.hpp
    title: src/geometry/R2/class/vector.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unit-test/geometry/R2/class/vector-and-point.test.cpp
    title: unit-test/geometry/R2/class/vector-and-point.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/R2/utility/equals.hpp\"\n\n#line 2 \"src/geometry/R2/numbers/sign.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 4 \"src/geometry/R2/numbers/sign.hpp\"\
    \n\nnamespace luz::numbers::sign {\n\n  constexpr i32 negative = -1;\n  constexpr\
    \ i32 zero     = 0;\n  constexpr i32 positive = +1;\n\n} // namespace luz::numbers::sign\n\
    #line 2 \"src/geometry/R2/utility/sign.hpp\"\n\n#line 2 \"src/geometry/R2/numbers/eps.hpp\"\
    \n\n#include <cmath>\n\nnamespace luz::R2 {\n\n  long double &eps() {\n    static\
    \ long double EPS = 1e-10;\n    return EPS;\n  }\n\n  void set_eps(long double\
    \ EPS) {\n    eps() = EPS;\n  }\n\n} // namespace luz::R2\n#line 6 \"src/geometry/R2/utility/sign.hpp\"\
    \n\nnamespace luz::R2 {\n\n  template < typename R >\n  i32 sign(R r) {\n    if\
    \ (r < -eps()) return numbers::sign::negative;\n    if (r > +eps()) return numbers::sign::positive;\n\
    \    return numbers::sign::zero;\n  }\n\n} // namespace luz::R2\n#line 5 \"src/geometry/R2/utility/equals.hpp\"\
    \n\nnamespace luz::R2 {\n\n  template < typename R >\n  bool equals(R r0, R r1)\
    \ {\n    return sign(r1 - r0) == numbers::sign::zero;\n  }\n\n} // namespace luz::R2\n"
  code: "#pragma once\n\n#include \"src/geometry/R2/numbers/sign.hpp\"\n#include \"\
    src/geometry/R2/utility/sign.hpp\"\n\nnamespace luz::R2 {\n\n  template < typename\
    \ R >\n  bool equals(R r0, R r1) {\n    return sign(r1 - r0) == numbers::sign::zero;\n\
    \  }\n\n} // namespace luz::R2\n"
  dependsOn:
  - src/geometry/R2/numbers/sign.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/geometry/R2/utility/sign.hpp
  - src/geometry/R2/numbers/eps.hpp
  isVerificationFile: false
  path: src/geometry/R2/utility/equals.hpp
  requiredBy:
  - src/geometry/R2/class/vector.hpp
  - src/geometry/R2/class/segment.hpp
  - src/geometry/R2/class/line.hpp
  - src/geometry/R2/class/circle.hpp
  - src/geometry/R2/class/point.hpp
  - src/geometry/R2/class/polygon.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/geometry/R2/class/vector-and-point.test.cpp
documentation_of: src/geometry/R2/utility/equals.hpp
layout: document
redirect_from:
- /library/src/geometry/R2/utility/equals.hpp
- /library/src/geometry/R2/utility/equals.hpp.html
title: src/geometry/R2/utility/equals.hpp
---
