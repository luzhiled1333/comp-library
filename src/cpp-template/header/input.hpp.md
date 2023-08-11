---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/dynamic-graph.test.cpp
    title: test/aoj/grl_1_a/dynamic-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_1_a/static-graph.test.cpp
    title: test/aoj/grl_1_a/static-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl_6_a.test.cpp
    title: test/aoj/grl_6_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1_1_a.test.cpp
    title: test/aoj/itp1_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/input.hpp\"\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/cpp-template/header/input.hpp\"\n\n#include <iostream>\n\n\
    namespace luz {\n\n  template < typename T = i64 >\n  T input() {\n    T tmp;\n\
    \    std::cin >> tmp;\n    return tmp;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n\n#include\
    \ <iostream>\n\nnamespace luz {\n\n  template < typename T = i64 >\n  T input()\
    \ {\n    T tmp;\n    std::cin >> tmp;\n    return tmp;\n  }\n\n} // namespace\
    \ luz\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: false
  path: src/cpp-template/header/input.hpp
  requiredBy:
  - src/cpp-template/template.cpp
  - src/cpp-template/header/template-header.hpp
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/itp1_1_a.test.cpp
  - test/aoj/grl_1_a/dynamic-graph.test.cpp
  - test/aoj/grl_1_a/static-graph.test.cpp
  - test/aoj/grl_6_a.test.cpp
  - test/atcoder/abc212_h.test.cpp
documentation_of: src/cpp-template/header/input.hpp
layout: document
title: input
---

## input
```
T input()
```

値を一つ受け取って返す。

unused variable との相性がよい。
