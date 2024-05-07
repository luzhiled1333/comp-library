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
  - icon: ':heavy_check_mark:'
    path: src/graph/decomposition/strongly-connected-components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3(Decomposition of Strongly Connected\
      \ Components, SCC)"
  - icon: ':heavy_check_mark:'
    path: src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
    title: "\u975E\u8CA0\u91CD\u307F\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
      \ (Single Source Shortest Path in Non-negative Weighted Graph, Dijkstra's Algorithm)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/dynamic-graph.test.cpp
    title: test/aoj/grl_1_a/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/static-graph.test.cpp
    title: test/aoj/grl_1_a/static-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1_1_a.test.cpp
    title: test/aoj/itp1_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc259_c.test.cpp
    title: test/atcoder/abc259_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/scc.test.cpp
    title: test/library-checker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/change-min.hpp\"\n\nnamespace luz\
    \ {\n\n  template < typename T1, typename T2 >\n  inline bool chmin(T1 &a, T2\
    \ b) {\n    return a > b and (a = b, true);\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\nnamespace luz {\n\n  template < typename T1, typename T2\
    \ >\n  inline bool chmin(T1 &a, T2 b) {\n    return a > b and (a = b, true);\n\
    \  }\n\n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/change-min.hpp
  requiredBy:
  - src/graph/decomposition/strongly-connected-components.hpp
  - src/graph/single-source-shortest-path/in-non-negative-weighted-graph.hpp
  - src/cpp-template/template.cpp
  - src/cpp-template/header/template-header.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/scc.test.cpp
  - test/atcoder/abc259_c.test.cpp
  - test/aoj/itp1_1_a.test.cpp
  - test/aoj/grl_1_a/static-graph.test.cpp
  - test/aoj/grl_1_a/dynamic-graph.test.cpp
documentation_of: src/cpp-template/header/change-min.hpp
layout: document
title: chmin
---

## chmin
```
bool chmin(T1 &a, T2 b)
```

`a` よりも `b` のほうが小さいとき `a` の値を `b` に変更する。
更新があったときのみ `true` を返す。
