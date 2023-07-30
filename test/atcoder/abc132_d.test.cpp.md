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
    path: src/math/modular-arithmetic/modular-combinatorics.hpp
    title: "mod \u7D44\u5408\u305B (mod combinatorics)"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc132/tasks/abc132_d
    links:
    - https://atcoder.jp/contests/abc132/tasks/abc132_d
  bundledCode: "#line 1 \"test/atcoder/abc132_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc132/tasks/abc132_d\n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\
    \n\n#include <cstdint>\n\nnamespace luz {\n\n  using i32  = std::int32_t;\n  using\
    \ i64  = std::int64_t;\n  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n\
    \  using u64  = std::uint64_t;\n  using u128 = __uint128_t;\n\n} // namespace\
    \ luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 2 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\n\n#line 5 \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\
    \n\n#include <vector>\n\nnamespace luz {\n\n  template < typename mint >\n  class\
    \ Combinatorics {\n    static usize bound;\n    static std::vector< mint > fact,\
    \ finv, inv;\n\n    static void expand(usize n) {\n      n += 1;\n      if (fact.size()\
    \ >= n) return;\n\n      if (bound == 0) bound = 1;\n\n      fact.resize(n, mint(1));\n\
    \      finv.resize(n, mint(1));\n      inv.resize(n, mint(1));\n\n      for (usize\
    \ i: rep(bound, n)) {\n        fact[i] = fact[i - 1] * i;\n      }\n\n      finv.back()\
    \ = mint(1) / fact.back();\n      for (usize i: rrep(bound, n)) {\n        finv[i\
    \ - 1] = finv[i] * i;\n      }\n\n      for (usize i: rep(bound, n)) {\n     \
    \   inv[i] = finv[i] * fact[i - 1];\n      }\n\n      bound = n;\n    }\n\n  \
    \ public:\n    explicit Combinatorics(usize n = 0) {\n      expand(n);\n    }\n\
    \n    static mint factorial(usize n) {\n      expand(n);\n      return fact[n];\n\
    \    }\n\n    static mint factorial_inverse(usize n) {\n      expand(n);\n   \
    \   return finv[n];\n    }\n\n    static mint inverse(usize n) {\n      expand(n);\n\
    \      return inv[n];\n    }\n\n    static mint permutation(isize n, isize r)\
    \ {\n      if (r < 0 or n < r) return 0;\n\n      expand(n);\n      return fact[n]\
    \ * finv[n - r];\n    }\n\n    static mint combination(isize n, isize r) {\n \
    \     if (r < 0 or n < r) return 0;\n\n      expand(n);\n      return fact[n]\
    \ * finv[r] * finv[n - r];\n    }\n\n    static mint combination_with_repetitions(isize\
    \ n, isize r) {\n      if (n < 0 or r < 0) return 0;\n      return (r ? combination(n\
    \ + r - 1, r) : 1);\n    }\n\n    static mint P(isize n, isize r) {\n      return\
    \ permutation(n, r);\n    }\n\n    static mint C(isize n, isize r) {\n      return\
    \ combination(n, r);\n    }\n\n    static mint H(isize n, isize r) {\n      return\
    \ combination_with_repetitions(n, r);\n    }\n  };\n\n  template < typename mint\
    \ >\n  usize Combinatorics< mint >::bound = 0;\n\n  template < typename mint >\n\
    \  std::vector< mint > Combinatorics< mint >::fact =\n      std::vector< mint\
    \ >();\n\n  template < typename mint >\n  std::vector< mint > Combinatorics< mint\
    \ >::finv =\n      std::vector< mint >();\n\n  template < typename mint >\n  std::vector<\
    \ mint > Combinatorics< mint >::inv =\n      std::vector< mint >();\n\n} // namespace\
    \ luz\n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#line 4 \"\
    src/math/modular-arithmetic/static-modint.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n\nnamespace luz {\n\n  template < u32 mod >\n  class StaticPrimeModInt\
    \ {\n    using modint = StaticPrimeModInt;\n\n    u32 v;\n\n   public:\n    StaticPrimeModInt():\
    \ v(0) {}\n\n    template < typename T >\n    StaticPrimeModInt(T v_) {\n    \
    \  i64 x = (i64)(v_ % (i64)mod);\n      if (x < 0) x += mod;\n      v = (u32)x;\n\
    \    }\n\n    u32 val() const {\n      return v;\n    }\n\n    modint &operator+=(const\
    \ modint &rhs) {\n      v += rhs.v;\n      if (v >= mod) v -= mod;\n      return\
    \ *this;\n    }\n\n    modint &operator-=(const modint &rhs) {\n      v += mod\
    \ - rhs.v;\n      if (v >= mod) v -= mod;\n      return *this;\n    }\n\n    modint\
    \ &operator*=(const modint &rhs) {\n      v = (u32)(u64(1) * v * rhs.v % mod);\n\
    \      return *this;\n    }\n\n    modint &operator/=(const modint &rhs) {\n \
    \     *this *= rhs.inverse();\n      return *this;\n    }\n\n    modint operator+()\
    \ const {\n      return *this;\n    }\n\n    modint operator-() const {\n    \
    \  return modint() - *this;\n    }\n\n    friend modint operator+(const modint\
    \ &lhs, const modint &rhs) {\n      return modint(lhs) += rhs;\n    }\n\n    friend\
    \ modint operator-(const modint &lhs, const modint &rhs) {\n      return modint(lhs)\
    \ -= rhs;\n    }\n\n    friend modint operator*(const modint &lhs, const modint\
    \ &rhs) {\n      return modint(lhs) *= rhs;\n    }\n\n    friend modint operator/(const\
    \ modint &lhs, const modint &rhs) {\n      return modint(lhs) /= rhs;\n    }\n\
    \n    friend bool operator==(const modint &lhs, const modint &rhs) {\n      return\
    \ lhs.v == rhs.v;\n    }\n\n    friend bool operator!=(const modint &lhs, const\
    \ modint &rhs) {\n      return lhs.v != rhs.v;\n    }\n\n    modint pow(i64 n)\
    \ const {\n      assert(0 <= n);\n      modint x = *this, r = 1;\n      while\
    \ (n) {\n        if (n & 1) r *= x;\n        x *= x;\n        n >>= 1;\n     \
    \ }\n      return r;\n    }\n\n    modint inverse() const {\n      assert(v !=\
    \ 0);\n      return pow(mod - 2);\n    }\n\n    static constexpr u32 get_mod()\
    \ {\n      return mod;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os,\n                                    const modint &m) {\n      os << m.val();\n\
    \      return os;\n    }\n  };\n\n  using modint998244353  = StaticPrimeModInt<\
    \ 998244353 >;\n  using modint1000000007 = StaticPrimeModInt< 1000000007 >;\n\n\
    } // namespace luz\n#line 7 \"test/atcoder/abc132_d.test.cpp\"\n\n#line 9 \"test/atcoder/abc132_d.test.cpp\"\
    \n\nnamespace luz {\n\n  void main_() {\n    i32 n, k;\n    std::cin >> n >> k;\n\
    \n    using mint = modint1000000007;\n    Combinatorics< mint > cb;\n\n    for\
    \ (i32 i: rep(1, k + 1)) {\n      i32 t = n - k - (i - 1);\n      std::cout <<\
    \ (cb.combination_with_repetitions(i + 1, t) *\n                    cb.combination_with_repetitions(i,\
    \ k - i))\n                       .val()\n                << std::endl;\n    }\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc132/tasks/abc132_d\n\
    \n#include \"src/cpp-template/header/int-alias.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/math/modular-arithmetic/modular-combinatorics.hpp\"\n#include\
    \ \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#include <iostream>\n\n\
    namespace luz {\n\n  void main_() {\n    i32 n, k;\n    std::cin >> n >> k;\n\n\
    \    using mint = modint1000000007;\n    Combinatorics< mint > cb;\n\n    for\
    \ (i32 i: rep(1, k + 1)) {\n      i32 t = n - k - (i - 1);\n      std::cout <<\
    \ (cb.combination_with_repetitions(i + 1, t) *\n                    cb.combination_with_repetitions(i,\
    \ k - i))\n                       .val()\n                << std::endl;\n    }\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/math/modular-arithmetic/modular-combinatorics.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  isVerificationFile: true
  path: test/atcoder/abc132_d.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc132_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc132_d.test.cpp
- /verify/test/atcoder/abc132_d.test.cpp.html
title: test/atcoder/abc132_d.test.cpp
---
