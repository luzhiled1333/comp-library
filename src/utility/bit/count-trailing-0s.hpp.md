---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA solver (Range Add Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-maximum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Add Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Add Range Minimum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp
    title: "\u533A\u9593\u52A0\u7B97 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Add Range Sum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-chmax-query-solver.hpp
    title: "\u533A\u9593 chmax \u30AF\u30A8\u30EA solver (Range ChangeMax Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-chmin-query-solver.hpp
    title: "\u533A\u9593 chmin \u30AF\u30A8\u30EA solver (Range ChangeMin Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0\u30AF\u30A8\u30EA solver (Range Update Query\
      \ Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-maximum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u6700\u5927\u30AF\u30A8\u30EA\
      \ solver (Range Update Range Maximum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\
      \ solver (Range Update Range Minimum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u533A\u9593\u548C\u30AF\u30A8\u30EA solver\
      \ (Range Update Range Sum Query Solver)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp
    title: "\u533A\u9593\u66F4\u65B0 + \u4E00\u70B9\u53D6\u5F97 \u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (Dual Segment Tree)"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp
    title: "\u533A\u9593\u66F4\u65B0+\u533A\u9593\u53D6\u5F97 \u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728 (Lazy Segment Tree)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_d.test.cpp
    title: test/aoj/dsl_2_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_e.test.cpp
    title: test/aoj/dsl_2_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_f/range-maximum.test.cpp
    title: test/aoj/dsl_2_f/range-maximum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_f/range-minimum.test.cpp
    title: test/aoj/dsl_2_f/range-minimum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_g.test.cpp
    title: test/aoj/dsl_2_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_h/range-maximum.test.cpp
    title: test/aoj/dsl_2_h/range-maximum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_h/range-minimum.test.cpp
    title: test/aoj/dsl_2_h/range-minimum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl_2_i.test.cpp
    title: test/aoj/dsl_2_i.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_f/range-chmax.test.cpp
    title: test/atcoder/abc179_f/range-chmax.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_f/range-chmin.test.cpp
    title: test/atcoder/abc179_f/range-chmin.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/utility/bit/count-trailing-0s.test.cpp
    title: unit-test/utility/bit/count-trailing-0s.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/bit/count-trailing-0s.hpp\"\n\n#line 2 \"src/utility/bit/popcount.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/utility/bit/popcount.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus <= 201703L);\n\n\
    #ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\n    x -= (x >>\
    \ 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);\n\
    \    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n    return x * 0x0101010101010101 >>\
    \ 56 & 0x7f;\n  }\n\n} // namespace luz\n#line 4 \"src/utility/bit/count-trailing-0s.hpp\"\
    \n\n#line 6 \"src/utility/bit/count-trailing-0s.hpp\"\n\nnamespace luz {\n\n \
    \ usize countr_zero(u64 x) {\n    assert(__cplusplus <= 201703L);\n\n    if (x\
    \ == 0) {\n      return 64;\n    }\n\n#ifdef __GNUC__\n    return __builtin_ctzll(x);\n\
    #endif\n\n    return popcount((x & -x) - 1);\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/utility/bit/popcount.hpp\"\n\n#include <cassert>\n\
    \nnamespace luz {\n\n  usize countr_zero(u64 x) {\n    assert(__cplusplus <= 201703L);\n\
    \n    if (x == 0) {\n      return 64;\n    }\n\n#ifdef __GNUC__\n    return __builtin_ctzll(x);\n\
    #endif\n\n    return popcount((x & -x) - 1);\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/utility/bit/popcount.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/utility/bit/count-trailing-0s.hpp
  requiredBy:
  - src/data-structure/segment-tree/range-mapping-point-fold-segment-tree.hpp
  - src/data-structure/segment-tree/presets/range-update-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-range-maximum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-range-sum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-chmax-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-range-maximum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-range-sum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-update-range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-chmin-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-query-solver.hpp
  - src/data-structure/segment-tree/presets/range-add-range-minimum-query-solver.hpp
  - src/data-structure/segment-tree/range-mapping-range-fold-segment-tree.hpp
  timestamp: '2023-02-10 17:57:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unit-test/utility/bit/count-trailing-0s.test.cpp
  - test/aoj/dsl_2_e.test.cpp
  - test/aoj/dsl_2_i.test.cpp
  - test/aoj/dsl_2_g.test.cpp
  - test/aoj/dsl_2_f/range-minimum.test.cpp
  - test/aoj/dsl_2_f/range-maximum.test.cpp
  - test/aoj/dsl_2_h/range-minimum.test.cpp
  - test/aoj/dsl_2_h/range-maximum.test.cpp
  - test/aoj/dsl_2_d.test.cpp
  - test/atcoder/abc179_f/range-chmin.test.cpp
  - test/atcoder/abc179_f/range-chmax.test.cpp
documentation_of: src/utility/bit/count-trailing-0s.hpp
layout: document
title: "\u6700\u4E0B\u4F4Dbit\u304B\u3089\u9023\u7D9A\u3059\u308B 0 \u306E\u6570 (counting\
  \ trailing 0s, countr_zero)"
---

## countr_zero
```
usize countr_zero(u64 n)
```

`n` を二進表記したとき、右からいくつ連続した $0$ が続くかを返す。

$n = 0$ のときは $64$ が返る。

### 計算量
- $O(\log \log n)$

### 制約
- C++17 以前であること。

C++20 以降では `std::countr_zero(T n)` を使用すること。
