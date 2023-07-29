---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':question:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: unit-test/utility/bit/count-leading-0s.test.cpp
    title: unit-test/utility/bit/count-leading-0s.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/bit/count-leading-0s.hpp\"\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\n\n#include <cstddef>\n\
    \nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize = std::size_t;\n\
    \n} // namespace luz\n#line 2 \"src/utility/bit/popcount.hpp\"\n\n#line 5 \"src/utility/bit/popcount.hpp\"\
    \n\n#include <cassert>\n\nnamespace luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus\
    \ <= 201703L);\n\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\
    \n    x -= (x >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) +\
    \ ((x >> 2) & 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n\
    #line 6 \"src/utility/bit/count-leading-0s.hpp\"\n\n#line 8 \"src/utility/bit/count-leading-0s.hpp\"\
    \n\nnamespace luz {\n\n  usize countl_zero(u64 x) {\n    assert(__cplusplus <=\
    \ 201703L);\n\n    if (x == 0) {\n      return 64;\n    }\n\n#ifdef __GNUC__\n\
    \    return __builtin_clzll(x);\n#endif\n\n    x |= x >> 1;\n    x |= x >> 2;\n\
    \    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n  \
    \  return 64 - popcount(x);\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n#include\
    \ \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/utility/bit/popcount.hpp\"\
    \n\n#include <cassert>\n\nnamespace luz {\n\n  usize countl_zero(u64 x) {\n  \
    \  assert(__cplusplus <= 201703L);\n\n    if (x == 0) {\n      return 64;\n  \
    \  }\n\n#ifdef __GNUC__\n    return __builtin_clzll(x);\n#endif\n\n    x |= x\
    \ >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n\
    \    x |= x >> 32;\n    return 64 - popcount(x);\n  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/utility/bit/popcount.hpp
  isVerificationFile: false
  path: src/utility/bit/count-leading-0s.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - unit-test/utility/bit/count-leading-0s.test.cpp
documentation_of: src/utility/bit/count-leading-0s.hpp
layout: document
title: "\u6700\u4E0A\u4F4Dbit\u304B\u3089\u9023\u7D9A\u3059\u308B 0 \u306E\u6570 (counting\
  \ leading 0s, countl_zero)"
---

## countl_zero
```
usize countl_zero(u64 n)
```

`n` を二進表記したとき、左からいくつ連続した $0$ が続くかを返す。

$n = 0$ のときは $64$ が返る。

### 計算量
- $O(\log \log n)$

### 制約
- C++17 以前であること。

C++20 以降では `std::countl_zero(T n)` を使用すること。

### appendix
立っている bit のうち最も大きい桁よりも小さい bit をすべて 1 で埋め、`popcount` でその数を取得している。
