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
    path: src/math/convolution/bitwise-xor-convolution.hpp
    title: src/math/convolution/bitwise-xor-convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/library-checker/bitwise_xor_convolution.test.cpp\"\n\
    // verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_xor_convolution\n\
    \n#line 2 \"src/math/modular-arithmetic/static-modint.hpp\"\n\n#line 2 \"src/cpp-template/header/type-alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nnamespace luz {\n\n  using isize\
    \ = std::ptrdiff_t;\n  using usize = std::size_t;\n\n  using i32 = std::int32_t;\n\
    \  using i64 = std::int64_t;\n  using u32 = std::uint32_t;\n  using u64 = std::uint64_t;\n\
    \  \n} // namespace luz\n#line 4 \"src/math/modular-arithmetic/static-modint.hpp\"\
    \n\n#include <cassert>\n\nnamespace luz {\n\n  template< u32 mod >\n  class StaticPrimeModInt\
    \ {\n    using mint = StaticPrimeModInt;\n    u32 v_;\n\n   public:\n     StaticPrimeModInt():\
    \ v_(0) {}\n\n     template< typename T >\n     StaticPrimeModInt(T v) {\n   \
    \    i64 x = (i64)(v % (i64)mod);\n       if (x < 0) x += mod;\n       v_ = (u32)x;\n\
    \     }\n\n     u32 val() const { return v_; }\n\n     mint &operator+=(const\
    \ mint &rhs) {\n       v_ += rhs.v_;\n       if (v_ >= mod) v_ -= mod;\n     \
    \  return *this;\n     }\n     mint &operator-=(const mint &rhs) {\n       v_\
    \ += mod - rhs.v_;\n       if (v_ >= mod) v_ -= mod;\n       return *this;\n \
    \    }\n     mint &operator*=(const mint &rhs) {\n       v_ = (u32)(u64(1) * v_\
    \ * rhs.v_ % mod);\n       return *this;\n     }\n     mint &operator/=(const\
    \ mint &rhs) {\n       *this *= rhs.inverse();\n       return *this;\n     }\n\
    \n     mint operator+() const { return *this; }\n     mint operator-() const {\
    \ return mint() - *this; }\n\n     friend mint operator+(const mint &lhs, const\
    \ mint &rhs) {\n       return mint(lhs) += rhs;\n     }\n     friend mint operator-(const\
    \ mint &lhs, const mint &rhs) {\n       return mint(lhs) -= rhs;\n     }\n   \
    \  friend mint operator*(const mint &lhs, const mint &rhs) {\n       return mint(lhs)\
    \ *= rhs;\n     }\n     friend mint operator/(const mint &lhs, const mint &rhs)\
    \ {\n       return mint(lhs) /= rhs;\n     }\n\n     friend bool operator==(const\
    \ mint &lhs, const mint &rhs) {\n       return lhs.v_ == rhs.v_;\n     }\n   \
    \  friend bool operator!=(const mint &lhs, const mint &rhs) {\n       return lhs.v_\
    \ != rhs.v_;\n     }\n\n     mint pow(i64 n) const {\n       assert(0 <= n);\n\
    \       mint x = *this, r = 1;\n       while (n) {\n         if (n & 1) r *= x;\n\
    \         x *= x;\n         n >>= 1;\n       }\n       return r;\n     }\n\n \
    \    mint inverse() const {\n       assert(v_ != 0);\n       return pow(mod -\
    \ 2);\n     }\n\n  };\n\n  using modint998244353  = StaticPrimeModInt< 998244353\
    \ >;\n  using modint1000000007 = StaticPrimeModInt< 1000000007 >;\n\n} // namespace\
    \ luz\n#line 2 \"src/math/convolution/bitwise-xor-convolution.hpp\"\n\n#line 2\
    \ \"src/cpp-template/header/rep.hpp\"\n\n#line 4 \"src/cpp-template/header/rep.hpp\"\
    \n\n#include <algorithm>\n\nnamespace luz {\n\n  struct rep {\n    struct itr\
    \ {\n      usize i;\n      constexpr itr(const usize i) noexcept : i(i) {}\n \
    \     void operator++() noexcept { ++i; }\n      constexpr usize operator*() const\
    \ noexcept { return i; }\n      constexpr bool operator!=(const itr x) const noexcept\
    \ { return i != x.i; }\n    };\n    const itr f, l;\n    constexpr rep(const usize\
    \ f, const usize l) noexcept\n      : f(std::min(f, l)), l(l) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n  struct rrep {\n    struct itr {\n      usize i;\n \
    \     constexpr itr(const usize i) noexcept : i(i) {}\n      void operator++()\
    \ noexcept { --i; }\n      constexpr usize operator*() const noexcept { return\
    \ i; }\n      constexpr bool operator!=(const itr x) const noexcept { return i\
    \ != x.i; }\n    };\n    const itr f, l;\n    constexpr rrep(const usize f, const\
    \ usize l) noexcept\n      : f(l - 1), l(std::min(f, l) - 1) {}\n    constexpr\
    \ auto begin() const noexcept { return f; }\n    constexpr auto end() const noexcept\
    \ { return l; }\n  };\n\n} // namespace luz\n#line 2 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\
    \n\n#line 5 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n\n#line\
    \ 7 \"src/math/convolution/fast-walsh-hadamard-transform.hpp\"\n#include <vector>\n\
    \nnamespace luz::impl {\n\n  template< typename T, typename F >\n  void impl_fwht(std::vector<\
    \ T > &f, F op) {\n    const usize n = f.size();\n    assert((n & (n - 1)) ==\
    \ 0);\n    usize i = 1;\n    while (i < n) {\n      usize j = 0;\n      while\
    \ (j < n) {\n        for (usize k: rep(0, i)) {\n          op(f[j + k], f[j +\
    \ k + i]);\n        }\n        j += i << 1;\n      }\n      i <<= 1;\n    }\n\
    \  }\n} // namespace luz::impl\n\nnamespace luz {\n\n  template< typename T, typename\
    \ F >\n  void fast_walsh_hadamard_transform(std::vector< T > &f, F op) {\n   \
    \ impl::impl_fwht(f, op);\n  }\n\n} // namespace luz\n#line 6 \"src/math/convolution/bitwise-xor-convolution.hpp\"\
    \n\n#line 9 \"src/math/convolution/bitwise-xor-convolution.hpp\"\n\nnamespace\
    \ luz {\n\n  template< typename T >\n  std::vector< T > bitwise_xor_convolution(std::vector<\
    \ T > f, std::vector< T > g) {\n    assert(f.size() == g.size());\n\n    T inv2\
    \ = T(1) / T(2);\n    auto zeta = [](T& lo, T& hi) {\n      T x = lo + hi;\n \
    \     T y = lo - hi;\n      lo = x;\n      hi = y;\n    };\n    auto mobius =\
    \ [inv2](T& lo, T& hi) {\n      T x = lo + hi;\n      T y = lo - hi;\n      lo\
    \ = x * inv2;\n      hi = y * inv2;\n    };\n\n    fast_walsh_hadamard_transform(f,\
    \ zeta);\n    fast_walsh_hadamard_transform(g, zeta);\n    for (usize i: rep(0,\
    \ f.size())) {\n      f[i] *= g[i];\n    }\n    fast_walsh_hadamard_transform(f,\
    \ mobius);\n    return f;\n  }\n\n} // namespace luz\n#line 5 \"test/library-checker/bitwise_xor_convolution.test.cpp\"\
    \n\n#line 7 \"test/library-checker/bitwise_xor_convolution.test.cpp\"\n#include\
    \ <iostream>\n\nnamespace luz {\n\n  void main_() {\n    usize n;\n    std::cin\
    \ >> n;\n\n    using mint = modint998244353;\n    std::vector< mint > as(1 <<\
    \ n);\n    for (mint &a: as) {\n      i32 v;\n      std::cin >> v;\n      a =\
    \ mint(v);\n    }\n\n    std::vector< mint > bs(1 << n);\n    for (mint &b: bs)\
    \ {\n      i32 v;\n      std::cin >> v;\n      b = mint(v);\n    }\n\n    auto\
    \ cs = bitwise_xor_convolution(as, bs);\n    for (usize i: rep(0, 1 << n)) {\n\
    \      std::cout << cs[i].val() << (i + 1 == (usize(1) << n) ? \"\\n\" : \" \"\
    );\n    }\n\n  }\n\n} // namespace luz\n\nint main() {\n  luz::main_();\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/bitwise_xor_convolution\n\
    \n#include \"src/math/modular-arithmetic/static-modint.hpp\"\n#include \"src/math/convolution/bitwise-xor-convolution.hpp\"\
    \n\n#include <vector>\n#include <iostream>\n\nnamespace luz {\n\n  void main_()\
    \ {\n    usize n;\n    std::cin >> n;\n\n    using mint = modint998244353;\n \
    \   std::vector< mint > as(1 << n);\n    for (mint &a: as) {\n      i32 v;\n \
    \     std::cin >> v;\n      a = mint(v);\n    }\n\n    std::vector< mint > bs(1\
    \ << n);\n    for (mint &b: bs) {\n      i32 v;\n      std::cin >> v;\n      b\
    \ = mint(v);\n    }\n\n    auto cs = bitwise_xor_convolution(as, bs);\n    for\
    \ (usize i: rep(0, 1 << n)) {\n      std::cout << cs[i].val() << (i + 1 == (usize(1)\
    \ << n) ? \"\\n\" : \" \");\n    }\n\n  }\n\n} // namespace luz\n\nint main()\
    \ {\n  luz::main_();\n}\n"
  dependsOn:
  - src/math/modular-arithmetic/static-modint.hpp
  - src/cpp-template/header/type-alias.hpp
  - src/math/convolution/bitwise-xor-convolution.hpp
  - src/cpp-template/header/rep.hpp
  - src/math/convolution/fast-walsh-hadamard-transform.hpp
  isVerificationFile: true
  path: test/library-checker/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-08-22 07:19:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/bitwise_xor_convolution.test.cpp
- /verify/test/library-checker/bitwise_xor_convolution.test.cpp.html
title: test/library-checker/bitwise_xor_convolution.test.cpp
---
