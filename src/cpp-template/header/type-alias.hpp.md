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
    title: make vector
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/template-header.hpp
    title: Template Header
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/vector-ios.hpp
    title: vector I/O
  - icon: ':warning:'
    path: src/cpp-template/template.cpp
    title: template
  - icon: ':heavy_check_mark:'
    path: src/data-structure/disjoint-set-union.hpp
    title: src/data-structure/disjoint-set-union.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra's Algorithm
  - icon: ':warning:'
    path: src/graph/functional-graph-utility.hpp
    title: src/graph/functional-graph-utility.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/graph/offline-query-lowest-common-ancestor.hpp
    title: src/graph/offline-query-lowest-common-ancestor.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/bitwise-xor-convolution.hpp
    title: src/math/convolution/bitwise-xor-convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/convolution/fast-walsh-hadamard-transform.hpp
    title: "\u9AD8\u901F\u30A6\u30A9\u30EB\u30B7\u30E5-\u30A2\u30C0\u30DE\u30FC\u30EB\
      \u5909\u63DB/\u9006\u5909\u63DB (Fast Walsh Hadamard Transform / Inverse Transform)"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/sequence/coordinate-compression.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':warning:'
    path: test/atcoder/abc259_d.cpp
    title: test/atcoder/abc259_d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-1-a.test.cpp
    title: test/aoj/dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-1-a.test.cpp
    title: test/aoj/grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-5-c.test.cpp
    title: test/aoj/grl-5-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.test.cpp
    title: test/aoj/itp1-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc177_d.test.cpp
    title: test/atcoder/abc177_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_xor_convolution.test.cpp
    title: test/library-checker/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/math/modular-arithmetic/static-modint.test.cpp
    title: unit-test/math/modular-arithmetic/static-modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/sequence/coordinate-complession.test.cpp
    title: unit-test/sequence/coordinate-complession.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - test/atcoder/abc259_d.cpp
  - src/math/convolution/fast-walsh-hadamard-transform.hpp
  - src/math/convolution/bitwise-xor-convolution.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  - src/graph/graph-template.hpp
  - src/graph/dijkstra.hpp
  - src/graph/functional-graph-utility.hpp
  - src/graph/offline-query-lowest-common-ancestor.hpp
  - src/data-structure/disjoint-set-union.hpp
  - src/sequence/coordinate-compression.hpp
  - src/cpp-template/header/make-vector.hpp
  - src/cpp-template/header/template-header.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/vector-ios.hpp
  - src/cpp-template/header/io-set.hpp
  - src/cpp-template/header/input.hpp
  - src/cpp-template/template.cpp
  timestamp: '2022-07-16 00:29:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/math/modular-arithmetic/static-modint.test.cpp
  - unit-test/sequence/coordinate-complession.test.cpp
  - test/library-checker/bitwise_xor_convolution.test.cpp
  - test/atcoder/abc177_d.test.cpp
  - test/atcoder/abc212_h.test.cpp
  - test/aoj/grl-5-c.test.cpp
  - test/aoj/itp1-1-a.test.cpp
  - test/aoj/grl-1-a.test.cpp
  - test/aoj/dsl-1-a.test.cpp
documentation_of: src/cpp-template/header/type-alias.hpp
layout: document
title: Type alias
---
