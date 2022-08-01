---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':warning:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':warning:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  - icon: ':warning:'
    path: test/atcoder/abc259_d.cpp
    title: test/atcoder/abc259_d.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - test/atcoder/abc259_d.cpp
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  timestamp: '2022-07-21 10:58:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Z2/operation/square.hpp
layout: document
title: $x^2 (x \in \mathbb{Z})$
---