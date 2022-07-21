---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - icon: ':x:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  - icon: ':x:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: src/geometry/Z2/operation/square-norm.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc259_d.test.cpp
    title: test/atcoder/abc259_d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/operation/square.hpp\"\n\nnamespace luz\
    \ {\n\nnamespace Z2 {\n\n  template< typename Z >\n  Z square(const Z z) {\n \
    \   return z * z;\n  }\n\n} // namespace Z2\n\n} // namespace luz\n"
  code: "#pragma once\n\nnamespace luz {\n\nnamespace Z2 {\n\n  template< typename\
    \ Z >\n  Z square(const Z z) {\n    return z * z;\n  }\n\n} // namespace Z2\n\n\
    } // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Z2/operation/square.hpp
  requiredBy:
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  timestamp: '2022-07-21 10:58:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc259_d.test.cpp
documentation_of: src/geometry/Z2/operation/square.hpp
layout: document
redirect_from:
- /library/src/geometry/Z2/operation/square.hpp
- /library/src/geometry/Z2/operation/square.hpp.html
title: src/geometry/Z2/operation/square.hpp
---
