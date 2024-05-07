---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1181.test.cpp
    title: test/aoj/1181.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1_1_a.test.cpp
    title: test/aoj/itp1_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc177_d.test.cpp
    title: test/atcoder/abc177_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc298_f.test.cpp
    title: test/atcoder/abc298_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/change-max.hpp\"\n\nnamespace luz\
    \ {\n\n  template < typename T1, typename T2 >\n  inline bool chmax(T1 &a, T2\
    \ b) {\n    return a < b and (a = b, true);\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\nnamespace luz {\n\n  template < typename T1, typename T2\
    \ >\n  inline bool chmax(T1 &a, T2 b) {\n    return a < b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/change-max.hpp
  requiredBy:
  - src/cpp-template/template.cpp
  - src/cpp-template/header/template-header.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc177_d.test.cpp
  - test/atcoder/abc298_f.test.cpp
  - test/aoj/itp1_1_a.test.cpp
  - test/aoj/1181.test.cpp
documentation_of: src/cpp-template/header/change-max.hpp
layout: document
title: chmax
---

## chmax
```
bool chmax(T1 &a, T2 b)
```

`a` よりも `b` のほうが大きいとき `a` の値を `b` に変更する。
更新があったときのみ `true` を返す。
