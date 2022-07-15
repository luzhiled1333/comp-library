---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/input.hpp
    title: input
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/io-set.hpp
    title: specify output precision
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/make-vector.hpp
    title: input
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: src/cpp-template/header/rep.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: src/cpp-template/header/template-header.hpp
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/vector-ios.hpp
    title: src/cpp-template/header/vector-ios.hpp
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-1-a.test.cpp
    title: test/aoj/grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc259_d.test.cpp
    title: test/atcoder/abc259_d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n  \n} // namespace\
    \ luz\n"
  code: "#pragma once\n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\
    \n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32\
    \ = std::int32_t;\n  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n\
    \  using u64 = std::uint64_t;\n  \n} // namespace luz\n"
  dependsOn: []
  isVerificationFile: false
  path: src/cpp-template/header/type-alias.hpp
  requiredBy:
  - src/graph/dijkstra.hpp
  - src/graph/graph-template.hpp
  - src/cpp-template/template.cpp
  - src/cpp-template/header/make-vector.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/cpp-template/header/io-set.hpp
  - src/cpp-template/header/input.hpp
  timestamp: '2022-07-16 00:29:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc259_d.test.cpp
  - test/aoj/itp1-1-a.test.cpp
  - test/aoj/grl-1-a.test.cpp
documentation_of: src/cpp-template/header/type-alias.hpp
layout: document
redirect_from:
- /library/src/cpp-template/header/type-alias.hpp
- /library/src/cpp-template/header/type-alias.hpp.html
title: src/cpp-template/header/type-alias.hpp
---