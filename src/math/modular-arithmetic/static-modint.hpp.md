---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/int-alias.hpp
    title: int alias
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc132_d.test.cpp
    title: test/atcoder/abc132_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc212_h.test.cpp
    title: test/atcoder/abc212_h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc307_h/main.test.cpp
    title: test/atcoder/abc307_h/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc117_c.test.cpp
    title: test/atcoder/arc117_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_and_convolution.test.cpp
    title: test/library-checker/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/bitwise_xor_convolution.test.cpp
    title: test/library-checker/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/modint_convolution.test.cpp
    title: test/library-checker/modint_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/data-structure/fenwick-tree.test.cpp
    title: unit-test/data-structure/fenwick-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: unit-test/math/modular-arithmetic/static-modint.test.cpp
    title: unit-test/math/modular-arithmetic/static-modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\nnamespace\
    \ luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n  using\
    \ i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#include <cassert>\n#include <iostream>\n\nnamespace luz {\n\n  template <\
    \ u32 mod >\n  class StaticPrimeModInt {\n    using modint = StaticPrimeModInt;\n\
    \n    u32 v;\n\n   public:\n    StaticPrimeModInt(): v(0) {}\n\n    template <\
    \ typename T >\n    StaticPrimeModInt(T v_) {\n      i64 x = (i64)(v_ % (i64)mod);\n\
    \      if (x < 0) x += mod;\n      v = (u32)x;\n    }\n\n    u32 val() const {\n\
    \      return v;\n    }\n\n    modint &operator+=(const modint &rhs) {\n     \
    \ v += rhs.v;\n      if (v >= mod) v -= mod;\n      return *this;\n    }\n\n \
    \   modint &operator-=(const modint &rhs) {\n      v += mod - rhs.v;\n      if\
    \ (v >= mod) v -= mod;\n      return *this;\n    }\n\n    modint &operator*=(const\
    \ modint &rhs) {\n      v = (u32)(u64(1) * v * rhs.v % mod);\n      return *this;\n\
    \    }\n\n    modint &operator/=(const modint &rhs) {\n      *this *= rhs.inverse();\n\
    \      return *this;\n    }\n\n    modint operator+() const {\n      return *this;\n\
    \    }\n\n    modint operator-() const {\n      return modint() - *this;\n   \
    \ }\n\n    friend modint operator+(const modint &lhs, const modint &rhs) {\n \
    \     return modint(lhs) += rhs;\n    }\n\n    friend modint operator-(const modint\
    \ &lhs, const modint &rhs) {\n      return modint(lhs) -= rhs;\n    }\n\n    friend\
    \ modint operator*(const modint &lhs, const modint &rhs) {\n      return modint(lhs)\
    \ *= rhs;\n    }\n\n    friend modint operator/(const modint &lhs, const modint\
    \ &rhs) {\n      return modint(lhs) /= rhs;\n    }\n\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\n      return lhs.v == rhs.v;\n    }\n\n \
    \   friend bool operator!=(const modint &lhs, const modint &rhs) {\n      return\
    \ lhs.v != rhs.v;\n    }\n\n    modint pow(i64 n) const {\n      assert(0 <= n);\n\
    \      modint x = *this, r = 1;\n      while (n) {\n        if (n & 1) r *= x;\n\
    \        x *= x;\n        n >>= 1;\n      }\n      return r;\n    }\n\n    modint\
    \ inverse() const {\n      assert(v != 0);\n      return pow(mod - 2);\n    }\n\
    \n    static constexpr u32 get_mod() {\n      return mod;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os,\n                               \
    \     const modint &m) {\n      os << m.val();\n      return os;\n    }\n  };\n\
    \n  using modint998244353  = StaticPrimeModInt< 998244353 >;\n  using modint1000000007\
    \ = StaticPrimeModInt< 1000000007 >;\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/int-alias.hpp\"\n\n#include\
    \ <cassert>\n#include <iostream>\n\nnamespace luz {\n\n  template < u32 mod >\n\
    \  class StaticPrimeModInt {\n    using modint = StaticPrimeModInt;\n\n    u32\
    \ v;\n\n   public:\n    StaticPrimeModInt(): v(0) {}\n\n    template < typename\
    \ T >\n    StaticPrimeModInt(T v_) {\n      i64 x = (i64)(v_ % (i64)mod);\n  \
    \    if (x < 0) x += mod;\n      v = (u32)x;\n    }\n\n    u32 val() const {\n\
    \      return v;\n    }\n\n    modint &operator+=(const modint &rhs) {\n     \
    \ v += rhs.v;\n      if (v >= mod) v -= mod;\n      return *this;\n    }\n\n \
    \   modint &operator-=(const modint &rhs) {\n      v += mod - rhs.v;\n      if\
    \ (v >= mod) v -= mod;\n      return *this;\n    }\n\n    modint &operator*=(const\
    \ modint &rhs) {\n      v = (u32)(u64(1) * v * rhs.v % mod);\n      return *this;\n\
    \    }\n\n    modint &operator/=(const modint &rhs) {\n      *this *= rhs.inverse();\n\
    \      return *this;\n    }\n\n    modint operator+() const {\n      return *this;\n\
    \    }\n\n    modint operator-() const {\n      return modint() - *this;\n   \
    \ }\n\n    friend modint operator+(const modint &lhs, const modint &rhs) {\n \
    \     return modint(lhs) += rhs;\n    }\n\n    friend modint operator-(const modint\
    \ &lhs, const modint &rhs) {\n      return modint(lhs) -= rhs;\n    }\n\n    friend\
    \ modint operator*(const modint &lhs, const modint &rhs) {\n      return modint(lhs)\
    \ *= rhs;\n    }\n\n    friend modint operator/(const modint &lhs, const modint\
    \ &rhs) {\n      return modint(lhs) /= rhs;\n    }\n\n    friend bool operator==(const\
    \ modint &lhs, const modint &rhs) {\n      return lhs.v == rhs.v;\n    }\n\n \
    \   friend bool operator!=(const modint &lhs, const modint &rhs) {\n      return\
    \ lhs.v != rhs.v;\n    }\n\n    modint pow(i64 n) const {\n      assert(0 <= n);\n\
    \      modint x = *this, r = 1;\n      while (n) {\n        if (n & 1) r *= x;\n\
    \        x *= x;\n        n >>= 1;\n      }\n      return r;\n    }\n\n    modint\
    \ inverse() const {\n      assert(v != 0);\n      return pow(mod - 2);\n    }\n\
    \n    static constexpr u32 get_mod() {\n      return mod;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os,\n                               \
    \     const modint &m) {\n      os << m.val();\n      return os;\n    }\n  };\n\
    \n  using modint998244353  = StaticPrimeModInt< 998244353 >;\n  using modint1000000007\
    \ = StaticPrimeModInt< 1000000007 >;\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  isVerificationFile: false
  path: src/math/modular-arithmetic/static-modint.hpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc307_h/main.test.cpp
  - test/atcoder/abc212_h.test.cpp
  - test/atcoder/arc117_c.test.cpp
  - test/atcoder/abc132_d.test.cpp
  - test/library-checker/bitwise_and_convolution.test.cpp
  - test/library-checker/modint_convolution.test.cpp
  - test/library-checker/bitwise_xor_convolution.test.cpp
  - unit-test/math/modular-arithmetic/static-modint.test.cpp
  - unit-test/data-structure/fenwick-tree.test.cpp
documentation_of: src/math/modular-arithmetic/static-modint.hpp
layout: document
redirect_from:
- /library/src/math/modular-arithmetic/static-modint.hpp
- /library/src/math/modular-arithmetic/static-modint.hpp.html
title: src/math/modular-arithmetic/static-modint.hpp
---
