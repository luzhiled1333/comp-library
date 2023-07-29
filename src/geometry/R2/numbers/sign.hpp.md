---
data:
  _extendedDependsOn: []
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
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/utility/equals.hpp
    title: src/geometry/R2/utility/equals.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/R2/utility/sign.hpp
    title: src/geometry/R2/utility/sign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unit-test/geometry/R2/class/vector-and-point.test.cpp
    title: unit-test/geometry/R2/class/vector-and-point.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/R2/numbers/sign.hpp\"\n\nnamespace luz::numbers::sign\
    \ {\n\n  constexpr i32 negative = -1;\n  constexpr i32 zero     = 0;\n  constexpr\
    \ i32 positive = +1;\n\n} // namespace luz::numbers::sign\n"
  code: "#pragma once\n\nnamespace luz::numbers::sign {\n\n  constexpr i32 negative\
    \ = -1;\n  constexpr i32 zero     = 0;\n  constexpr i32 positive = +1;\n\n} //\
    \ namespace luz::numbers::sign\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/R2/numbers/sign.hpp
  requiredBy:
  - src/geometry/R2/utility/sign.hpp
  - src/geometry/R2/utility/equals.hpp
  - src/geometry/R2/class/segment.hpp
  - src/geometry/R2/class/polygon.hpp
  - src/geometry/R2/class/point.hpp
  - src/geometry/R2/class/line.hpp
  - src/geometry/R2/class/circle.hpp
  - src/geometry/R2/class/vector.hpp
  timestamp: '2023-02-03 00:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/geometry/R2/class/vector-and-point.test.cpp
documentation_of: src/geometry/R2/numbers/sign.hpp
layout: document
redirect_from:
- /library/src/geometry/R2/numbers/sign.hpp
- /library/src/geometry/R2/numbers/sign.hpp.html
title: src/geometry/R2/numbers/sign.hpp
---
