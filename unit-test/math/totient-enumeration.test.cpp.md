---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/rep.hpp
    title: "rep \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/size-alias.hpp
    title: size alias
  - icon: ':heavy_check_mark:'
    path: src/math/totient-enumeration.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\u30A7\u30F3\u30C8\u95A2\
      \u6570\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/math/totient-enumeration.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\n#line 2 \"src/math/totient-enumeration.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
    \n\n#include <cstddef>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n\
    \  using usize = std::size_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/rep.hpp\"\
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
    \ 4 \"src/math/totient-enumeration.hpp\"\n\n#include <cassert>\n#include <limits>\n\
    #include <vector>\n\nnamespace luz {\n\n  template < typename T >\n  std::vector<\
    \ T > totient_enumeration(T n) {\n    static_assert(std::numeric_limits< T >::is_integer,\n\
    \                  \"T must be integer\");\n    assert(n >= 0);\n\n    n += 1;\n\
    \    std::vector< T > totients(n);\n    for (T i: rep(0, n)) {\n      totients[i]\
    \ = i;\n    }\n    for (T i: rep(2, n)) {\n      if (totients[i] != i) continue;\n\
    \      for (T j = i; j < n; j += i) {\n        totients[j] = totients[j] / i *\
    \ (i - 1);\n      }\n    }\n    return totients;\n  }\n\n} // namespace luz\n\
    #line 4 \"unit-test/math/totient-enumeration.test.cpp\"\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 7 \"unit-test/math/totient-enumeration.test.cpp\"\n\n#line 9 \"unit-test/math/totient-enumeration.test.cpp\"\
    \n#include <iostream>\n#include <numeric>\n#line 12 \"unit-test/math/totient-enumeration.test.cpp\"\
    \n\nnamespace luz {\n\n  u32 naive_totient(u32 n) {\n    u32 result = 0;\n   \
    \ for (u32 m: rep(1, n + 1)) {\n      if (std::gcd(n, m) == 1) result++;\n   \
    \ }\n    return result;\n  }\n\n  void main_() {\n    std::vector< u32 > totients\
    \ = totient_enumeration((u32)1000);\n\n    for (u32 i: rep(0, 1001)) {\n     \
    \ assert(totients[i] == naive_totient(i));\n    }\n\n    std::cout << \"Hello\
    \ World\" << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/math/totient-enumeration.hpp\"\n\n#include \"src/cpp-template/header/int-alias.hpp\"\
    \n#include \"src/cpp-template/header/rep.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <numeric>\n#include <vector>\n\nnamespace luz {\n\n  u32\
    \ naive_totient(u32 n) {\n    u32 result = 0;\n    for (u32 m: rep(1, n + 1))\
    \ {\n      if (std::gcd(n, m) == 1) result++;\n    }\n    return result;\n  }\n\
    \n  void main_() {\n    std::vector< u32 > totients = totient_enumeration((u32)1000);\n\
    \n    for (u32 i: rep(0, 1001)) {\n      assert(totients[i] == naive_totient(i));\n\
    \    }\n\n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/math/totient-enumeration.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: true
  path: unit-test/math/totient-enumeration.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/math/totient-enumeration.test.cpp
layout: document
redirect_from:
- /verify/unit-test/math/totient-enumeration.test.cpp
- /verify/unit-test/math/totient-enumeration.test.cpp.html
title: unit-test/math/totient-enumeration.test.cpp
---
