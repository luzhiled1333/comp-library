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
    path: src/math/totient.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\
      \u6570 (\u30AA\u30A4\u30E9\u30FC\u306E $\\phi$ \u95A2\u6570, Euler's totient\
      \ function)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/math/totient.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/math/totient.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n\
    #include <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using\
    \ usize = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/math/totient.hpp\"\n\n#include <cassert>\n#include <limits>\n\
    \nnamespace luz {\n\n  template < typename T >\n  T totient(T n) {\n    static_assert(std::numeric_limits<\
    \ T >::is_integer,\n                  \"T must be integer\");\n    assert(n >=\
    \ 0);\n    T t = n, p = 2;\n    while (p * p <= n) {\n      if (n % p == 0) {\n\
    \        t -= t / p;\n        while (n % p == 0) {\n          n /= p;\n      \
    \  }\n      }\n      p++;\n    }\n    if (n > 1) {\n      t -= t / n;\n    }\n\
    \    return t;\n  }\n\n} // namespace luz\n#line 4 \"unit-test/math/totient.test.cpp\"\
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
    \ 6 \"unit-test/math/totient.test.cpp\"\n\n#line 8 \"unit-test/math/totient.test.cpp\"\
    \n#include <iostream>\n#include <numeric>\n\nnamespace luz {\n\n  u32 naive_totient(u32\
    \ n) {\n    u32 result = 0;\n    for (u32 m: rep(1, n + 1)) {\n      if (std::gcd(n,\
    \ m) == 1) result++;\n    }\n    return result;\n  }\n\n  void main_() {\n\n \
    \   // small\n    for (u32 i: rep(0, 1000)) {\n      assert(totient(i) == naive_totient(i));\n\
    \    }\n\n    // large\n    assert(totient(735134400) == 132710400);\n    assert(totient(1000000007)\
    \ == 1000000006);\n    assert(totient(1000000009) == 1000000008);\n    assert(totient(31415926535)\
    \ == 20847434400);\n\n    std::cout << \"Hello World\" << std::endl;\n  }\n\n\
    } // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/math/totient.hpp\"\n\n#include \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\nnamespace luz\
    \ {\n\n  u32 naive_totient(u32 n) {\n    u32 result = 0;\n    for (u32 m: rep(1,\
    \ n + 1)) {\n      if (std::gcd(n, m) == 1) result++;\n    }\n    return result;\n\
    \  }\n\n  void main_() {\n\n    // small\n    for (u32 i: rep(0, 1000)) {\n  \
    \    assert(totient(i) == naive_totient(i));\n    }\n\n    // large\n    assert(totient(735134400)\
    \ == 132710400);\n    assert(totient(1000000007) == 1000000006);\n    assert(totient(1000000009)\
    \ == 1000000008);\n    assert(totient(31415926535) == 20847434400);\n\n    std::cout\
    \ << \"Hello World\" << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n\
    \  luz::main_();\n}\n"
  dependsOn:
  - src/math/totient.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/cpp-template/header/rep.hpp
  isVerificationFile: true
  path: unit-test/math/totient.test.cpp
  requiredBy: []
  timestamp: '2022-08-31 12:35:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/math/totient.test.cpp
layout: document
redirect_from:
- /verify/unit-test/math/totient.test.cpp
- /verify/unit-test/math/totient.test.cpp.html
title: unit-test/math/totient.test.cpp
---
