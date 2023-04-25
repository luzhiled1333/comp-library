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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: unit-test/geometry/R2/class/vector-and-point.test.cpp
    title: unit-test/geometry/R2/class/vector-and-point.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/R2/utility/is-fp-exception.hpp\"\n\n#include\
    \ <cmath>\n\nnamespace luz::R2 {\n\n  template < typename R >\n  bool is_fp_exception(R\
    \ r) {\n    return std::isinf(r) or std::isnan(r);\n  }\n\n} // namespace luz::R2\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace luz::R2 {\n\n  template < typename\
    \ R >\n  bool is_fp_exception(R r) {\n    return std::isinf(r) or std::isnan(r);\n\
    \  }\n\n} // namespace luz::R2\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/R2/utility/is-fp-exception.hpp
  requiredBy:
  - src/geometry/R2/class/line.hpp
  - src/geometry/R2/class/vector.hpp
  - src/geometry/R2/class/circle.hpp
  - src/geometry/R2/class/point.hpp
  - src/geometry/R2/class/segment.hpp
  - src/geometry/R2/class/polygon.hpp
  timestamp: '2023-02-03 00:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/geometry/R2/class/vector-and-point.test.cpp
documentation_of: src/geometry/R2/utility/is-fp-exception.hpp
layout: document
redirect_from:
- /library/src/geometry/R2/utility/is-fp-exception.hpp
- /library/src/geometry/R2/utility/is-fp-exception.hpp.html
title: src/geometry/R2/utility/is-fp-exception.hpp
---
