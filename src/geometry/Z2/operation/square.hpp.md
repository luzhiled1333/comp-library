---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
    title: "\u5186\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/intersect/is-intersect-point-circle.hpp
    title: "\u70B9\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/ccw.hpp
    title: src/geometry/Z2/operation/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/operation/square-norm.hpp
    title: "$\\|v\\|^2 (v \\in {\\mathbb{Z}}^2)$ (norm\u306E2\u4E57)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/Z2/segment-function/counterbalance-segments.hpp
    title: src/geometry/Z2/segment-function/counterbalance-segments.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/4011.test.cpp
    title: test/aoj/4011.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc259_d.test.cpp
    title: test/atcoder/abc259_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Z2/operation/square.hpp\"\n\nnamespace luz::Z2\
    \ {\n\n  template < typename Z >\n  Z square(const Z x) {\n    return x * x;\n\
    \  }\n\n} // namespace luz::Z2\n"
  code: "#pragma once\n\nnamespace luz::Z2 {\n\n  template < typename Z >\n  Z square(const\
    \ Z x) {\n    return x * x;\n  }\n\n} // namespace luz::Z2\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Z2/operation/square.hpp
  requiredBy:
  - src/geometry/Z2/intersect/is-intersect-circle-circle.hpp
  - src/geometry/Z2/intersect/is-intersect-point-circle.hpp
  - src/geometry/Z2/operation/square-norm.hpp
  - src/geometry/Z2/operation/ccw.hpp
  - src/geometry/Z2/segment-function/counterbalance-segments.hpp
  timestamp: '2022-08-22 18:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc259_d.test.cpp
  - test/aoj/4011.test.cpp
documentation_of: src/geometry/Z2/operation/square.hpp
layout: document
title: $x^2 (x \in \mathbb{Z})$
---

## square
```
Z square(Z x)
```

`x` を2乗して返す。

オーバーフローに注意。
