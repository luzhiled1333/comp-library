---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: src/cpp-template/header/template-header.hpp
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-1-a.test.cpp
    title: test/aoj/grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/change-minmax.hpp\"\n\nnamespace\
    \ luz {\n\n  template <typename T1, typename T2>\n  inline bool chmax(T1 &a, T2\
    \ b) {\n    return a < b and (a = b, true);\n  }\n\n  template <typename T1, typename\
    \ T2>\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n"
  code: "#pragma once \n\nnamespace luz {\n\n  template <typename T1, typename T2>\n\
    \  inline bool chmax(T1 &a, T2 b) {\n    return a < b and (a = b, true);\n  }\n\
    \n  template <typename T1, typename T2>\n  inline bool chmin(T1 &a, T2 b) {\n\
    \    return a > b and (a = b, true);\n  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/change-minmax.hpp
  requiredBy:
  - src/graph/dijkstra.hpp
  - src/cpp-template/template.cpp
  - src/cpp-template/header/template-header.hpp
  timestamp: '2022-06-13 01:05:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1-1-a.test.cpp
  - test/aoj/grl-1-a.test.cpp
documentation_of: src/cpp-template/header/change-minmax.hpp
layout: document
title: chmin / chmax
---

## chmin
```
bool chmin(T1 &a, T2 b)
```

`a` よりも `b` のほうが小さいとき `a` の値を `b` に変更する。
更新があったときのみ `true` を返す。

## chmax
```
bool chmax(T1 &a, T2 b)
```

`a` よりも `b` のほうが大きいとき `a` の値を `b` に変更する。
更新があったときのみ `true` を返す。