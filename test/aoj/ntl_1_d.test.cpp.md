---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  - icon: ':question:'
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
  bundledCode: "#line 1 \"test/aoj/ntl_1_d.test.cpp\"\n// verification-helper: PROBLEM\
    \ https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/math/totient.hpp\"\n\n#include <cassert>\n#include <limits>\n\
    \nnamespace luz {\n\n  template < typename T >\n  T totient(T n) {\n    static_assert(std::numeric_limits<\
    \ T >::is_integer,\n                  \"T must be integer\");\n    assert(n >=\
    \ 0);\n    T t = n, p = 2;\n    while (p * p <= n) {\n      if (n % p == 0) {\n\
    \        t -= t / p;\n        while (n % p == 0) {\n          n /= p;\n      \
    \  }\n      }\n      p++;\n    }\n    if (n > 1) {\n      t -= t / n;\n    }\n\
    \    return t;\n  }\n\n} // namespace luz\n#line 5 \"test/aoj/ntl_1_d.test.cpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    u32 n;\n \
    \   std::cin >> n;\n    std::cout << totient(n) << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/math/totient.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    u32 n;\n \
    \   std::cin >> n;\n    std::cout << totient(n) << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/math/totient.hpp
  isVerificationFile: true
  path: test/aoj/ntl_1_d.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ntl_1_d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ntl_1_d.test.cpp
- /verify/test/aoj/ntl_1_d.test.cpp.html
title: test/aoj/ntl_1_d.test.cpp
---
