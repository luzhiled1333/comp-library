---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/bit-width.hpp
    title: "\u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
      \u6700\u5C0F\u306Ebit\u5E45 (bit_width)"
  - icon: ':heavy_check_mark:'
    path: src/utility/bit/popcount.hpp
    title: "\u7ACB\u3063\u3066\u3044\u308B bit \u306E\u6570 (population count, popcount)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/utility/bit/bit-width.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/utility/bit/bit-width.hpp\"\
    \n\n#line 2 \"src/utility/bit/popcount.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/utility/bit/popcount.hpp\"\n\n#include <cassert>\n\
    \nnamespace luz {\n\n  usize popcount(u64 x) {\n    assert(__cplusplus <= 201703L);\n\
    \n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n#endif\n\n    x -= (x\
    \ >> 1) & 0x5555555555555555;\n    x = (x & 0x3333333333333333) + ((x >> 2) &\
    \ 0x3333333333333333);\n    x += (x >> 4) & 0x0f0f0f0f0f0f0f0f;\n    return x\
    \ * 0x0101010101010101 >> 56 & 0x7f;\n  }\n\n} // namespace luz\n#line 4 \"src/utility/bit/bit-width.hpp\"\
    \n\n#line 6 \"src/utility/bit/bit-width.hpp\"\n\nnamespace luz {\n\n  usize bit_width(u64\
    \ x) {\n    assert(__cplusplus <= 201703L);\n\n    if (x == 0) {\n      return\
    \ 0;\n    }\n\n#ifdef __GNUC__\n    return 64 - __builtin_clzll(x);\n#endif\n\n\
    \    x |= x >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >> 8;\n    x\
    \ |= x >> 16;\n    x |= x >> 32;\n    return popcount(x);\n  }\n\n} // namespace\
    \ luz\n#line 4 \"unit-test/utility/bit/bit-width.test.cpp\"\n\n#line 2 \"src/cpp-template/header/rep.hpp\"\
    \n\n#line 4 \"src/cpp-template/header/rep.hpp\"\n\n#include <algorithm>\n\nnamespace\
    \ luz {\n\n  struct rep {\n    struct itr {\n      usize i;\n      constexpr itr(const\
    \ usize i) noexcept: i(i) {}\n      void operator++() noexcept {\n        ++i;\n\
    \      }\n      constexpr usize operator*() const noexcept {\n        return i;\n\
    \      }\n      constexpr bool operator!=(const itr x) const noexcept {\n    \
    \    return i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rep(const\
    \ usize f, const usize l) noexcept\n        : f(std::min(f, l)),\n          l(l)\
    \ {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n  \
    \  constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n  struct\
    \ rrep {\n    struct itr {\n      usize i;\n      constexpr itr(const usize i)\
    \ noexcept: i(i) {}\n      void operator++() noexcept {\n        --i;\n      }\n\
    \      constexpr usize operator*() const noexcept {\n        return i;\n     \
    \ }\n      constexpr bool operator!=(const itr x) const noexcept {\n        return\
    \ i != x.i;\n      }\n    };\n    const itr f, l;\n    constexpr rrep(const usize\
    \ f, const usize l) noexcept\n        : f(l - 1),\n          l(std::min(f, l)\
    \ - 1) {}\n    constexpr auto begin() const noexcept {\n      return f;\n    }\n\
    \    constexpr auto end() const noexcept {\n      return l;\n    }\n  };\n\n}\
    \ // namespace luz\n#line 7 \"unit-test/utility/bit/bit-width.test.cpp\"\n\n#line\
    \ 9 \"unit-test/utility/bit/bit-width.test.cpp\"\n#include <iostream>\n\nnamespace\
    \ luz {\n\n  usize naive_bit_width(u64 x) {\n    for (usize k: rrep(0, 64)) {\n\
    \      if (x & (u64(1) << k)) {\n        return k + 1;\n      }\n    }\n\n   \
    \ return 0;\n  }\n\n  void main_() {\n    for (u64 x: rep(0, 1 << 20)) {\n   \
    \   assert(bit_width(x) == naive_bit_width(x));\n    }\n\n    u64 large = u64(1)\
    \ << 63;\n    assert(bit_width(large) == naive_bit_width(large));\n\n    std::cout\
    \ << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n\
    \  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/utility/bit/bit-width.hpp\"\n\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n\nnamespace luz {\n\n  usize naive_bit_width(u64 x) {\n \
    \   for (usize k: rrep(0, 64)) {\n      if (x & (u64(1) << k)) {\n        return\
    \ k + 1;\n      }\n    }\n\n    return 0;\n  }\n\n  void main_() {\n    for (u64\
    \ x: rep(0, 1 << 20)) {\n      assert(bit_width(x) == naive_bit_width(x));\n \
    \   }\n\n    u64 large = u64(1) << 63;\n    assert(bit_width(large) == naive_bit_width(large));\n\
    \n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\n\
    int main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/utility/bit/bit-width.hpp
  - src/utility/bit/popcount.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: true
  path: unit-test/utility/bit/bit-width.test.cpp
  requiredBy: []
  timestamp: '2023-02-10 17:57:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/utility/bit/bit-width.test.cpp
layout: document
redirect_from:
- /verify/unit-test/utility/bit/bit-width.test.cpp
- /verify/unit-test/utility/bit/bit-width.test.cpp.html
title: unit-test/utility/bit/bit-width.test.cpp
---
