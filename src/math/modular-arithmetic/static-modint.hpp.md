---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#line\
    \ 2 \"src/cpp-template/header/type-alias.hpp\"\n\n#include <cstddef>\n#include\
    \ <cstdint>\n\nnamespace luz {\n\n  using isize = std::ptrdiff_t;\n  using usize\
    \ = std::size_t;\n\n  using i32 = std::int32_t;\n  using i64 = std::int64_t;\n\
    \  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n  \n} // namespace\
    \ luz\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#include <cassert>\n\
    \nnamespace luz {\n\n  template< u32 mod >\n  class StaticPrimeModInt {\n    using\
    \ mint = StaticPrimeModInt;\n    u32 v_;\n\n   public:\n     StaticPrimeModInt():\
    \ v_(0) {}\n\n     template< typename T >\n     StaticPrimeModInt(T v) {\n   \
    \    i64 x = (i64)(v % mod);\n       if (x < 0) x += mod;\n       v_ = (u32)x;\n\
    \     }\n\n     mint &operator+=(const mint &rhs) {\n       v_ += rhs.v_;\n  \
    \     if (v_ >= mod) _v -= mod;\n       return *this;\n     }\n     mint &operator-=(const\
    \ mint &rhs) {\n       v_ += mod - rhs.v_;\n       if (v_ >= mod) v_ -= mod;\n\
    \       return *this;\n     }\n     mint &operator*=(const mint &rhs) {\n    \
    \   v_ = (u32)(u64(1) * v_ * rhs.v_ % mod);\n       return *this;\n     }\n  \
    \   mint &operator/=(const mint &rhs) {\n       *this *= rhs.inverse();\n    \
    \   return *this;\n     }\n\n     mint operator+() const { return *this; }\n \
    \    mint operator-() const { return mint() - *this; }\n\n     friend mint operator+(const\
    \ mint &lhs, const mint &rhs) {\n       return mint(lhs) += rhs;\n     }\n   \
    \  friend mint operator-(const mint &lhs, const mint &rhs) {\n       return mint(lhs)\
    \ -= rhs;\n     }\n     friend mint operator*(const mint &lhs, const mint &rhs)\
    \ {\n       return mint(lhs) *= rhs;\n     }\n     friend mint operator/(const\
    \ mint &lhs, const mint &rhs) {\n       return mint(lhs) /= rhs;\n     }\n   \
    \  friend mint operator/(const mint &lhs, const mint &rhs) {\n       return mint(lhs)\
    \ /= rhs;\n     }\n\n     friend mint operator==(const mint &lhs, const mint &rhs)\
    \ {\n       return lhs.v_ == rhs.v_;\n     }\n     friend mint operator!=(const\
    \ mint &lhs, const mint &rhs) {\n       return lhs.v_ != rhs.v_;\n     }\n\n \
    \    mint pow(i64 n) const {\n       assert(0 <= n);\n       mint x = *this, r\
    \ = 1;\n       while (n) {\n         if (n & 1) r *= x;\n         x *= x;\n  \
    \       n >>= 1;\n       }\n       return r;\n     }\n\n     mint inverse() const\
    \ {\n       assert(v_ != 0);\n       return pow(mod - 2);\n     }\n\n  };\n\n\
    \  using modint998244353  = StaticPrimeModInt< 998244353 >;\n  using modint1000000007\
    \ = StaticPrimeModInt< 1000000007 >;\n\n} // namespace luz\n"
  code: "#pragma once\n\n#include \"src/cpp-template/header/type-alias.hpp\"\n\n#include\
    \ <cassert>\n\nnamespace luz {\n\n  template< u32 mod >\n  class StaticPrimeModInt\
    \ {\n    using mint = StaticPrimeModInt;\n    u32 v_;\n\n   public:\n     StaticPrimeModInt():\
    \ v_(0) {}\n\n     template< typename T >\n     StaticPrimeModInt(T v) {\n   \
    \    i64 x = (i64)(v % mod);\n       if (x < 0) x += mod;\n       v_ = (u32)x;\n\
    \     }\n\n     mint &operator+=(const mint &rhs) {\n       v_ += rhs.v_;\n  \
    \     if (v_ >= mod) _v -= mod;\n       return *this;\n     }\n     mint &operator-=(const\
    \ mint &rhs) {\n       v_ += mod - rhs.v_;\n       if (v_ >= mod) v_ -= mod;\n\
    \       return *this;\n     }\n     mint &operator*=(const mint &rhs) {\n    \
    \   v_ = (u32)(u64(1) * v_ * rhs.v_ % mod);\n       return *this;\n     }\n  \
    \   mint &operator/=(const mint &rhs) {\n       *this *= rhs.inverse();\n    \
    \   return *this;\n     }\n\n     mint operator+() const { return *this; }\n \
    \    mint operator-() const { return mint() - *this; }\n\n     friend mint operator+(const\
    \ mint &lhs, const mint &rhs) {\n       return mint(lhs) += rhs;\n     }\n   \
    \  friend mint operator-(const mint &lhs, const mint &rhs) {\n       return mint(lhs)\
    \ -= rhs;\n     }\n     friend mint operator*(const mint &lhs, const mint &rhs)\
    \ {\n       return mint(lhs) *= rhs;\n     }\n     friend mint operator/(const\
    \ mint &lhs, const mint &rhs) {\n       return mint(lhs) /= rhs;\n     }\n   \
    \  friend mint operator/(const mint &lhs, const mint &rhs) {\n       return mint(lhs)\
    \ /= rhs;\n     }\n\n     friend mint operator==(const mint &lhs, const mint &rhs)\
    \ {\n       return lhs.v_ == rhs.v_;\n     }\n     friend mint operator!=(const\
    \ mint &lhs, const mint &rhs) {\n       return lhs.v_ != rhs.v_;\n     }\n\n \
    \    mint pow(i64 n) const {\n       assert(0 <= n);\n       mint x = *this, r\
    \ = 1;\n       while (n) {\n         if (n & 1) r *= x;\n         x *= x;\n  \
    \       n >>= 1;\n       }\n       return r;\n     }\n\n     mint inverse() const\
    \ {\n       assert(v_ != 0);\n       return pow(mod - 2);\n     }\n\n  };\n\n\
    \  using modint998244353  = StaticPrimeModInt< 998244353 >;\n  using modint1000000007\
    \ = StaticPrimeModInt< 1000000007 >;\n\n} // namespace luz\n"
  dependsOn:
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: false
  path: src/math/modular-arithmetic/static-modint.hpp
  requiredBy: []
  timestamp: '2022-07-21 11:48:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/modular-arithmetic/static-modint.hpp
layout: document
redirect_from:
- /library/src/math/modular-arithmetic/static-modint.hpp
- /library/src/math/modular-arithmetic/static-modint.hpp.html
title: src/math/modular-arithmetic/static-modint.hpp
---
