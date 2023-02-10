---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/online-query-jump-on-functional-graph.hpp
    title: "(online) Functional Graph \u4E0A\u306E\u9802\u70B9 $v$ \u304B\u3089 $k$\
      \ \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9 (Online Jump On Functional\
      \ Graph)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/bit-width.hpp
    title: "\u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
      \u6700\u5C0F\u306Ebit\u5E45 (bit_width)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/count-leading-0s.hpp
    title: "\u6700\u4E0A\u4F4Dbit\u304B\u3089\u9023\u7D9A\u3059\u308B 0 \u306E\u6570\
      \ (counting leading 0s, countl_zero)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/count-trailing-0s.hpp
    title: "\u6700\u4E0B\u4F4Dbit\u304B\u3089\u9023\u7D9A\u3059\u308B 0 \u306E\u6570\
      \ (counting trailing 0s, countr_zero)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc258_e/online-algorithm.test.cpp
    title: test/atcoder/abc258_e/online-algorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
    title: unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/utility/bit/bit-width.test.cpp
    title: unit-test/utility/bit/bit-width.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/utility/bit/count-leading-0s.test.cpp
    title: unit-test/utility/bit/count-leading-0s.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/utility/bit/count-trailing-0s.test.cpp
    title: unit-test/utility/bit/count-trailing-0s.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/utility/bit/popcount.test.cpp
    title: unit-test/utility/bit/popcount.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/bit/popcount.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/utility/bit/popcount.hpp\"\n\n#include <cassert>\n\
    \nnamespace luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus <= 201703L);\n\
    \n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\n    x -= (x\
    \ >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) + ((x >> 2) &\
    \ 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n    return x\
    \ * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <cassert>\n\nnamespace luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus\
    \ <= 201703L);\n\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\
    \n    x -= (x >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) +\
    \ ((x >> 2) & 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/utility/bit/popcount.hpp
  requiredBy:
  - src/graph/online-query-jump-on-functional-graph.hpp
  - src/utility/bit/bit-width.hpp
  - src/utility/bit/count-trailing-0s.hpp
  - src/utility/bit/count-leading-0s.hpp
  timestamp: '2023-02-10 17:57:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc258_e/online-algorithm.test.cpp
  - unit-test/graph/online-query-jump-on-functional-graph.test.cpp
  - unit-test/utility/bit/popcount.test.cpp
  - unit-test/utility/bit/count-trailing-0s.test.cpp
  - unit-test/utility/bit/bit-width.test.cpp
  - unit-test/utility/bit/count-leading-0s.test.cpp
documentation_of: src/utility/bit/popcount.hpp
layout: document
title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
---

## popcount
```
usize popcount(u64 n)
```

`n` を二進表記したときの1の数を返す。

### 計算量
- $O(\log \log n)$

### 制約
- C++17 以前であること。

C++20 以降では `std::popcount(T n)` を使用すること。

### appendix
基本方針として、「 $2^i$ bit ごとに区切り、それぞれの区間ごとにいくつ立っている bit があったか」を計算している。
