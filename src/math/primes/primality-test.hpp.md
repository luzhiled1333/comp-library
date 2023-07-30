---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/primality_test.test.cpp
    title: test/library-checker/primality_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/primes/primality-test.hpp\"\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 4 \"src/math/primes/primality-test.hpp\"\n\n#include <initializer_list>\n\
    \nnamespace luz::internal_primality_test {\n\n  template < typename T1, typename\
    \ T2 >\n  T1 mod_pow(T1 b, T1 e, T1 mod) {\n    if (mod == 1) return 0;\n\n  \
    \  T1 ans{1};\n    while (e) {\n      if (e & 1) {\n        ans = T2(ans) * b\
    \ % mod;\n      }\n\n      b = T2(b) * b % mod;\n      e >>= 1;\n    }\n\n   \
    \ return ans;\n  }\n\n  template < typename T1, typename T2 >\n  bool is_prime(T1\
    \ n, std::initializer_list< T1 > ws) {\n    if (n == 2) return true;\n    if (n\
    \ == 1 or n % 2 == 0) return false;\n\n    T1 k = (n - 1) & -(n - 1);\n    T1\
    \ d = (n - 1) / k;\n\n    for (T1 a: ws) {\n      if (n <= a) break;\n\n     \
    \ T1 t = d;\n      T1 y = mod_pow< T1, T2 >(a, t, n);\n      while (t != n - 1\
    \ and y != 1 and y != n - 1) {\n        y = T2(y) * y % n;\n        t = T2(t)\
    \ * 2 % n;\n      }\n\n      if (y != n - 1 and t % 2 == 0) {\n        return\
    \ false;\n      }\n    }\n\n    return true;\n  }\n\n  bool is_prime_u32(u32 n)\
    \ {\n    return is_prime< u32, u64 >(n, {2, 7, 61});\n  }\n\n  bool is_prime_u64(u64\
    \ n) {\n    return is_prime< u64, u128 >(\n        n, {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022});\n  }\n\n} // namespace luz::internal_primality_test\n\
    \nnamespace luz {\n\n  bool is_prime(u64 n) {\n    if (n == 2) return true;\n\
    \    if (n == 1 or n % 2 == 0) return false;\n\n    if (n < u64(1) << 32) {\n\
    \      return internal_primality_test::is_prime_u32(n);\n    } else {\n      return\
    \ internal_primality_test::is_prime_u64(n);\n    }\n  }\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n\n#include\
    \ <initializer_list>\n\nnamespace luz::internal_primality_test {\n\n  template\
    \ < typename T1, typename T2 >\n  T1 mod_pow(T1 b, T1 e, T1 mod) {\n    if (mod\
    \ == 1) return 0;\n\n    T1 ans{1};\n    while (e) {\n      if (e & 1) {\n   \
    \     ans = T2(ans) * b % mod;\n      }\n\n      b = T2(b) * b % mod;\n      e\
    \ >>= 1;\n    }\n\n    return ans;\n  }\n\n  template < typename T1, typename\
    \ T2 >\n  bool is_prime(T1 n, std::initializer_list< T1 > ws) {\n    if (n ==\
    \ 2) return true;\n    if (n == 1 or n % 2 == 0) return false;\n\n    T1 k = (n\
    \ - 1) & -(n - 1);\n    T1 d = (n - 1) / k;\n\n    for (T1 a: ws) {\n      if\
    \ (n <= a) break;\n\n      T1 t = d;\n      T1 y = mod_pow< T1, T2 >(a, t, n);\n\
    \      while (t != n - 1 and y != 1 and y != n - 1) {\n        y = T2(y) * y %\
    \ n;\n        t = T2(t) * 2 % n;\n      }\n\n      if (y != n - 1 and t % 2 ==\
    \ 0) {\n        return false;\n      }\n    }\n\n    return true;\n  }\n\n  bool\
    \ is_prime_u32(u32 n) {\n    return is_prime< u32, u64 >(n, {2, 7, 61});\n  }\n\
    \n  bool is_prime_u64(u64 n) {\n    return is_prime< u64, u128 >(\n        n,\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n  }\n\n} // namespace\
    \ luz::internal_primality_test\n\nnamespace luz {\n\n  bool is_prime(u64 n) {\n\
    \    if (n == 2) return true;\n    if (n == 1 or n % 2 == 0) return false;\n\n\
    \    if (n < u64(1) << 32) {\n      return internal_primality_test::is_prime_u32(n);\n\
    \    } else {\n      return internal_primality_test::is_prime_u64(n);\n    }\n\
    \  }\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: false
  path: src/math/primes/primality-test.hpp
  requiredBy: []
  timestamp: '2023-07-30 18:05:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/primality_test.test.cpp
documentation_of: src/math/primes/primality-test.hpp
layout: document
title: "\u9AD8\u901F\u7D20\u6570\u5224\u5B9A"
---

## is_prime
```
bool is_prime(u64 n)
```

$n$ が素数であるかどうかを判定する。

### 計算量
- $O((\log n)^{2})$

### note
witnesses は以下を参考にした。

- [Deterministic variants of the Miller-Rabin primality test](http://miller-rabin.appspot.com/)
