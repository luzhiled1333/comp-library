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
  bundledCode: "#line 2 \"src/geometry/R2/numbers/eps.hpp\"\n\n#include <cmath>\n\n\
    namespace luz::R2 {\n\n  long double &eps() {\n    static long double EPS = 1e-10;\n\
    \    return EPS;\n  }\n\n  void set_eps(long double EPS) {\n    eps() = EPS;\n\
    \  }\n\n} // namespace luz::R2\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace luz::R2 {\n\n  long double\
    \ &eps() {\n    static long double EPS = 1e-10;\n    return EPS;\n  }\n\n  void\
    \ set_eps(long double EPS) {\n    eps() = EPS;\n  }\n\n} // namespace luz::R2\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/R2/numbers/eps.hpp
  requiredBy:
  - src/geometry/R2/class/vector.hpp
  - src/geometry/R2/class/segment.hpp
  - src/geometry/R2/class/line.hpp
  - src/geometry/R2/class/circle.hpp
  - src/geometry/R2/class/point.hpp
  - src/geometry/R2/class/polygon.hpp
  - src/geometry/R2/utility/sign.hpp
  - src/geometry/R2/utility/equals.hpp
  timestamp: '2023-02-03 00:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/geometry/R2/class/vector-and-point.test.cpp
documentation_of: src/geometry/R2/numbers/eps.hpp
layout: document
redirect_from:
- /library/src/geometry/R2/numbers/eps.hpp
- /library/src/geometry/R2/numbers/eps.hpp.html
title: src/geometry/R2/numbers/eps.hpp
---
