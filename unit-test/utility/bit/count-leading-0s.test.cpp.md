---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':question:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':question:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':x:'
    path: src/utility/bit/count-leading-0s.hpp
    title: "\u6700\u4E0A\u4F4Dbit\u304B\u3089\u9023\u7D9A\u3059\u308B 0 \u306E\u6570\
      \ (counting leading 0s, countl_zero)"
  - icon: ':question:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/utility/bit/count-leading-0s.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/utility/bit/count-leading-0s.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 2 \"src/utility/bit/popcount.hpp\"\
    \n\n#line 5 \"src/utility/bit/popcount.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus <= 201703L);\n\n\
    #ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\n    x -= (x >>\
    \ 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);\n\
    \    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n    return x * 0x0101010101010101 >>\
    \ 56 & 0x7f;\n  }\n\n} // namespace luz\n#line 6 \"src/utility/bit/count-leading-0s.hpp\"\
    \n\n#line 8 \"src/utility/bit/count-leading-0s.hpp\"\n\nnamespace luz {\n\n  usize\
    \ countl_zero(u64 x) {\n    assert(__cplusplus <= 201703L);\n\n    if (x == 0)\
    \ {\n      return 64;\n    }\n\n#ifdef __GNUC__\n    return __builtin_clzll(x);\n\
    #endif\n\n    x |= x >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >>\
    \ 8;\n    x |= x >> 16;\n    x |= x >> 32;\n    return 64 - popcount(x);\n  }\n\
    \n} // namespace luz\n#line 4 \"unit-test/utility/bit/count-leading-0s.test.cpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        ++i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rep(const usize f, const usize l)\
    \ noexcept\n        : f(std::min(f, l)),\n          l(l) {}\n    constexpr auto\
    \ begin() const noexcept {\n      return f;\n    }\n    constexpr auto end() const\
    \ noexcept {\n      return l;\n    }\n  };\n\n  struct rrep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept: i(i) {}\n  \
    \    void operator++() noexcept {\n        --i;\n      }\n      constexpr usize\
    \ operator*() const noexcept {\n        return i;\n      }\n      constexpr bool\
    \ operator!=(const itr x) const noexcept {\n        return i != x.i;\n      }\n\
    \    };\n    const itr f, l;\n    constexpr rrep(const usize f, const usize l)\
    \ noexcept\n        : f(l - 1),\n          l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept {\n      return f;\n    }\n    constexpr auto end()\
    \ const noexcept {\n      return l;\n    }\n  };\n\n} // namespace luz\n#line\
    \ 8 \"unit-test/utility/bit/count-leading-0s.test.cpp\"\n\n#line 10 \"unit-test/utility/bit/count-leading-0s.test.cpp\"\
    \n#include <iostream>\n\nnamespace luz {\n\n  usize naive_countl_zero(u64 x) {\n\
    \    for (usize k: rrep(0, 64)) {\n      if (x & (u64(1) << k)) {\n        return\
    \ 63 - k;\n      }\n    }\n\n    return 64;\n  }\n\n  void main_() {\n    for\
    \ (u64 x: rep(0, 1 << 20)) {\n      assert(countl_zero(x) == naive_countl_zero(x));\n\
    \    }\n\n    u64 large = u64(1) << 63;\n    assert(countl_zero(large) == naive_countl_zero(large));\n\
    \n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/utility/bit/count-leading-0s.hpp\"\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n#include \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n\nnamespace luz {\n\n  usize naive_countl_zero(u64\
    \ x) {\n    for (usize k: rrep(0, 64)) {\n      if (x & (u64(1) << k)) {\n   \
    \     return 63 - k;\n      }\n    }\n\n    return 64;\n  }\n\n  void main_()\
    \ {\n    for (u64 x: rep(0, 1 << 20)) {\n      assert(countl_zero(x) == naive_countl_zero(x));\n\
    \    }\n\n    u64 large = u64(1) << 63;\n    assert(countl_zero(large) == naive_countl_zero(large));\n\
    \n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/utility/bit/count-leading-0s.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/utility/bit/popcount.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: true
  path: unit-test/utility/bit/count-leading-0s.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: unit-test/utility/bit/count-leading-0s.test.cpp
layout: document
redirect_from:
- /verify/unit-test/utility/bit/count-leading-0s.test.cpp
- /verify/unit-test/utility/bit/count-leading-0s.test.cpp.html
title: unit-test/utility/bit/count-leading-0s.test.cpp
---
