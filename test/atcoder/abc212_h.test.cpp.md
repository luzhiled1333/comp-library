---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/cpp-template/header/input.hpp
    title: input
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
    path: src/math/convolution/fast-walsh-hadamard-transform.hpp
    title: "\u9AD8\u901F\u30A6\u30A9\u30EB\u30B7\u30E5-\u30A2\u30C0\u30DE\u30FC\u30EB\
      \u5909\u63DB/\u9006\u5909\u63DB (Fast Walsh Hadamard Transform / Inverse Transform)"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic/static-modint.hpp
    title: src/math/modular-arithmetic/static-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc212/tasks/abc212_h
    links:
    - https://atcoder.jp/contests/abc212/tasks/abc212_h
  bundledCode: "#line 1 \"test/atcoder/abc212_h.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc212/tasks/abc212_h\n\n#line 2 \"src/cpp-template/header/input.hpp\"\
    \n\n#line 2 \"src/cpp-template/header/int-alias.hpp\"\n\n#include <cstdint>\n\n\
    namespace luz {\n\n  using i32  = std::int32_t;\n  using i64  = std::int64_t;\n\
    \  using i128 = __int128_t;\n\n  using u32  = std::uint32_t;\n  using u64  = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n\n} // namespace luz\n#line 4 \"src/cpp-template/header/input.hpp\"\
    \n\n#include <iostream>\n\nnamespace luz {\n\n  template < typename T = i64 >\n\
    \  T input() {\n    T tmp;\n    std::cin >> tmp;\n    return tmp;\n  }\n\n} //\
    \ namespace luz\n#line 2 \"src/cpp-template/header/rep.hpp\"\n\n#line 2 \"src/cpp-template/header/size-alias.hpp\"\
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
    \ 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#line 5 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n\nnamespace luz {\n\n  template < typename\
    \ T, typename F >\n  void fast_walsh_hadamard_transform(std::vector< T > &f, F\
    \ op) {\n    const usize n = f.size();\n    assert((n & (n - 1)) == 0);\n    usize\
    \ i = 1;\n    while (i < n) {\n      usize j = 0;\n      while (j < n) {\n   \
    \     for (usize k: rep(0, i)) {\n          op(f[j + k], f[j + k + i]);\n    \
    \    }\n        j += i << 1;\n      }\n      i <<= 1;\n    }\n  }\n\n} // namespace\
    \ luz\n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#line 4 \"\
    src/math/modular-arithmetic/static-modint.hpp\"\n\n#line 7 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\nnamespace luz {\n\n  template < u32 mod >\n  class StaticPrimeModInt {\n \
    \   using modint = StaticPrimeModInt;\n\n    u32 v;\n\n   public:\n    StaticPrimeModInt():\
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
    } // namespace luz\n#line 8 \"test/atcoder/abc212_h.test.cpp\"\n\n// TODO: replace\
    \ #11\nnamespace luz {\n\n  template < typename T >\n  T sum_of_geometric_sequence(const\
    \ T& a_0, const T& r,\n                              const usize& n) {\n    if\
    \ (r == T(1)) return a_0 * n;\n    return a_0 * (r.pow(n) - 1) / (r - 1);\n  }\n\
    \n} // namespace luz\n\n#line 22 \"test/atcoder/abc212_h.test.cpp\"\n#include\
    \ <numeric>\n#line 24 \"test/atcoder/abc212_h.test.cpp\"\n\nnamespace luz {\n\n\
    \  void main_() {\n    usize n = input(), k = input();\n\n    using mint = modint998244353;\n\
    \    std::vector< mint > cs(1 << 16);\n    for ([[maybe_unused]] usize _: rep(0,\
    \ k)) {\n      cs[input()] = 1;\n    }\n\n    mint inv2 = mint(1) / mint(2);\n\
    \    auto zeta = [](mint& lo, mint& hi) {\n      mint x = lo + hi;\n      mint\
    \ y = lo - hi;\n      lo     = x;\n      hi     = y;\n    };\n    auto mobius\
    \ = [inv2](mint& lo, mint& hi) {\n      mint x = lo + hi;\n      mint y = lo -\
    \ hi;\n      lo     = x * inv2;\n      hi     = y * inv2;\n    };\n    fast_walsh_hadamard_transform(cs,\
    \ zeta);\n    for (mint& c: cs) {\n      c = sum_of_geometric_sequence(c, c, n);\n\
    \    }\n    fast_walsh_hadamard_transform(cs, mobius);\n\n    std::cout << (std::accumulate(cs.begin(),\
    \ cs.end(), mint()) -\n                  cs[0])\n                     .val()\n\
    \              << std::endl;\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n\
    }\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc212/tasks/abc212_h\n\
    \n#include \"src/cpp-template/header/input.hpp\"\n#include \"src/cpp-template/header/rep.hpp\"\
    \n#include \"src/cpp-template/header/size-alias.hpp\"\n#include \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n#include \"src/math/modular-arithmetic/static-modint.hpp\"\n\n// TODO: replace\
    \ #11\nnamespace luz {\n\n  template < typename T >\n  T sum_of_geometric_sequence(const\
    \ T& a_0, const T& r,\n                              const usize& n) {\n    if\
    \ (r == T(1)) return a_0 * n;\n    return a_0 * (r.pow(n) - 1) / (r - 1);\n  }\n\
    \n} // namespace luz\n\n#include <iostream>\n#include <numeric>\n#include <vector>\n\
    \nnamespace luz {\n\n  void main_() {\n    usize n = input(), k = input();\n\n\
    \    using mint = modint998244353;\n    std::vector< mint > cs(1 << 16);\n   \
    \ for ([[maybe_unused]] usize _: rep(0, k)) {\n      cs[input()] = 1;\n    }\n\
    \n    mint inv2 = mint(1) / mint(2);\n    auto zeta = [](mint& lo, mint& hi) {\n\
    \      mint x = lo + hi;\n      mint y = lo - hi;\n      lo     = x;\n      hi\
    \     = y;\n    };\n    auto mobius = [inv2](mint& lo, mint& hi) {\n      mint\
    \ x = lo + hi;\n      mint y = lo - hi;\n      lo     = x * inv2;\n      hi  \
    \   = y * inv2;\n    };\n    fast_walsh_hadamard_transform(cs, zeta);\n    for\
    \ (mint& c: cs) {\n      c = sum_of_geometric_sequence(c, c, n);\n    }\n    fast_walsh_hadamard_transform(cs,\
    \ mobius);\n\n    std::cout << (std::accumulate(cs.begin(), cs.end(), mint())\
    \ -\n                  cs[0])\n                     .val()\n              << std::endl;\n\
    \  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  dependsOn:
  - src/cpp-template/header/input.hpp
  - src/cpp-template/header/int-alias.hpp
  - src/cpp-template/header/rep.hpp
  - src/cpp-template/header/size-alias.hpp
  - src/math/convolution/fast-walsh-hadamard-transform.hpp
  - src/math/modular-arithmetic/static-modint.hpp
  isVerificationFile: true
  path: test/atcoder/abc212_h.test.cpp
  requiredBy: []
  timestamp: '2023-07-30 00:54:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc212_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc212_h.test.cpp
- /verify/test/atcoder/abc212_h.test.cpp.html
title: test/atcoder/abc212_h.test.cpp
---
