---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/type-alias.hpp
    title: Type alias
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"unit-test/math/modular-arithmetic/static-modint.test.cpp\"\
    \n// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \n} // namespace luz\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\
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
    \ = StaticPrimeModInt< 1000000007 >;\n\n} // namespace luz\n#line 4 \"unit-test/math/modular-arithmetic/static-modint.test.cpp\"\
    \n\n#line 7 \"unit-test/math/modular-arithmetic/static-modint.test.cpp\"\n\nnamespace\
    \ luz {\n\n  void main_() {\n    using mint = StaticPrimeModInt< 11 >;\n\n   \
    \ mint a = 10;\n    mint b(3);\n\n    // equal\n    assert(a == 10);\n    assert(10\
    \ == a);\n    assert(a == 21);\n    assert(a == -1);\n\n    // positive and negative\n\
    \    assert(+b == 3);\n    assert(-b == 8);\n\n    // add\n    assert(a + b ==\
    \ 2);\n    assert(1 + a == 0);\n    assert(a + 1 == 0);\n\n    // sub\n    assert(a\
    \ - b == 7);\n    assert(b - a == 4);\n    assert(a - 1 == 9);\n    assert(1 -\
    \ a == 2);\n\n    // mul\n    assert(a * b == 8);\n    assert(a * 2 == 9);\n \
    \   assert(2 * a == 9);\n\n    // div\n    assert(a / b == 7);\n    assert(a /\
    \ 2 == 5);\n    assert(2 / a == 9);\n\n    // @=\n    a += b;\n    assert(a ==\
    \ 2 and b == 3);\n    a -= b;\n    assert(a == 10 and b == 3);\n    a *= b;\n\
    \    assert(a == 8 and b == 3);\n    a /= b;\n    assert(a == 10 and b == 3);\n\
    \n    // pow\n    assert(b.pow(3) == 5); // 27 mod 11\n\n    // inverse\n    assert(b.inverse()\
    \ == 4);\n\n    std::cout << \"Hello World\" << std::endl;\n  }\n\n} // namespace\
    \ luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\n\
    \n#include \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#include <cassert>\n\
    #include <iostream>\n\nnamespace luz {\n\n  void main_() {\n    using mint = StaticPrimeModInt<\
    \ 11 >;\n\n    mint a = 10;\n    mint b(3);\n\n    // equal\n    assert(a == 10);\n\
    \    assert(10 == a);\n    assert(a == 21);\n    assert(a == -1);\n\n    // positive\
    \ and negative\n    assert(+b == 3);\n    assert(-b == 8);\n\n    // add\n   \
    \ assert(a + b == 2);\n    assert(1 + a == 0);\n    assert(a + 1 == 0);\n\n  \
    \  // sub\n    assert(a - b == 7);\n    assert(b - a == 4);\n    assert(a - 1\
    \ == 9);\n    assert(1 - a == 2);\n\n    // mul\n    assert(a * b == 8);\n   \
    \ assert(a * 2 == 9);\n    assert(2 * a == 9);\n\n    // div\n    assert(a / b\
    \ == 7);\n    assert(a / 2 == 5);\n    assert(2 / a == 9);\n\n    // @=\n    a\
    \ += b;\n    assert(a == 2 and b == 3);\n    a -= b;\n    assert(a == 10 and b\
    \ == 3);\n    a *= b;\n    assert(a == 8 and b == 3);\n    a /= b;\n    assert(a\
    \ == 10 and b == 3);\n\n    // pow\n    assert(b.pow(3) == 5); // 27 mod 11\n\n\
    \    // inverse\n    assert(b.inverse() == 4);\n\n    std::cout << \"Hello World\"\
    \ << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  dependsOn:
  - src/math/modular-arithmetic/static-modint.hpp
  - src/cpp-template/header/type-alias.hpp
  isVerificationFile: true
  path: unit-test/math/modular-arithmetic/static-modint.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 00:18:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unit-test/math/modular-arithmetic/static-modint.test.cpp
layout: document
redirect_from:
- /verify/unit-test/math/modular-arithmetic/static-modint.test.cpp
- /verify/unit-test/math/modular-arithmetic/static-modint.test.cpp.html
title: unit-test/math/modular-arithmetic/static-modint.test.cpp
---
